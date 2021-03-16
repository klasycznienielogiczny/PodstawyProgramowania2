#include <iostream>

class CzlowiekZnanyZWidzenia{
protected:
    std::string cechaCharakterystyczna;
public:
    CzlowiekZnanyZWidzenia(){};
    CzlowiekZnanyZWidzenia(std::string cecha){
        this->cechaCharakterystyczna=cecha;
    }
    ~CzlowiekZnanyZWidzenia(){}

    void setCeche(std::string _cecha){
        this->cechaCharakterystyczna = _cecha;
    }

    std::string getCeche(){
        return this->cechaCharakterystyczna;
    }
};

class CzlowiekZnanyZImienia : public CzlowiekZnanyZWidzenia{
protected:
    std::string imie;
public:
    CzlowiekZnanyZImienia(){};
    CzlowiekZnanyZImienia(std::string _imie){
        this->imie=_imie;
    }
    CzlowiekZnanyZImienia(std::string _imie, std::string _cecha) : CzlowiekZnanyZWidzenia(_cecha){
        this->imie=_imie;
    }
    ~CzlowiekZnanyZImienia(){};

    void setImie(std::string _imie){
        this->imie = _imie;
    }

    void setCeche(std::string _cecha){
        CzlowiekZnanyZWidzenia::setCeche(_cecha);
    }

    std::string getCeche(){
        return CzlowiekZnanyZWidzenia::getCeche();
        //CzlowiekZnanyZWidzenia::getCeche();
    }

    std::string getImie(){
        return this->imie;
    }

};

class CzlowiekZnanyZInternetu{
protected:
    std::string gdziePoznany;
    std::string czymZwrocilMojaUwage;
public:
    CzlowiekZnanyZInternetu(){};
    CzlowiekZnanyZInternetu(std::string gdzie, std::string czym) : gdziePoznany(gdzie), czymZwrocilMojaUwage(czym) {};
    ~CzlowiekZnanyZInternetu(){};

    void setGdzie(std::string _gdzie){
        this->gdziePoznany = _gdzie;
    }

    void setCzym(std::string _czym){
        this->gdziePoznany = _czym;
    }

    std::string getGdzie(){
        return this->gdziePoznany;
    }

    std::string getCzym(){
        return this->czymZwrocilMojaUwage;
    }
};

class Zwierze{
protected:
    std::string gatunek;
    std::string imie;
public:
    Zwierze(){};
    Zwierze(std::string _gat, std::string _imie){
        this->imie=_imie;
        this->gatunek=_gat;
    }
    ~Zwierze(){};

    void setGatunek(std::string _gat){
        this->gatunek=_gat;
    }

    void setImie(std::string _imie){
        this->imie=_imie;
    }

    std::string getGatunek(){
        return this->gatunek;
    }

    std::string getImie(){
        return this->imie;
    }

};

class DobrzeZnanyKolega : public CzlowiekZnanyZImienia, public CzlowiekZnanyZInternetu{
protected:
    std::string skadGoZnam;
    Zwierze zwierzeDomowe;
public:
    DobrzeZnanyKolega(){};
    DobrzeZnanyKolega(std::string _skad, Zwierze zwierz, std::string _imie, std::string _gdzie, std::string _czym, std::string _cecha) : skadGoZnam(_skad), zwierzeDomowe(zwierz), CzlowiekZnanyZImienia(_imie,_cecha), CzlowiekZnanyZInternetu(_gdzie,_czym){};
    ~DobrzeZnanyKolega(){};

    static std::string fstatyczna(){
        return "Metoda statyczna";
    }

    void setSkad(std::string _skad){
        this->skadGoZnam = _skad;
    }

    void setZwierze(Zwierze zwierz){
        this->zwierzeDomowe=zwierz;
    }

    void setImie(std::string _imie){
        CzlowiekZnanyZImienia::setImie(_imie);
    }

    void setGdzie(std::string _gdzie){
        CzlowiekZnanyZInternetu::setGdzie(_gdzie);
    }

    void setCzym(std::string _czym){
        CzlowiekZnanyZInternetu::setCzym(_czym);
    }

    std::string getSkad(){
        return this->skadGoZnam;
    }

    Zwierze getZwierze(){
        return this->zwierzeDomowe;
    }

    std::string getImie(){
        return CzlowiekZnanyZImienia::getImie();
        //CzlowiekZnanyZImienia::getImie();
    }

    std::string getGdzie(){
        //CzlowiekZnanyZInternetu::getGdzie();
        return CzlowiekZnanyZInternetu::getGdzie();
    }

    std::string getCzym(){
        return CzlowiekZnanyZInternetu::getCzym();
        //CzlowiekZnanyZInternetu::getCzym();
    }
    std::string getCeche(){
        return CzlowiekZnanyZWidzenia::getCeche();
        //CzlowiekZnanyZInternetu::getCzym();
    }
};

int main(){
    CzlowiekZnanyZWidzenia czzw = CzlowiekZnanyZWidzenia("Oczy");
    CzlowiekZnanyZImienia czzi = CzlowiekZnanyZImienia("Maciek", "Wlosy");
    CzlowiekZnanyZInternetu czzin = CzlowiekZnanyZInternetu("6obcy","charakterem");
    Zwierze zwierzak = Zwierze("pies","Fafik");
    DobrzeZnanyKolega dzk = DobrzeZnanyKolega("omegle",zwierzak,"Paweu","AGH","aparycja","pewnosc siebie");

    std::cout<<czzw.getCeche()<<std::endl;
    std::cout<<dzk.getCzym()<<std::endl;
    std::cout<<dzk.getCeche()<<std::endl;
    std::cout<<dzk.getImie()<<std::endl;
    dzk.setImie("Jednak Rafau");
    std::cout<<dzk.getImie()<<std::endl;
    std::cout<<DobrzeZnanyKolega::fstatyczna()<<std::endl;
}