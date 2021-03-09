#include <iostream>

const float pi=3.14159265358;

class Kolo{
private:
    mutable float r;
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

    ~Kolo(){
        std::cout<<"Destruktor kola"<<std::endl;
    }
};

class Prostokat{
private:
    float a,b;
public:
    Prostokat(){
        this->a=3;
        this->b=0;
        std::cout<<"Prostokat. Domyslny konstruktor. a=3, b=0"<<std::endl;
    }
    Prostokat(float _a, float _b):a(_a),b(_b){
        std::cout<<"Prostokat. Konstruktor z parametrami. Tworze prostokat a="<<this->a<<" b="<<this->b<<std::endl;
    }
    Prostokat(float _a):a(_a),b(_a){
        std::cout<<"Prostokat. Konstruktor z parametrem. Tworze kwadrat a="<<this->a<<std::endl;
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
        std::cout<<"Destruktor prostokata"<<std::endl;
    }
};

class Trojkat{
private:
    float a,b,c;
public:
    Trojkat(){
        this->a=3;
        b=3;
        c=3;
        std::cout<<"Trojkat. Domyslny konstruktor. a=b=c=3"<<std::endl;
    }
    Trojkat(float _a){
        this->a=_a;
        b=_a;
        c=_a;
        std::cout<<"Trojkat. Konstruktor z parametrem. a=b=c="<<_a<<std::endl;
    }
    Trojkat(float _a,float _b,float _c){
        this->a=_a;
        b=_b;
        c=_c;
        std::cout<<"Trojkat. Konstruktor z parametrami. a="<<_a<<" b="<<this->b<<" c="<<c<<std::endl;
    }

    ~Trojkat(){
        std::cout<<"Destruktor trojkata"<<std::endl;
    }
};

int main(){

    std::cout<<"Zwykle tworzenie"<<std::endl;
    Kolo kolo;
    Kolo kolo1(5);
    Prostokat prostokat;
    Prostokat prostokat1(5);
    Prostokat prostokat2(5,4);
    Trojkat trojkat;
    Trojkat trojkat1(5);
    Trojkat trojkat2(1,5,8);


    std::cout<<std::endl<<"Tworzenie z new"<<std::endl;
    Kolo *k=new Kolo;
    Kolo *k1=new Kolo(5);
    Prostokat *p = new Prostokat;
    Prostokat *p2=new Prostokat(5);
    Prostokat *p3 = new Prostokat(5,4);
    Trojkat *t= new Trojkat;
    Trojkat *t1 =new Trojkat(5);
    Trojkat *t2=new Trojkat(1,5,8);
    std::cout<<std::endl<<"Usuwanie z delete"<<std::endl;
    delete k;
    delete k1;
    delete t;
    delete t2;
    delete t1;
    delete p;
    delete p2;
    delete p3;
    std::cout<<std::endl<<"Tworzenie tablicy obiektow"<<std::endl;
    Kolo ko[5]={5,8,7};
    Prostokat pr[3]={5,{4,5}};
    Trojkat tr[3]={5,{4,5,8}};

    std::cout<<std::endl<<"Tworzenie z malloc"<<std::endl;
    Kolo *kolo3=(Kolo*)malloc(sizeof(Kolo));
    std::cout<<std::endl<<"Usuwanie z uzyciem free()"<<std::endl;
    free(kolo3);
    std::cout<<std::endl<<"Usuwanie sie tablicy obiektow"<<std::endl;
    std::cout<<std::endl<<"Zwykle usuwanie sie"<<std::endl;
}