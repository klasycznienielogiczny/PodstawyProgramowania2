#include "funkcje.cpp"

int main()
{
	std::vector<std::string> Nazwa, Numer;
	std::vector<int> Id;
	size_t id_p, dec=1;
	
	while(dec>0){
		dec = prompt1();
		if(dec==1){
			wyswietl_instrukcje();
		}
		else if(dec==2)
			return 0;
		else{
			dec=0;
			read_from_csv(Nazwa, Numer, Id);
			
			const std::string link = "https://ckan2.multimediagdansk.pl/delays?stopId=";
			std::string code=find_stop_id(Nazwa, Numer, Id, id_p);
			const std::string url(link+code);
			CURL* curl = curl_easy_init();

			// Set remote URL.
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

			// Don't bother trying IPv6, which would increase DNS resolution time.
			curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

			// Don't wait forever, time out after 10 seconds.
			curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

			// Follow HTTP redirects if necessary.
			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

			// Response information.
			long httpCode(0);
			std::unique_ptr<std::string> httpData(new std::string());

			// Hook up data handling function.
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

			// Hook up data container (will be passed as the last parameter to the
			// callback handling function).  Can be any pointer type, since it will
			// internally be passed as a void pointer.
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

			// Run our HTTP GET command, capture the HTTP response code, and clean up.
			curl_easy_perform(curl);
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
			curl_easy_cleanup(curl);

			if (httpCode == 200){
				//std::cout << "Got successful response from " << url << std::endl;
				// Response looks good - done using Curl now.  Try to parse the results
				// and print them out.
				Json::Value jsonData;
				Json::Reader jsonReader;

				if (jsonReader.parse(*httpData.get(), jsonData)){
					/*std::cout << "Successfully parsed JSON data" << std::endl;
					std::cout << "\nJSON data received:" << std::endl;
					std::cout << jsonData.toStyledString() << std::endl;
					std::cout << std::endl;*/
					odswiez_tablice(Nazwa, Numer, id_p, jsonData);
				}
				else{
					system("clear");
					std::cout << "Nie udało się sparsować danych z HTTP do JSON" << std::endl;
					std::cout << "Dane HTTP:\n" << *httpData.get() << std::endl;
					return 1;
				}
			}
			else{
				std::cout << "Nie udało się pobrać danych z adresu " << url << " - kończenie pracy" << std::endl;
				return 1;
			}
		}
	}
    return 0;
}
