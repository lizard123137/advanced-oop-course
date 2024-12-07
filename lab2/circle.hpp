#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <iostream>
#include "figure.hpp"

class Circle : public Figure {
private:
    float r;
public:
    Circle(float r1);
    ~Circle();
    virtual void calculateArea() override;
    virtual void calculateCircumference() override;
};

Circle::Circle(float r1): r(r1) {
    std::cout << "Konstruktor w klasie Circle" << std::endl;
}

Circle::~Circle() {
    std::cout << "Destruktor w klasie Circle" << std::endl;
}

void Circle::calculateArea() {
    float p = M_PI * this->r * this->r;
    this->setArea(p);
}

void Circle ::calculateCircumference() {
    float c = M_PI * 2 * this->r;
    this->setCircumference(c);
}

#endif