#include <iostream>

class tekst{
    const char *String;
    unsigned int rozmiar;
public:
    tekst() : String(new char[0]),rozmiar(0){};

    tekst(const char _tekst[]){
        this -> rozmiar = -1;
        while (_tekst[++this->rozmiar] != '\0'){};

        char *Stringtmp = new char[this->rozmiar];
        for(int i=0; i< this->rozmiar;++i){
            Stringtmp[i]=_tekst[i];
        }
        this->String=Stringtmp;
    }

    tekst(tekst *_tekst){
        this -> rozmiar = _tekst->rozmiar;
        char *Stringtmp = new char[this->rozmiar];
        for(int i=0; i< this->rozmiar;++i){
            Stringtmp[i]=_tekst->String[i];
        }
        this->String=Stringtmp;
    }

    unsigned int getSize() const{
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
        delete[] String;
    };
};

int main(){
    //char *xdd = "siedem";
    tekst xd = tekst("blablablabla");
    tekst xd2=tekst(xd);
    std::cout<<xd2.getSize()<<std::endl;
    std::cout<<xd2.getString()<<std::endl;
    xd2.setNewText("krotki");
    std::cout<<xd2.getSize()<<std::endl;
    std::cout<<xd2.getString()<<std::endl;
}