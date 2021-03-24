#include <iostream>

using namespace std;

#include "matrix.h"

//#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
//    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
//#else
//    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
//#endif

TwoDimensionMatrix::TwoDimensionMatrix(){
    matrix = new MatrixElement * [size];
    for(int i=0; i< size; ++i)
        matrix[i] = new MatrixElement[size];

    for (int i=0;i<this->size;++i)
        for (int j=0;j<this->size;++j)
            this->matrix[i][j]=0;
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &m){
    matrix = new MatrixElement * [size];
    for(int i=0; i< size; ++i)
        matrix[i] = new MatrixElement[size];

    for (int i=0;i<this->size;++i)
        for (int j=0;j<this->size;++j)
            this->matrix[i][j]=m.matrix[i][j];
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement m[size][size]){
    matrix = new MatrixElement * [size];
    for(int i=0; i< size; ++i)
        matrix[i] = new MatrixElement[size];

    for (int i=0;i<this->size;++i)
        for (int j=0;j<this->size;++j)
            this->matrix[i][j]=m[i][j];
}

TwoDimensionMatrix::~TwoDimensionMatrix(){
    delete[] matrix;
    delete matrix;
};

TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix &m){
    for (int i=0;i<this->size;++i)
        for (int j=0;j<this->size;++j)
            this->matrix[i][j]=m.matrix[i][j];
    return *this;
}

std::ostream& operator <<(std::ostream &os, const TwoDimensionMatrix &m){
    os <<  m.get(0,0) <<" , " << m.get(0,1) <<"/n" << m.get(1,0) <<" , " << m.get(1,1);
    return os;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(const MatrixElement &number) {
    this->matrix[0][0] *= number;
    this->matrix[0][1] *= number;
    this->matrix[1][0] *= number;
    this->matrix[1][1] *= number;
    return *this;
}

MatrixElement TwoDimensionMatrix::get(int row, int col) const {
    return TwoDimensionMatrix::matrix[row][col];
}

int TwoDimensionMatrix::getSize() const{
    return this->size;
}

const TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2){
    const MatrixElement m[2][2]={{matrix1.get(0,0)+matrix2.get(0,0), matrix1.get(0,1)+matrix2.get(0,1)},
                                 {matrix1.get(1,0)+matrix2.get(1,0), matrix1.get(1,1)+matrix2.get(1,1)}};
    TwoDimensionMatrix m1(m);
    return m1;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix) const{
    const MatrixElement m[2][2]={{this->matrix[0][0] && matrix.get(0,0), this->matrix[0][1] && matrix.get(0,1)},
                                 {this->matrix[1][0] && matrix.get(1,0), this->matrix[1][1] && matrix.get(1,1)}};
    TwoDimensionMatrix m1(m);
    return m1;
}

MatrixElement* TwoDimensionMatrix::operator[](const size_t &i) const{
    return matrix[i];
}

TwoDimensionMatrix::operator size_t() const{
    return (size_t)this->getSize();
}