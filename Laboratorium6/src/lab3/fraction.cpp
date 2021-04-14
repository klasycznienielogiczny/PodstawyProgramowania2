#include "fraction.h"

inline int NWD(int _a, int _b){
    int a = abs(_a);
    int b = abs(_b);
    int pom;
    while(b!=0){
        pom = b;
        b = a%b;
        a = pom;
    }
    return a;
}

inline int NWW(int a, int b){
    return abs(a*b)/NWD(a,b);
}

void Fraction::setNumerator(int num) {
    this->numerator = num;
}

void Fraction::setDenominator(int den) {
    if (den==0)
        throw std::invalid_argument("Mianownik nie moze byc rowny 0!");
    else
        this->denominator = den;
}

int Fraction::getNumerator() const{
    return this->numerator;
}

int Fraction::getDenominator() const{
    return this->denominator;
}

Fraction normalize(Fraction frac){
    Fraction fraction;
    int num = frac.getNumerator(), den=frac.getDenominator();

    if (num * den <= 0) {
        if (num > 0) {
            num *= -1;
            den *= -1;
        }
    } else {
        if (num < 0 and den < 0){
            num *= -1;
            den *= -1;
        }
    }

    int nwd = NWD(num, den);
    num /= nwd;
    den /= nwd;

    fraction.setNumerator(num);
    fraction.setDenominator(den);

    return fraction;
}

const Fraction operator+(const Fraction &frac1, const Fraction &frac2){
    Fraction fraction;
    if ((frac1.getDenominator() == 0) || ((frac2.getDenominator() == 0)))
        throw std::invalid_argument("Mianownik nie moze byc rowny 0!");

    fraction.setDenominator(NWW(frac1.getDenominator(), frac2.getDenominator()));
    fraction.setNumerator(fraction.getDenominator()/frac1.getDenominator()*frac1.getNumerator() + fraction.getDenominator()/frac2.getDenominator()*frac2.getNumerator());

    fraction = normalize(fraction);

    return fraction;
}

const Fraction operator*(const Fraction &frac1, const Fraction &frac2){
    Fraction fraction;
    if ((frac1.getDenominator() == 0) || ((frac2.getDenominator() == 0)))
        throw std::invalid_argument("Mianownik nie moze byc rowny 0!");

    fraction.setDenominator(frac1.getDenominator() * frac2.getDenominator());
    fraction.setNumerator(frac1.getNumerator() * frac2.getNumerator());

    fraction = normalize(fraction);

    return fraction;
}