#include <iostream>

class String{
    char *tekst;
    unsigned int rozmiar;
public:
    String() : tekst(new char[0]), rozmiar(0) {}; //A

    String(const char *tekst_){ //B
        if (tekst_ == nullptr)
            throw std::out_of_range("Given text cannot be null!");
        this -> rozmiar = 0;
        while (tekst_[this->rozmiar++] != '\0'){};
        this->tekst = new char[this->rozmiar];
        std::copy(tekst_, tekst_ + rozmiar + 1, tekst);
    };

    String(const String &s){ //D
        this->tekst = new char[s.rozmiar];
        if (this->tekst)
            std::copy(s.tekst, s.tekst + s.rozmiar + 1, tekst);
        else
            throw std::invalid_argument("NULL object");
        this->rozmiar = s.rozmiar;
    }

    String& operator=(const char *NewText){ //F
        if (NewText == nullptr)
            throw std::out_of_range("Given text cannot be null!");
        this -> rozmiar = 0;
        while (NewText[this->rozmiar++] != '\0'){};
        this->tekst = new char[this->rozmiar];
        std::copy(NewText, NewText + rozmiar + 1, tekst);
        return *this;
    }

    unsigned int size() const{ //G
        return this->rozmiar-1;
    }

    char *text() const{ //G
        return this->tekst;
    }

    String & operator=(const String &NewText){ //H
        if (this==&NewText)
            return *this;

        if (NewText.tekst == nullptr)
            throw std::out_of_range("Given text cannot be null!");

        this->tekst = new char[NewText.rozmiar];
        if (this->tekst)
            std::copy(NewText.tekst, NewText.tekst + NewText.rozmiar + 1, tekst);
        else
            throw std::invalid_argument("Fail when creating object");

        this->rozmiar = NewText.rozmiar;
        return *this;
    }

    String& operator+=(const char* text2Append){ //I
        if (text2Append == nullptr)
            throw std::out_of_range("Given text cannot be null!");

        unsigned int size = 0, index = 0;
        while (text2Append[size++] != '\0'){};
        this->rozmiar += size;
        size = 0;
        char *tmptxt = new char[this->rozmiar];
        while(this->tekst[size++] != '\0'){
            tmptxt[size-1] = this->tekst[size-1];
        }
        while(text2Append[index++] != '\0'){
            tmptxt[size++ -1] = text2Append[index-1];
        }
        tmptxt[size-1]='\0';
        delete[] this->tekst;
        this->tekst = tmptxt;
        return *this;
    }

    char* operator+(const char* text2Append){ //J
        if (text2Append == nullptr)
            throw std::out_of_range("Given text cannot be null!");

        unsigned int size = 0, index =0;
        while (text2Append[size++] != '\0'){};
        this->rozmiar += size;
        size = 0;
        char *tmptxt = new char[this->rozmiar];
        while(this->tekst[size++] != '\0'){
            tmptxt[size-1] = this->tekst[size-1];
        }
        while(text2Append[index++] != '\0'){
            tmptxt[size++ -1] = text2Append[index-1];
        }
        tmptxt[size-1]='\0';
        return tmptxt;
    }

    friend std::ostream& operator <<(std::ostream &os, const String &s){
        os << s.text() <<std::endl;
        return os;
    };

    friend std::istream& operator >>(std::istream &in, String &f){
        std::string tmp;
        std::getline(in, tmp);
        unsigned int index = 0;
        while (tmp[index++] != '\0'){};
        f.rozmiar = index;
        index = 0;
        f.tekst = new char[f.rozmiar];
        while(tmp[index++] != '\0'){
            f.tekst[index-1] = tmp[index-1];
        }
        f.tekst[index-1] = '\0';
        return in;
    }

    ~String(){ //C
        delete[] tekst;
    }
    void printtekst(){ //tylko do testów!
        std::cout<<tekst<<std::endl;
    }
};

int main(){
    //String s1(nullptr); //terminate called after throwing an instance of 'std::out_of_range'
    //what():  Given text cannot be null!
    String s1("test. Albo moze cos bardziej skomplikowanego"); // works good
    String s2;
    s2 = s1; //works good
    s1.printtekst(); //awesome
    s2.printtekst(); //better and better
    std::cout<<s1.text()<<std::endl; //still good
    std::cout<<s2.text()<<std::endl; //I cant believe

    String s3,s4,s5("Jakis randomowy tekst");
    std::cout<<s5.text()<<std::endl; //pieknie
    s3=s4=s5;
    std::cout<<s3.text()<<std::endl; //super
    std::cout<<s4.text()<<std::endl; //wspaniale
    std::cout<<s5.text()<<std::endl; //pysznie :3
    s5=s5;
    std::cout<<s5.text()<<std::endl; //rozkosznie

    s5 += "dopisze, dobrze? Prosze";
    std::cout<<s5.text()<<std::endl; //awww. rozpływam się

    std::cout<<s5+"Dziekuje pieknie"<<std::endl; //brakuje mi już słów do wyrażenia zachwytu

    String s6("test cout i cin");
    std::cout<<"Rozmiar "<<s6.size()<<std::endl;
    std::cout<<s6; //rozpłynąłem się

    String s7;
    std::cout<<"Podaj tekst do wprowadzenia do stringa: "<<std::endl;
    std::cin>>s7;
    std::cout<<s7<<"Rozmiar: "<<s7.size(); // <3
    return 0;
}