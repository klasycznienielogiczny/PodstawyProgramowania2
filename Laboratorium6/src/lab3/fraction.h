#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <cmath>

/** Implementacja ulamka:
Zaimplementuj klase Ulamek (ang. Fraction), posiadająca licznik (ang. numerator) i mianownik (ang. denominator).
       Powinna zawierac jeden konstruktor ustawiajacy licznik i mianownik (domyslne wartosci licznika=0 a mianownika domyslna 1)
       Gettery i settery do wartosci licznika i mianownika
       Settery nie powinny skracac ulamkow
       operator+ dla ulamka zwracajacy ulamek
       operator* dla ulamka zwracajacy ulamek
Niepoprawny mianownik powinien byc zglaszany przez wyjatek std::invalid_argument.
Prosze o skracanie ulamkow po operacji + i * (pomocny moze sie okazac algorytm euklidesa), oczywiscie tutaj robimy tylko dla przypadkow dodatnich
**/

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int num=0, int den=1){
        if (den == 0)
            throw std::invalid_argument("Mianownik nie moze byc rowny 0!");
        this->numerator=num;
        this->denominator=den;
    };
    void setNumerator(int num);
    void setDenominator(int den);
    int getNumerator() const;
    int getDenominator() const;
    ~Fraction(){}
};

inline int NWD(int _a, int _b);
inline int NWW(int a, int b);
Fraction normalize(Fraction frac);
const Fraction operator+(const Fraction &frac1, const Fraction &frac2);
const Fraction operator*(const Fraction &frac1, const Fraction &frac2);
#endif // FRACTION_H
