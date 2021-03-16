#include <iostream>

class tekst{
    const char *String;
    unsigned int rozmiar;
public:
    tekst() : String(new char[0]),rozmiar(0){
        std::cout<<"Domyslny konstruktor tekst"<<std::endl;
    };

    tekst(const char _tekst[]){
        std::cout<<"Konstruktor na tekst tekst"<<std::endl;

        this -> rozmiar = -1;
        while (_tekst[++this->rozmiar] != '\0'){};

        char *Stringtmp = new char[this->rozmiar];
        for(int i=0; i< this->rozmiar;++i){
            Stringtmp[i]=_tekst[i];
        }
        this->String=Stringtmp;
    }

    tekst(tekst *_tekst){
        std::cout<<"Konstruktor kopiujacy tekst"<<std::endl;

        this -> rozmiar = _tekst->rozmiar;
        char *Stringtmp = new char[this->rozmiar];
        for(int i=0; i< this->rozmiar;++i){
            Stringtmp[i]=_tekst->String[i];
        }
        this->String=Stringtmp;
    }

    unsigned int getSize(){
        return this->rozmiar;
    }

    void setNewText(const char *newText){
        delete[] this->String;

        this -> rozmiar = -1;
        while (newText[++this->rozmiar] != '\0'){};

        char *Stringtmp = new char[this->rozmiar];
        for(int i=0; i< this->rozmiar;++i){
            Stringtmp[i]=newText[i];
        }
        this->String=Stringtmp;
    }

    const char *getString(){
        return this->String;
    }

    ~tekst(){
        std::cout<<"Domyslny destruktor tekst"<<std::endl;
        delete[] String;
    };
};

class Osoba{
    tekst Imie;
    tekst Nazwisko;
public:
    Osoba(){
        std::cout<<"Domyslny konstruktor Osoba"<<std::endl;
    }
    /*
    Osoba(tekst _imie, tekst _nazwisko){
        std::cout<<"Konstruktor Osoba w ciele"<<std::endl;
        this->Imie=_imie;
        this->Nazwisko=_nazwisko;
    }
    */

    Osoba(tekst _imie, tekst _nazwisko): Imie(_imie), Nazwisko(_nazwisko){
        std::cout<<"Konstruktor Osoba z lista inicjalizacyjna"<<std::endl;
    }

    ~Osoba(){
        std::cout<<"Domyslny destruktor Osoba"<<std::endl;
    }
};

int main(){
    std::cout<<"Tworze osobe: "<<std::endl;
    Osoba os = Osoba();

    std::cout<<"Tworze osobe z imieniem i nazwiskiem: "<<std::endl;
    Osoba os2 = Osoba("Maciej","Rydel");
}

/* Output dla konstruktora z ciałem:
Tworze osobe:
Domyslny konstruktor tekst
Domyslny konstruktor tekst
Domyslny konstruktor Osoba
Tworze osobe z imieniem i nazwiskiem:
Konstruktor na tekst tekst
Konstruktor na tekst tekst
Domyslny konstruktor tekst
Domyslny konstruktor tekst
Konstruktor Osoba w ciele
Domyslny destruktor tekst
Domyslny destruktor tekst
Domyslny destruktor Osoba
Domyslny destruktor tekst
Domyslny destruktor tekst
Domyslny destruktor Osoba
Domyslny destruktor tekst
Domyslny destruktor tekst
 */

/* Output dla konstruktora na liście inicjalizacyjnej
Tworze osobe:
Domyslny konstruktor tekst
Domyslny konstruktor tekst
Domyslny konstruktor Osoba
Tworze osobe z imieniem i nazwiskiem:
Konstruktor na tekst tekst
Konstruktor na tekst tekst
Konstruktor Osoba z lista inicjalizacyjna
Domyslny destruktor tekst
Domyslny destruktor tekst
Domyslny destruktor Osoba
Domyslny destruktor tekst
Domyslny destruktor tekst
Domyslny destruktor Osoba
Domyslny destruktor tekst
Domyslny destruktor tekst
 */