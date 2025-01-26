#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include "person.hpp"

class Teacher : public Person {
private:
    int experience;
    std::string title;
public:
    Teacher(
        std::string name,
        std::string surname,
        int age,
        int experience,
        std::string title
    ) : Person(name, surname, age),
        experience(experience),
        title(title) {
        std::cout << "Konstruktor klasy pochodnej - Teacher" << std::endl;
    }

    Teacher() {
        std::cout << "Konstruktor bez. klasy pochodnej - Teacher" << std::endl;
    }

    void setTitle(std::string title) {
        this->title = title;
    }

    int getExperience() {
        return this->experience;
    }

    bool is_phd() {
        return this->title == "Phd";
    }

    void showInfoTeacher() {
        this->showInfoPerson();
        std::cout << "Teacher {\n"
            << "\tStaz pracy: " << this->experience << "\n"
            << "\tTytul naukowy: " << this->title << "\n"
            << "}"
            << std::endl;
    }
};

#endif