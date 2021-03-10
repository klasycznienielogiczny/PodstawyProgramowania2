struct Ulamek{
    int l;
    int m;
};

//AKTYWNOŚĆ
//https://github.com/tfc/pprintpp

void print(int arg){
    pprintf("{}", arg);
}

void print(float arg){
    pprintf("{}", arg);
}

void print(Ulamek arg){
    pprintf("{}/{}", arg.l, arg.m);
}

void print(...){
    pprintf("{s}","Nie mozna wyswietlic argumentu");
}

void print(const char *arg= nullptr){
    pprintf("{s}", arg);
}

void print(Ulamek &arg){
    pprintf("{}/{}", arg.l, arg.m);
}

void print(int tab[], int rozmiar){
    for(int i=0;i<rozmiar;++i)
        pprintf("{} \t", tab[i]);
}

void print(int (&tab)[3]){
    for(int i=0;i<sizeof(tab)/sizeof(int);++i)
        pprintf("{} \t", tab[i]);
}



//https://github.com/fmtlib/fmt

void print(int arg){
    fmt::print("{}", arg);
}

void print(float arg){
    fmt::print("{}", arg);
}

void print(Ulamek arg){
    fmt::print("{1}/{0}", arg.m, arg.l);
}

void print(...){
    fmt::print("{}","Nie mozna wyswietlic argumentu");
}

void print(const char *arg= nullptr){ //std::string s {"dowolny tekst"};
    fmt::print("{}", arg); //const char * ps = s.c_str();
}                           //print(ps);

void print(Ulamek &arg){
    fmt::print("{}/{}", arg.l, arg.m);
}

void print(int tab[], int rozmiar){
    for(int i=0;i<rozmiar;++i)
        fmt::print("{} \t", tab[i]);
}

void print(int (&tab)[3]){
    for(int i=0;i<sizeof(tab)/sizeof(int);++i)
        fmt::print("{} \t", tab[i]);
}



//https://en.cppreference.com/w/cpp/utility/format

void print(int arg){
    std::cout << std::format("{}",arg);
}

void print(float arg){
    std::cout << std::format("{}",arg);
}

void print(Ulamek arg){
    std::cout << std::format("{}/{}",arg.l, arg.m);
}

void print(...){
    std::cout << std::format("Nie mozna wyswietlic argumentu");
}

void print(const char *arg= nullptr){
    std::cout << std::format("{}",arg);
}

void print(Ulamek &arg){
    std::cout << std::format("{}/{}",arg.l, arg.m);
}

void print(int tab[], int rozmiar){
    for(int i=0;i<rozmiar;++i)
        std::cout<<std::format("{} \t",tab[i]);
}

void print(int (&tab)[3]){
    for(int i=0;i<sizeof(tab)/sizeof(int);++i)
        std::cout<<std::format("{} \t",tab[i]);
}