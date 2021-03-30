#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Object{
public:
    Object(){};
    virtual void whatAmI() = 0;
    virtual std::string toString() = 0;
    virtual Object* clone() = 0;
    virtual ~Object(){};
};

class StringObject : public Object{
private:
    char* value;
    size_t size;
public:
    StringObject(){
        this->size = (size_t) sizeof("I am empty!")/sizeof(char);
        this->value = new char[this->size];
        this->value = (char*)"I am empty!";
    }

    StringObject(const char _tekst[]){
        this->size = 0;
        while (_tekst[this->size++] != '\0'){};

        char *tmp = new char[this->size];
        for(int i=0; i< this->size;++i){
            tmp[i]=_tekst[i];
        }
        this->value=tmp;
    }

    StringObject(std::string _tekst){
        this->size = _tekst.length();
        char *tmp = new char[this->size];
        for(int i=0; i< this->size;++i){
            tmp[i]=_tekst[i];
        }
        this->value=tmp;
    }

    void whatAmI() override{
        std::cout<<"StringObject!"<<std::endl;
    }

    std::string toString() override{
        return (std::string)this->value;
    }

    Object* clone() override{
        return new StringObject(*this);
    }

    virtual ~StringObject() {
        delete[] value;
    }
};

class IntObject : public Object{
private:
    int value;
public:
    IntObject(){
        this->value = 0;
    };

    IntObject(int val){
        this->value= val;
    }

    void whatAmI() override{
        std::cout<<"IntObject!"<<std::endl;
    }

    std::string toString() override{
        return std::to_string(this->value);
    }

    Object* clone() override{
        return new IntObject(*this);
    }

    virtual ~IntObject(){}
};

class DoubleObject : public Object{
private:
    double value;
public:
    DoubleObject(){
        this->value = 0.0;
    };

    DoubleObject(double val){
        this->value= val;
    }

    void whatAmI() override{
        std::cout<<"DoubleObject!"<<std::endl;
    }

    std::string toString() override{
        return std::to_string(this->value);
    }

    Object* clone() override{
        return new DoubleObject(*this);
    }

    virtual ~DoubleObject(){}
};

//enum obiekty {object = 0, stringObject = 1, intObject = 2, doubleObject = 3};
//
//void funkcja(std::vector<Object*> VO, obiekty rodzaj){
//    int rozmiar;
//    switch(rodzaj) {
//        case 0:
//            std::cout<<"Wyswietlam obiekty klasy Object "<<std::endl;
//            break;
//        case 1:
//            std::cout<<"Wyswietlam obiekty klasy StringObject "<<std::endl;
//            rozmiar = sizeof (char *);
//            break;
//        case 2:
//            std::cout<<"Wyswietlam obiekty klasy IntObject "<<std::endl;
//            rozmiar = sizeof (int);
//            break;
//        case 3:
//            std::cout<<"Wyswietlam obiekty klasy DoubleObject "<<std::endl;
//            rozmiar = sizeof (double);
//            break;
//        default:
//            std::cout<<"Stosuj sie do instrukcji... "<<std::endl;
//            rozmiar = -1;
//            break;
//    }
//    for (int i=0; i<VO.size(); ++i){
//        //if (typeid(VO[i]) == typeid(StringObject)){
//        if VO[i]{
//            std::cout<<"Rellll"<<std::endl;
//        }
//    }
//}

int main(){
    std::cout<<"Testy StringObject"<<std::endl;
    // Object o; Variable type 'Object' is an abstract class <- good
    std::cout<<std::endl<<"SO: "<<std::endl;
    StringObject so; // works <- good
    std::cout<<"Jestem obiektem ";so.whatAmI(); // prints "Jestem obiektem StringObject!" <- good
    std::cout<<so.toString(); // prints "I am empty!" <- good
    std::cout<<std::endl<<"SO1: "<<std::endl;
    StringObject so1 = StringObject("Testuje sie!");
    std::cout<<"Jestem obiektem ";so1.whatAmI(); // prints "Jestem obiektem StringObject!" <- good
    std::cout<<so1.toString(); // prints "Testuje sie!" <- good
    std::cout<<std::endl<<"SO2: "<<std::endl;
    Object *so2 = so1.clone(); //it works
    std::cout<<"Jestem obiektem ";so2->whatAmI(); // prints "Jestem obiektem StringObject!" <- good
    std::cout<<so2->toString(); // prints "Testuje sie!" <- good

    std::cout<<std::endl<<"Testy IntObject"<<std::endl;
    std::cout<<std::endl<<"IO: "<<std::endl;
    IntObject io; // works <- good
    std::cout<<"Jestem obiektem ";io.whatAmI(); // prints "Jestem obiektem IntObject!" <- good
    std::cout<<io.toString(); // prints "0" <- good
    std::cout<<std::endl<<"IO1: "<<std::endl;
    IntObject io1 = IntObject(5);
    std::cout<<"Jestem obiektem ";io1.whatAmI(); // prints "Jestem obiektem IntObject!" <- good
    std::cout<<io1.toString(); // prints "5" <- good
    std::cout<<std::endl<<"IO2: "<<std::endl;
    Object *io2 = io1.clone(); //it works
    std::cout<<"Jestem obiektem ";io2->whatAmI(); // prints "Jestem obiektem IntObject!" <- good
    std::cout<<io2->toString(); // prints "5" <- good

    std::cout<<std::endl<<"Testy DoubleObject"<<std::endl;
    std::cout<<std::endl<<"DOO: "<<std::endl;
    DoubleObject doo; // works <- good
    std::cout<<"Jestem obiektem ";doo.whatAmI(); // prints "Jestem obiektem DoubleObject!" <- good
    std::cout<<doo.toString(); // prints "0.000000" <- good
    std::cout<<std::endl<<"DOO1: "<<std::endl;
    DoubleObject doo1 = DoubleObject(5.85);
    std::cout<<"Jestem obiektem ";doo1.whatAmI(); // prints "Jestem obiektem DoubleObject!" <- good
    std::cout<<doo1.toString(); // prints "5.850000" <- good
    std::cout<<std::endl<<"DOO2: "<<std::endl;
    std::cout<<"Jestem obiektem ";Object *doo2 = doo1.clone(); //it works
    doo2->whatAmI(); // prints "Jestem obiektem DoubleObject!" <- good
    std::cout<<doo2->toString(); // prints "5.850000" <- good

    std::vector<Object*> tablica;
    tablica.push_back(&so);
    tablica.push_back(&so1);
    tablica.push_back(so2);
    tablica.push_back(&io);
    tablica.push_back(&io1);
    tablica.push_back(io2);
    tablica.push_back(&doo);
    tablica.push_back(&doo1);
    tablica.push_back(doo2);
    //const std::type_info& info1=typeid(Object);
//    funkcja(tablica,stringObject);
}