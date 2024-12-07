#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
private:
    float area;
    float circumference;
public:
    Figure();
    virtual ~Figure();

    float getArea() const;
    void setArea(float area1);

    float getCircumference() const;
    void setCircumference(float circ1);

    virtual void calculateArea()=0;
    virtual void calculateCircumference()=0;
    virtual void show() const;
};

Figure::Figure() {
    std::cout << "Konstruktor klasy bazowej Figure" << std::endl;
}

Figure::~Figure() {
    std::cout << "Wirtualny destruktor klasy bazowej Figure" << std::endl;
}

float Figure::getArea() const {
    return this->area;
}

void Figure::setArea(float area1) {
    this->area = area1;
}

float Figure::getCircumference() const {
    return this->circumference;
}

void Figure::setCircumference(float circ1) {
    this->circumference = circ1;
}

void Figure::show() const {
    std::cout << "Pole: " << this->area << ", Obwod: " << this->circumference << std::endl;
}

#endif