#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
private:
    std::string name;
    std::string surname;
    int age;
public:
    Person(std::string name, std::string surname, int age)
        : name(name), surname(surname), age(age) {
        std::cout << "Konstruktor klasy bazowej - Person" << std::endl;
    }

    Person() {
        std::cout << "Konstruktor bez. klasy bazowej - Person" << std::endl;
    }

    void setAge(int age) {
        this->age = age;
    }

    std::string getSurname() {
        return this->surname;
    }

    bool is_18() {
        return age >= 18;
    }

    void showInfoPerson() {
        std::cout << "Person {\n"
            << "\tImie: " << this->name << "\n"
            << "\tNazwisko: " << this->surname << "\n"
            << "\tWiek: " << this->age << "\n"
            << "}"
            << std::endl;
    }

    void init(std::string name, std::string surname, int age) {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }
};

#endif