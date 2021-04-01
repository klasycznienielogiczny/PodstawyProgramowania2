/*
 * aktywnosc5.cpp
 *
 * Copyright 2021 klasycznienielogiczny
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <experimental/filesystem>

#define H_SIZE 1200
#define V_SIZE 800

const float pi=3.14159265358;

class Kolo{
private:
    mutable float r;
public:
    Kolo(){
        this->r=50;
        std::cout<<"Kolo. Domyslny konstruktor. r=50"<<std::endl;
    }
    Kolo(float _r){
        r=_r;
        std::cout<<"Konstruktor z parametrem. r="<<this->r<<std::endl;
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
    sf::CircleShape rysuj(){
        sf::CircleShape kolo(2*this->r);
        kolo.setFillColor(sf::Color::Green);
        kolo.setPosition(this->r, this->r);
        kolo.setOutlineThickness(4.f);
        kolo.setOutlineColor(sf::Color::Blue);
        return kolo;
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
        this->a=30;
        this->b=50;
        std::cout<<"Domyslny konstruktor. a=30, b=50"<<std::endl;
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

    sf::RectangleShape rysuj(){
        sf::RectangleShape prostokat(sf::Vector2f(this->a, this->b));
        prostokat.setFillColor(sf::Color::Red);
        prostokat.setPosition(H_SIZE/2, 10+this->b);
        prostokat.setOutlineThickness(4.f);
        prostokat.setOutlineColor(sf::Color::Yellow);
        return prostokat;
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
        this->a=30;
        b=30;
        c=30;
        std::cout<<"Domyslny konstruktor. a=b=c=30"<<std::endl;
    }
    Trojkat(float _a){
        this->a=_a;
        b=_a;
        c=_a;
        std::cout<<"Trojkat. Konstruktor z parametrem. a=b=c="<<_a<<std::endl;
    }
    /*Trojkat(float _a,float _b,float _c){
        this->a=_a;
        b=_b;
        c=_c;
        std::cout<<"Trojkat. Konstruktor z parametrami. a="<<_a<<" b="<<this->b<<" c="<<c<<std::endl;
    }*/

    sf::CircleShape rysuj(){
        sf::CircleShape trojkat(this->a, 3);
        trojkat.setFillColor(sf::Color::Blue);
        trojkat.setPosition(H_SIZE-70-this->a, this->b+30);
        trojkat.setOutlineThickness(4.f);
        trojkat.setOutlineColor(sf::Color::Magenta);
        return trojkat;
    }

    ~Trojkat(){
        std::cout<<"Destruktor trojkata"<<std::endl;
    }
};

int main()
{
    Kolo kolo;
    Kolo kolo1(100);
    Prostokat prostokat(100,80);
    Prostokat prostokat1(33);
    Trojkat trojkat(50);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(H_SIZE, V_SIZE), "Aktywnosc 5 by klasycznienielogiczny", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                sf::Texture outputTexture;
                outputTexture.create(H_SIZE, V_SIZE);
                outputTexture.update(window);

                sf::Image output;
                output.create(H_SIZE, V_SIZE);
                output = outputTexture.copyToImage();
                output.saveToFile("aktywnosc5.png");
                window.close();
            }
        }

        window.clear();
        window.draw(kolo.rysuj());
        window.draw(kolo1.rysuj());
        window.draw(prostokat.rysuj());
        window.draw(prostokat1.rysuj());
        window.draw(trojkat.rysuj());
        window.display();
    }

    return 0;
}
