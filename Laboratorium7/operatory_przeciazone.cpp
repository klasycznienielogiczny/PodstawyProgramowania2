//
// Created by piotr on 21.04.2021.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

class NotUnderstandableFile{
private:
    std::fstream file;
    std::string filename;
public:
    NotUnderstandableFile(const std::string filepath) : filename(filepath){}

    NotUnderstandableFile(){
        this->filename="Brak";
    };

    std::string getName() const{
        return filename;
    }
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator=
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    NotUnderstandableFile& operator=(const NotUnderstandableFile &f){
        if (this==&f)
            return *this;

//        std::filebuf *in = f.file.rdbuf();
//        std::filebuf *dest = this->file.rdbuf();
//        char c = in->sbumpc();
//        while (c!=EOF){
//            dest->sputc(c);
//            c=in->sbumpc();
//        }
        this->file.open(this->filename,std::ios::in | std::ios::out | std::ios::trunc);
        std::fstream tmp;
        tmp.open(f.filename, std::ios::in | std::ios::out);
        if (file.bad()==true || tmp.bad()==true){
            throw std::fstream::failure("Unexpected error");
        }
        this->file << tmp.rdbuf();
        this->filename=f.filename;
        this->file.close();
        tmp.close();
        return *this;
    };

/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator+=
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    NotUnderstandableFile& operator+=(const NotUnderstandableFile &f) {
        this->file.open(this->filename,std::ios::out | std::ios::app);
        std::fstream tmp;
        tmp.open(f.filename, std::ios::in | std::ios::out);
        if (file.bad()==true || tmp.bad()==true){
            throw std::fstream::failure("Unexpected error");
        }
        this->file << tmp.rdbuf();
        this->file.close();
        tmp.close();
        return *this;
    }
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator--
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    NotUnderstandableFile& operator--(){
        std::vector<std::string> v_str;
        std::fstream tmp;
        tmp.open(this->filename, std::ios::in | std::ios::out);
        int linesCount = 0;
        std::string line;
        while(std::getline(tmp, line)){
            v_str.push_back(line);
            ++linesCount;
        }
        tmp.close();
        this->file.open(this->filename,std::ios::out);
        this->file.seekg(0, std::ios::end);
        for(int counter=0; counter<linesCount-1;++counter) {
            this->file.write(v_str[counter].c_str(),v_str[counter].size());
            this->file << "\n";
        }
        this->file.close();
        return *this;
    }

    friend std::ostream& operator <<(std::ostream &os, const NotUnderstandableFile &f);
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator>>
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    friend std::istream& operator >>(std::istream &in, NotUnderstandableFile &f){
        std::string tmp;
        f.file.open(f.filename, std::ios::in | std::ios::out);
        in >> tmp;
        f.file << tmp;
        f.file.close();
        return in;
    }
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator==
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    bool operator==(NotUnderstandableFile &f){
        std::string tmp;
        std::vector<std::string> v_str1, v_str2;
        f.file.open(f.filename, std::ios::in | std::ios::out);
        this->file.open(this->filename, std::ios::in | std::ios::out);
        std::string line;
        int linesCount=0, linesCount2=0;
        while(std::getline(f.file, line)){
            v_str1.push_back(line);
            ++linesCount;
        }
        while(std::getline(this->file, line)){
            v_str2.push_back(line);
            ++linesCount2;
        }
        f.file.close();
        this->file.close();
        if (linesCount != linesCount2)
            return false;

        for(int i = 0; i<linesCount; ++i) {
            if (v_str1[i] != v_str2[i])
                return false;
        }
        return true;
    }

/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator>>
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    NotUnderstandableFile& operator>>(NotUnderstandableFile &f){
        this->file.open(this->filename,std::ios::in | std::ios::out);
        f.file.open(f.filename, std::ios::in | std::ios::app);
        std::vector<std::string> v_str;
        int linesCount = 0;
        std::string line;
        while(std::getline(this->file, line)){
            v_str.push_back(line);
            ++linesCount;
        }
        f.file.seekg(0,std::ios::end);
        for(int counter=0; counter<linesCount;++counter) {
            f.file.write(v_str[counter].c_str(),v_str[counter].size());
            f.file << "\n";
        }
        this->file.close();
        f.file.close();
        return f;
    }
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator<<
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    NotUnderstandableFile& operator<<(NotUnderstandableFile &f){
        this->file.open(this->filename,std::ios::in | std::ios::app);
        f.file.open(f.filename, std::ios::in | std::ios::out);
        std::vector<std::string> v_str;
        int linesCount = 0;
        std::string line;
        while(std::getline(f.file, line)){
            v_str.push_back(line);
            ++linesCount;
        }
        this->file.seekg(0,std::ios::end);
        for(int counter=0; counter<linesCount;++counter) {
            this->file.write(v_str[counter].c_str(),v_str[counter].size());
            this->file << "\n";
        }
        this->file.close();
        f.file.close();
        return *this;
    }

/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator()
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    NotUnderstandableFile& operator()(std::string (*funkcja)(std::string filepath), std::string filepath){
        NotUnderstandableFile *tmp = new NotUnderstandableFile;
        tmp->filename=funkcja(filepath);
        return *tmp;
    }
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator char*()
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    operator char* () const{
        char *tmp = new char[this->filename.length()];
        for (int i=0; i<this->filename.length();++i)
            tmp[i] = char(this->filename[i]);
        return tmp;
    }
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator new
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    void * operator new(size_t rozmiar) {
        void *pointer;
        pointer = malloc(rozmiar);
        if(!pointer){
            throw std::bad_alloc();
        }
        return pointer;
    }

/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator delete
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    void operator delete(void* wsk) {
        free(wsk);
    }
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator new[]
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    void* operator new[](size_t rozmiar) {
        void *pointer;
        pointer = malloc(rozmiar);
        if(!pointer){
            throw std::bad_alloc();
        }
        return pointer;
    }

/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator delete[]
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
    void operator delete[](void* wsk) {
        free(wsk);
    }

    ~NotUnderstandableFile(){
        if (file.is_open()==true){
            file.close();
        }
    }
};
std::string fun(std::string str){
    std::string tmp=str;
    for(int i =0; i<str.length(); ++i)
        tmp[i]= toupper(str[i]);
    return tmp;
}
/*! \class NotUnderstandableFile
 *  \brief NotUnderstandableFile operator<<
 *  \author klasycznienielogiczny
 *  \author Several species of small furry animals gathered together
 *          in a cave and grooving with a pict.
 *  \version -1.0.0
 *  \date    20.04.2021
 *  \bug It crashes a lot and requires huge amounts of memory.
 *  \bug The class introduces the more bugs, the longer it is used and IT'S NOT A JOKE!
 *  \warning This class may explode in your face and nobody take the responsibility
 *  \warning If you inherit anything from this class, you should fix it first
 */
std::ostream& operator <<(std::ostream &os, const NotUnderstandableFile &f){
    std::vector<std::string> v_str;
    std::fstream tmp;
    tmp.open(f.filename, std::ios::in | std::ios::out);
    int linesCount = 0;
    std::string line;
    while(std::getline(tmp, line)){
        v_str.push_back(line);
        ++linesCount;
    }
    tmp.close();
    os << "Filename: "<< f.getName() <<", Text in file:\n";
    for(int counter=0; counter<linesCount;++counter) {
        os<<v_str[counter]<<std::endl;
    }
    return os;
}



int main(){
    NotUnderstandableFile a("C:\\Users\\piotr\\Desktop\\PodstawyProgramowania2\\test.txt");
    std::cout<<a.getName()<<std::endl;
    NotUnderstandableFile b("C:\\Users\\piotr\\Desktop\\PodstawyProgramowania2\\xd.txt");
    NotUnderstandableFile c("C:\\Users\\piotr\\Desktop\\PodstawyProgramowania2\\xd2.txt");
    std::cout<<b.getName()<<std::endl;
    std::cout<<c.getName()<<std::endl;
    //b=a=c; <-działa
    std::cout<<b.getName()<<std::endl;
    std::cout<<c.getName()<<std::endl;
    std::cout<<a.getName()<<std::endl;
    a+=b; //<-działa
    --c; //<- działa
    std::cout << a;
    NotUnderstandableFile d("C:\\Users\\piotr\\Desktop\\PodstawyProgramowania2\\zad3.txt");
    std::cin >> d;
    a>>d; //<-działa
    b<<a;
    std::string (*funkcja)(std::string fname);
    funkcja=fun;
    NotUnderstandableFile e("C:\\Users\\piotr\\Desktop\\PodstawyProgramowania2\\zad4.txt"),f;
    f = e(funkcja, "C:\\Users\\piotr\\Desktop\\PodstawyProgramowania2\\zad4.txt");
    std::cout<<e.getName();
    std::cout<<f.getName();
    if(b==c) //<-DZIALA!!!!!
        std::cout<<"Rowne"<<std::endl;
    else
        std::cout<<"Nierowne"<<std::endl;

    char *test = new char[128];
    test = (char*)e; //dziala
    std::cout<<test; //hooooray
    return 0;
}