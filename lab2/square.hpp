#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "figure.hpp"

class Square : public Figure {
private:
    float a;
public:
    Square(float a1);
    ~Square();

    virtual void calculateArea() override;
    virtual void calculateCircumference() override;
    virtual void show() override;
};

Square::Square(float a1): a(a1) {
    std::cout << "Konstruktor klasy Square" << std::endl;
}

Square::~Square() {
    std::cout << "Destruktor klasy Square" << std::endl;
}

void Square::calculateArea() {
    float p = this->a * this-> a;
    this->setArea(p);
}

void Square::calculateCircumference() {
    float c = 4 * this->a;
    this->setCircumference(c);
}

void Square::show() {
    std::cout << "Show w klasie Square, pole: " << this->getArea()
        << ", obwod: " << this->getCircumference()
        << std::endl;
}

#endif