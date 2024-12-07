#include <iostream>

#include "figure.hpp"
#include "square.hpp"
#include "circle.hpp"

int main(void) {
    // Zad 2.1
    Figure* f1 = new Square(5);
    Figure* f2 = new Circle(3);

    f1->calculateArea();
    f1->calculateCircumference();
    f1->show();

    f2->calculateArea();
    f2->calculateCircumference();
    f2->show();

    delete f1;
    delete f2;

    // Zad 2.2

    return EXIT_SUCCESS;
}