#include <iostream>
class A{
private:
    static int ogolem;
public:
    A(){
        ++ogolem;
        std::cout<<"Utworzono obiekt A. Ogolnie:"<<ogolem<<std::endl;
    }
    ~A(){
        std::cout<<"Usuwam obiekt A. Utworzonych:"<<ogolem<<std::endl;
    };
};

class B{
private:
    static int obecnie;
public:
    B(){
        ++obecnie;
        std::cout<<"Utworzono obiekt B. Obecnie istnieje:"<<obecnie<<std::endl;
    }
    ~B(){
        --obecnie;
        std::cout<<"Usuwam obiekt B. Pozostalo:"<<obecnie<<std::endl;
    };
};



class Kolo{
private:
    mutable float r;
    static constexpr double pi=3.14159265358;
public:
    Kolo(){
        this->r=3;
        std::cout<<"Kolo. Domyslny konstruktor. r=3"<<std::endl;
    }
    Kolo(float _r){
        r=_r;
        std::cout<<"Kolo. Konstruktor z parametrem. r="<<this->r<<std::endl;
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

    static double zwrocPi(){
        return pi;
    }

    ~Kolo(){
        std::cout<<"Destruktor kola"<<std::endl;
    }
};

int A::ogolem=0;
int B::obecnie=0;

int main(){
    A obiektyA[10];
    A *p=new A[10];
    delete[] p;

    B obiektyB[10];
    B *b=new B[10];
    delete[] b;

    std::cout<<"Pi jest rowne "<<Kolo::zwrocPi()<<std::endl;
    return 0;
}