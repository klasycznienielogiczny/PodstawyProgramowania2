#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include <memory>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include "csv.h"
#include <algorithm>
#include <ctime>
#include <cctype>
#include <unistd.h>
#include <thread>
#include <sys/ioctl.h> // For FIONREAD
#include <termios.h>
#include <stdbool.h>


#include "funkcje.h"
#include "makra.h"

namespace
{
	int kbhit(void) {
		static bool initflag = false;
		static const int STDIN = 0;

		if (!initflag) {
			// Use termios to turn off line buffering
			struct termios term;
			tcgetattr(STDIN, &term);
			term.c_lflag &= ~ICANON;
			tcsetattr(STDIN, TCSANOW, &term);
			setbuf(stdin, NULL);
			initflag = true;
		}

		int nbbytes;
		ioctl(STDIN, FIONREAD, &nbbytes);  // 0 is STDIN
		return nbbytes;
	}
	
    std::size_t callback(const char* in,std::size_t size,std::size_t num,std::string* out){
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }


	void read_from_csv(std::vector<std::string> &Nazwa, std::vector<std::string> &Numer,std::vector<int> &Id){
		io::CSVReader<3> przyst("przystanki.csv");
		przyst.read_header(io::ignore_extra_column, "Nazwa", "Numer", "Id");
		std::string nazwa, numer;
		int id;
		while(przyst.read_row(nazwa, numer, id)){
			Nazwa.push_back(nazwa);
			Numer.push_back(numer);
			Id.push_back(id);
		}
	}
	
	void znajdz_wszystkie(std::vector<size_t> &pozycje, std::vector<std::string> przystanki, std::string to_find){
		size_t poz = 0;
		for(std::string nazwa : przystanki){
			size_t found = nazwa.find(to_find);
				if(found != std::string::npos)
					pozycje.push_back(poz);
			++poz;
		}
	}

	std::string find_stop_id(std::vector<std::string> przystanki, std::vector<std::string> numery, std::vector<int> id, size_t &id_p){
		std::vector<size_t> znalezione;
		while(znalezione.size() == 0){
			system("clear");
			std::cout<<"Wpisz co najmniej 3 znaki i wybierz przystanek"<<std::endl;
			std::string przystanek;
			do{
				std::cin>>przystanek;
			}while(przystanek.length() <3);
			
			system("clear");
			przystanek[0] = toupper(przystanek[0]);
			znajdz_wszystkie(znalezione, przystanki, przystanek);
			if(znalezione.size() == 0){
				std::cout<<RED<<"Nie udało się znaleźć przystanku spełniającego kryteria. Spróbuj ponownie"<<RESET<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
		}
		system("clear");
		std::cout<<"ID\t"<<"Nazwa przystanku"<<std::endl;
		for(size_t index : znalezione){
			std::cout<<index<<"\t"<<przystanki[index] <<" "<< numery[index]<<std::endl;
		}
		std::cout<<std::endl<<"Podaj ID przystanku"<<std::endl;
		std::cin>>id_p;	
		znalezione.clear();
	return std::to_string(id[id_p]);
	}
	
	//std::string znajdz_przystanek_po_id
	
	void rysuj_linie(){
		for(int i=0; i<55; ++i)
			std::cout<<"-";
	}
	
	void odswiez_tablice(std::vector<std::string> przystanki, std::vector<std::string> numery, size_t &id_p, Json::Value jsonData){
		system("clear");
        time_t teraz = time(0);
        char* aktualna = ctime(&teraz);
        std::cout<<"\t\t\t"<<przystanki[id_p]<<" "<< numery[id_p]<<std::endl;
        std::cout<<"Linia nr|"<<std::setw(25)<<"Kierunek"<<"\t"<<std::setw(8)<<"|"<<"Odjazd"<<std::endl;
        rysuj_linie();
		std::cout<<std::endl;
		if(jsonData["delay"].size() ==0)
			std::cout<<WHITE<<"\t\t\tBRAK KURSÓW"<<RESET<<std::endl;
		else{
			for (unsigned int i =0; i<jsonData["delay"].size(); ++i){
				if(jsonData["delay"][i]["delayInSeconds"] > 0)
					std::cout << RED <<std::setw(8)<< jsonData["delay"][i]["routeId"].asString()<<"|"<<std::setw(25)<< jsonData["delay"][i]["headsign"].asString()<<"\t"<<std::setw(8)<<"|"<< jsonData["delay"][i]["estimatedTime"].asString()<< RESET << std::endl;
				else
					std::cout << BOLDGREEN << std::setw(8)<< jsonData["delay"][i]["routeId"].asString()<<"|"<<std::setw(25)<< jsonData["delay"][i]["headsign"].asString()<<"\t"<<std::setw(8)<<"|"<< jsonData["delay"][i]["estimatedTime"].asString()<< RESET << std::endl;
			}
		}
		rysuj_linie();
		std::cout<<std::endl<<"Stan na: "<<aktualna<<std::endl;
		int c = getchar();
	}
	
	void zaznacz(std::string text){
		std::cout << BACKG <<text<<RESET<<std::endl;
	}
	
	
	int prompt1(){
		size_t wskazane = 0;
		int c,c1,c2;
		std::string text[]={"1. Sprawdź rozkład na wybranym przystanku", "2. Instrukcja korzystania", "3. Wyjdz z programu"};
		while(c!=10 && c1!=10 && c2!=10){
			system("clear");
			std::cout<<"System Informacji Pasażerskiej Gdańsk"<<std::endl;
			std::cout<<"Co chcesz zrobić?"<<std::endl;
			for(size_t wiersz=0; wiersz<3; ++wiersz){
				if(wiersz==wskazane)
					zaznacz(text[wiersz]);
				else
					std::cout<<text[wiersz]<<std::endl;
			}
			while (!kbhit()){}
			if((c=getchar())==10)
				return wskazane;
			c1=getchar();
			c2 = getchar();
			switch(c2){
				case KEY_UP:
					wskazane >= 1 ? wskazane-- : wskazane;
					break;
				case KEY_DOWN:
					wskazane < 3 ? wskazane++ : wskazane;
					break;
				default:
					break;
			}
		}
		return wskazane;
	}
	
	void wyswietl_instrukcje(){
		system("clear");
		std::cout<<WHITE<<"Instrukcja korzystania:"<<std::endl;
		std::cout<<"Wybierz opcję \"Sprawdź rozkład na wybranym przystanku\", nastepnie wpisz conajmniej 3 znaki z nazwy przystanku (wielkość liter nie ma znaczenia)."<<std::endl;
		std::cout<<"Wybierz interesujący Cię przystanek z listy i zatwierdź klawiszem enter."<<std::endl;
		std::cout<<"Miłego korzystania!"<<std::endl;
		std::cout<<RESET<<std::endl;
		std::cout<<std::endl<<std::endl<<"Aby wrocic wcisnij dowolny klawisz"<<std::endl;
		int c = getchar();
	}
}
