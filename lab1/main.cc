#include <iostream>

#include "person.hpp"
#include "student.hpp"
#include "teacher.hpp"

int main() {
    // 1.1
    std::cout << "Obiekt klasy Person" << std::endl;
    Person person("Grazyna", "Nowak", 45);
    person.showInfoPerson();
    std::cout << "Osoba "
        << person.getSurname()
        << " Jest pelnoletnia: "
        << (person.is_18() ? "Tak" : "Nie")
        << std::endl;
    person.setAge(16);

    std::cout << "Obiekt klasy Teacher" << std::endl;
    Teacher teacher("Barbara", "Kowalska", 56, 30, "Phd");
    teacher.showInfoTeacher();
    std::cout << "Czy "
        << teacher.getSurname()
        << " ma Phd: "
        << (teacher.is_phd() ? "Tak" : "Nie")
        << std::endl;
    teacher.setAge(34);

    Person people_array_1[3];
    Person* people_array_2;
    Person* people_array_3[3];
    Person** people_array_4;

    // Static array
    for(int i = 0; i < 3; ++i) {
        people_array_1[i].init("Anna", "Nowak", 20 + i);
        people_array_1[i].showInfoPerson();
    }

    // Allocating memory for entire array
    people_array_2 = new Person[3];
    for(int i = 0; i < 3; ++i) {
        people_array_2[i].init("Ola", "Adamek", 20 + i);
        people_array_2[i].showInfoPerson();
    }

    // Allocating each person separately
    for(int i = 0; i < 3; ++i) {
        people_array_3[i] = new Person("Kasia", "Kowalska", 20 + i);
        people_array_3[i]->showInfoPerson();
    }

    // Allocating an array of pointers to allocated elements
    people_array_4 = new Person*[3];
    for(int i = 0; i < 3; ++i) {
        people_array_4[i] = new Person("Pawel", "Wojcik", 20 + i);
        people_array_4[i]->showInfoPerson();
    }

    for(int i = 0; i < 3; ++i) {
        delete people_array_3[i];
    }

    for(int i = 0; i < 3; ++i) {
        delete people_array_4[i];
    }
    delete[] people_array_4;

    // Creating the arrays for class Student
    Student students_array_1[3];
    Student* students_array_2;
    Student* students_array_3[3];
    Student** students_array_4;

    // Static array
    for(int i = 0; i < 3; ++i) {
        students_array_1[i].init("Anna", "Nowak", 20 + i);
        students_array_1[i].setIndex("99532");
        students_array_1[i].showInfoStudent();
    }

    // Allocating memory for entire array
    students_array_2 = new Student[3];
    for(int i = 0; i < 3; ++i) {
        students_array_2[i].init("Ola", "Adamek", 20 + i);
        students_array_2[i].setIndex("99532");
        students_array_2[i].showInfoStudent();
    }

    // Allocating each person separately
    for(int i = 0; i < 3; ++i) {
        students_array_3[i] = new Student("Kasia", "Kowalska", 20 + i, "99532");
        students_array_3[i]->showInfoStudent();
    }

    // Allocating an array of pointers to allocated elements
    students_array_4 = new Student*[3];
    for(int i = 0; i < 3; ++i) {
        students_array_4[i] = new Student("Pawel", "Wojcik", 20 + i, "99532");
        students_array_4[i]->showInfoStudent();
    }

    for(int i = 0; i < 3; ++i) {
        delete students_array_3[i];
    }

    for(int i = 0; i < 3; ++i) {
        delete students_array_4[i];
    }
    delete[] students_array_4;

    return EXIT_SUCCESS;
}