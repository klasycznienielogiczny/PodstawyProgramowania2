#include <iostream>

const float pi=3.14159265358;

class Kolo{
private:
    mutable float r;
public:
    Kolo(){
        this->r=3;
        std::cout<<"Domyslny konstruktor. r=3"<<std::endl;
    }
    Kolo(float _r){
        r=_r;
        std::cout<<"Konstruktor z parametrem. r="<<this->r<<std::endl;
    }
    void setr(const int &_r){
        this->r=_r;
    }
    float getr() const{
        return r;
    }

    float area() const{
        return pi*r*r;
    }

    float perimeter() const{
        return 2*pi*r;
    }

    ~Kolo(){
        std::cout<<"Destruktor"<<std::endl;
    }
};

int main(){
    const Kolo kolo1(1);
    std::cout<<"Pole kolo1 ="<<kolo1.area()<<std::endl;
    std::cout<<"Obwod kolo1 ="<<kolo1.perimeter()<<std::endl;
    std::cout<<"Promien kolo1 ="<<kolo1.getr()<<std::endl;
    //blad kolo1.setr(5);
    //blad kolo1.r=5;
    Kolo k2;
    std::cout<<"Promien k2 ="<<k2.getr()<<std::endl;
    k2.setr(5);
    std::cout<<"Promien k2 ="<<k2.getr()<<std::endl;
}