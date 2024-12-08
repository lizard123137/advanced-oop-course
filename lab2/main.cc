#include <iostream>

#include "figure.hpp"
#include "square.hpp"
#include "circle.hpp"

#include "employee.hpp"
#include "developer.hpp"
#include "team_leader.hpp"

/**
 * I didn't choose the function names,
 * also the assignment explicitly stated to not use vectors...
 */
void whoWorkMoreThan5Years(Employee** tab, size_t size);
size_t howManyEarnLessThanMeanBonus(Employee** tab, size_t size);

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
    Employee** tab = new Employee*[4];

    tab[0] = new Developer("Kowalski", 24, 4, 5000);
    tab[1] = new Developer("Markowski", 36, 12, 8000);
    tab[2] = new TeamLeader("Nowak", 45, 24, 12000);
    tab[3] = new Developer("Stasiewicz", 20, 2, 5000);

    whoWorkMoreThan5Years(tab, 4);
    std::cout << "Powyzej sredniej premii: " << howManyEarnLessThanMeanBonus(tab, 4) << std::endl;

    for (size_t i = 0; i < 4; i++)
        delete tab[i];
    delete[] tab;

    return EXIT_SUCCESS;
}

void whoWorkMoreThan5Years(Employee** tab, size_t size) {
    for(size_t i = 0; i < size; i++) {
        Employee* emp = tab[i];
        if (emp->getExperience() > 5) {
            emp->show();
        }
    }
}

size_t howManyEarnLessThanMeanBonus(Employee** tab, size_t size) {
    float acc = 0.0;

    /**
     * I am pretty sure the assignment didn't specify what value is,
     * as well as what it should be equal to...
     */
    uint32_t test_val = 100;

    for(size_t i = 0; i < size; i++) {
        Employee* emp = tab[i];
        acc += emp->calculateBonus(test_val);
    }

    float avg = acc / size;

    size_t result = 0;
    for(size_t i = 0; i < size; i++) {
        Employee* emp = tab[i];
        if (emp->calculateBonus(test_val) > avg)
            result++;
    }

    return result;
}