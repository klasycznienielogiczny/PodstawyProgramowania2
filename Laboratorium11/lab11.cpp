#include <iostream>
#include <cstring>

#define N 10

class VectoredList{
private:
    class Bucket{
    public:
        Bucket *prev;
        Bucket *next;
        std::string *elements;
        size_t el_count;
        size_t block_size;

        Bucket(){
            this->el_count=0;
            this->block_size=N;
            this->prev= nullptr;
            this->next= nullptr;
            this->elements = new std::string[block_size];
        };

//        explicit Bucket(std::string el){
//            this->el_count=1;
//            this->block_size=N;
//            this->prev= nullptr;
//            this->next= nullptr;
//            this->elements = new std::string[N];
//            this->elements[el_count-1]=el;
//        };

        ~Bucket(){
            delete[] elements;
            delete prev;
            delete next;
        }

    };

    class LVIterator{
        //const VectoredList &v;
        std::string* cursor;
    public:
        LVIterator(std::string *v_) : cursor(v_){};

        LVIterator operator++(){
            cursor++;
            return *this;
        }

        LVIterator operator++(int){
            LVIterator tmp = *this;
            ++*this;
            return tmp;
        }

        bool operator!=(const LVIterator& rhs) { return cursor != rhs.cursor; }

        ~LVIterator(){};
    };

    Bucket *head;
    Bucket *tail;
    size_t size_;
    size_t capacity_;

public:
    VectoredList() : head(new Bucket[1]){
        this->tail = head;
        this->size_ = 1;
        this->capacity_ = 1;
        this->head->prev=this->head;
    }

    explicit VectoredList(size_t cap){
        if (cap<1)
            throw std::bad_alloc();

        this->head = new Bucket[cap];
        this->head->prev=this->head;
        this->tail = head;
        this->size_ = 1;
        this->capacity_ = cap;
    }

//    VectoredList(std::string el){
//        this->head = new Bucket(el);
//        this->tail = head;
//        this->size_ = 1;
//        this->capacity_ = 1;
//    }
//
//    VectoredList(size_t cap, std::string el) : head(new Bucket(el)){
//        this->tail = head;
//        this->size_ = 1;
//        this->capacity_ = cap;
//    }

    void push_back(const std::string &el){
        if (this->tail->el_count < this->tail->block_size){
            this->tail->elements[this->tail->el_count++] = el;
        }
        else if(this->size_ < this->capacity_){
            this->tail = &this->head[this->size_];
            ++this->size_;
            this->head[size_-1].next = &this->head[size_];
            this->head[size_].prev = &this->head[size_-1];
            this->tail->elements[this->tail->el_count++] = el;
        }
        else{
            auto * tmp = new Bucket[2*capacity_];
            for(size_t i = 0; i<this->size_; ++i){
                for(size_t j =0; j<this->head->block_size; ++j){
                    tmp[i].elements[j] = this->head[i].elements[j];
                }
                tmp[i-1].next = &tmp[i];
                tmp[i].prev = &tmp[i-1];
            }
            ++this->size_;
            this->head = tmp;
            this->tail = &this->head[this->size_-1];
            this->tail->elements[this->tail->el_count++] = el;
            this->capacity_ *= 2;
        }
    }

    std::string& operator[](const size_t &index) const{
        if(index<0)
            throw std::invalid_argument("<0");

        return this->head[index/N].elements[index%N];
    }

    LVIterator begin(){
        return LVIterator(head->elements);
    }

    LVIterator end(){
        return LVIterator(tail->elements+tail->el_count);
    }

    ~VectoredList(){
        delete[] head;
        delete tail;
    }
};

int main(){
    std::cout<<"Boje sie cokolwiek zrobic"<<std::endl;
    // ZADANIE 1
//    VectoredList v = VectoredList(1);
//    for(size_t i = 0; i<101; ++i)
//        v.push_back(std::to_string(2*i));
//
//    for(size_t i = 100;i>=0;--i){
//        std::cout<<v[i]<<std::endl; //AWWWW. DZIAłA!
//        }
    VectoredList v1 = VectoredList(1);
    for(size_t i = 0; i<15; ++i)
        v1.push_back(std::to_string(2*i));

    for(auto element : v1)
        std::cout<<element<<std::endl;
    return 0;
}