#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "person.hpp"

class Student : public Person {
private:
    std::string index;

public:
    Student(std::string name, std::string surname, int age, std::string index)
        : Person(name, surname, age), index(index) {
        std::cout << "Konstruktor klasy pochodnej - Student" << std::endl;
    }

    Student() {
        std::cout << "Konstruktor bez. klasy pochodnej - Student" << std::endl;
    }

    void setIndex(std::string index) {
        this->index = index;
    }

    std::string getIndex() {
        return this->index;
    }

    void showInfoStudent() {
        this->showInfoPerson();
        std::cout << "Student {\n"
            << "\tindex: " << this->index << "\n"
            << "}"
            << std::endl;
    }
};

#endif