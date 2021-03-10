#include <iostream>
#include <vector>

// zadanie 1
struct Ulamek{
    int l;
    int m;
};

void print(int arg){
    std::cout << arg;
}

void print(float arg){
    std::cout << arg;
}

void print(Ulamek arg){
    std::cout << arg.l <<"/"<<arg.m;
}

void print(...){
    std::cout << "Nie mozna wyswietlic argumentu";
}

void print(const char *arg= nullptr){
    std::cout << arg;
}

void print(Ulamek &arg){
    std::cout << arg.l <<"/"<<arg.m;
}

void print(int tab[], int rozmiar){
    for(int i=0;i<rozmiar;++i)
        std::cout<<tab[i]<<"\t";

    std::cout<<std::endl;
}

void print(int (&tab)[3]){
    for(int i=0;i<sizeof(tab)/sizeof(int);++i)
        std::cout<<tab[i]<<"\t";

    std::cout<<std::endl;
}

//zadanie 2
int *doubleCopy(int *pocz, int *kon){
    if(pocz==NULL || kon==NULL)
        return NULL;

    int rozmiar=kon-pocz;
    int *tab=new int[rozmiar];
    for(;pocz!=kon;pocz++){
        *tab=(*pocz)*2;
        tab++;
    }
    return tab-rozmiar;
}

//zadanie 3
std::string dnaD(std::string tekst){
    for(int i=0;tekst[i]!=NULL;++i){
        if(tekst[i]=='d')
            tekst[i]='D';
    }
    return tekst;
}

std::string dnaDzakres(std::string tekst){
    for(int i=0;i< sizeof(tekst);++i){
        if(tekst[i]=='d')
            tekst[i]='D';
    }
    return tekst;
}

std::string dnaDauto(std::string tekst){
    for(auto i=0;i< sizeof(tekst);++i){
        if(tekst[i]=='d')
            tekst[i]='D';
    }
    return tekst;
}
// zadanie 4
void print(std::vector<int> v){
    std::cout<<"Zawartosc vector<int>: "<<std::endl;
    for(int i=0; i<v.size(); ++i)
        std::cout<<v[i]<<std::endl;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    int tab[3]={0,4,8}; //zadanie 2
    int *end=tab+3;
    int *tab2=doubleCopy(tab,end);
    for(int i=0;i<3;++i)
        std::cout<<tab2[i]<<std::endl;
    std::cout<<std::endl; //zadanie 3
    std::string tekst="male d na duze D";
    std::string tekst2=dnaD(tekst);
    std::cout<<tekst2<<std::endl;
    std::string tekst3=dnaDzakres(tekst);
    std::cout<<tekst3<<std::endl;
    auto tekst4=dnaDauto(tekst);
    std::cout<<tekst4<<std::endl;

    std::vector<int> wekt {4,5,6,8}; //zadanie 4
    wekt.push_back(10);
    print(wekt);
    return 0;
}
