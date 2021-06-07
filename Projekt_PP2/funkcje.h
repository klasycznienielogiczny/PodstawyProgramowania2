#include <iostream>
#include <vector>
#include <cstring>

namespace{
	int kbhit(void);
	std::size_t callback(const char* in,std::size_t size,std::size_t num,std::string* out);
	void read_from_csv(std::vector<std::string> &Nazwa, std::vector<std::string> &Numer,std::vector<int> &Id);
	void znajdz_wszystkie(std::vector<size_t> &pozycje, std::vector<std::string> przystanki, std::string to_find);
	std::string find_stop_id(std::vector<std::string> przystanki, std::vector<std::string> numery, std::vector<int> id, size_t &id_p);
	void rysuj_linie();
	void odswiez_tablice(std::vector<std::string> przystanki, std::vector<std::string> numery, size_t &id_p, Json::Value jsonData);
	void zaznacz(std::string text);
	int prompt1();
	void wyswietl_instrukcje();
}
