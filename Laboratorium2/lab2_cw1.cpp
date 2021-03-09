#include <iostream>

const float pi=3.14159265358;

class Kolo{
    float r;
public:
    Kolo(){
        this->r=3;
        std::cout<<"Domyslny konstruktor. r=3"<<std::endl;
    }
    Kolo(float _r):r(_r){
        std::cout<<"Konstruktor z parametrem. r="<<this->r<<std::endl;
    }
    void setr(int _r){
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

class Prostokat{
    float a,b;
public:
    Prostokat(){
        this->a=3;
        this->b=0;
        std::cout<<"Domyslny konstruktor. a=3, b=0"<<std::endl;
    }
    Prostokat(float _a, float _b):a(_a),b(_b){
        std::cout<<"Konstruktor z parametrem. a="<<this->a<<" b="<<this->b<<std::endl;
    }
    void seta(int _a){
        this->a=_a;
    }
    void setb(int _b){
        this->b=_b;
    }
    float geta() const{
        return a;
    }
    float getb() const{
        return b;
    }
    float area() const{
        return a*b;
    }

    float perimeter() const{
        return (a==0 || b==0) ? 0 : 2*(a+b);
    }

    ~Prostokat(){
        std::cout<<"Destruktor"<<std::endl;
    }
};

int main(){
    Kolo kolo1;
    std::cout<<"Promien kolo1 ="<<kolo1.getr()<<std::endl;
    Kolo kolo2(5);
    std::cout<<"Promien kolo2 ="<<kolo2.getr()<<std::endl;
    kolo1.setr(2);
    std::cout<<"Promien kolo1 ="<<kolo1.getr()<<std::endl;
    std::cout<<"Pole kolo1 ="<<kolo1.area()<<std::endl;
    std::cout<<"Obwod kolo1 ="<<kolo1.perimeter()<<std::endl;
    std::cout<<"Pole kolo2 ="<<kolo2.area()<<std::endl;
    std::cout<<"Obwod kolo2 ="<<kolo2.perimeter()<<std::endl;
    Prostokat p1;
    std::cout<<"Pole p1 ="<<p1.area()<<std::endl;
    std::cout<<"Obwod p1 ="<<p1.perimeter()<<std::endl;
    p1.setb(3);
    std::cout<<"Pole p1 ="<<p1.area()<<std::endl;
    std::cout<<"Obwod p1 ="<<p1.perimeter()<<std::endl;
}