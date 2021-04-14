// author: Grzegorz Prowadzacy

#include "vector.h"

size_t Vector::size() const {
    return this->_size;
}

size_t Vector::capacity() const {
    return this->_capacity;
}

Vector::Vector(size_t rozmiar){
    this->data = new Fraction[rozmiar];
    this->_capacity = rozmiar;
    this->_size = 0;
}

Vector::Vector(const Vector &v){
    this->data = new Fraction[v._capacity];
    if(this->data) {
        for (size_t i = 0; i < v._size; ++i)
            this->data[i] = v.data[i];
    }
    else
        throw std::invalid_argument("NULL object!");
    this->_size=v._size;
    this->_capacity = v._capacity;
}

void Vector::push_back(const Fraction &frac) {
    ++this->_size;
    if(this->_size > this->_capacity)
        ++this->_capacity;

    Fraction *tmp = new Fraction[this->_capacity];
    if(tmp){
        for (size_t i = 0; i < this->_size-1; ++i)
            tmp[i] = this->data[i];
        tmp[this->_size-1].setNumerator(frac.getNumerator());
        tmp[this->_size-1].setDenominator(frac.getDenominator());
    }
    delete[] this->data;
    this->data = tmp;
}

Vector::Vector(Vector &&v) : data(v.data), _capacity(v._capacity), _size(v._size){
    v.data = NULL;
    v._size=0;
    v._capacity=0;
};

Vector& Vector::operator=(const Vector &v){
    this->data = new Fraction[v._capacity];
    this->_size=v._size;
    this->_capacity=v._capacity;
    if(this->data) {
        for (size_t i = 0; i < v._size; ++i)
            this->data[i] = v.data[i];
    }
    else
        throw std::invalid_argument("NULL object!");
    return *this;
}

Vector& Vector::operator=(Vector &&v){
    //this->data = v.data;
    std::swap(this->data, v.data);
    std::swap(this->_size , v._size);
    std::swap(this->_capacity , v._capacity);

    v.data = NULL;
    v._size = 0;
    v._capacity = 0;
    return *this;
};

Fraction Vector::operator[](const size_t index) const {
    if(index >= this->_size)
        throw std::out_of_range("Index out of bound");
    else
        return data[index];
}

Vector::~Vector(){
    delete[] data;
    delete data;
}
