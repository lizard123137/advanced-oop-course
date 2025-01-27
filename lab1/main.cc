#include <iostream>

#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "person.hpp"
#include "student.hpp"
#include "teacher.hpp"

int howManyProtectedAnimals(Animal animals[], int size) {
    int acc = 0;

    for(int i = 0; i < size; ++i) {
        acc += animals[i].getProtectedAnimal();
    }

    return acc;
}

int howManyTrackerDogs(Dog dogs[], int size) {
    int acc = 0;

    for(int i = 0; i < size; ++i) {
        int tracker = dogs[i].getSkillLevel(SkillType::SKILL_TRACKER);
        int guide = dogs[i].getSkillLevel(SkillType::SKILL_GUIDE);

        acc += (tracker > guide);
    }

    return acc;
}

void howManyCats(Cat cats[], int size) {
    for(int i = 0; i < size; ++i) {
        int acc = 0;

        for(int j = 0; j < 5; ++j) {
            acc += cats[i].getMice(j);
        }

        std::cout << "Cat nr. "
            << i + 1
            << " has hunted "
            << acc
            << " mice in the last 5 years"
            << std::endl;
    }
}

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

    // 1.2
    Animal animals[5];
    animals[0] = Animal(4, "Zebra", true);
    animals[1] = Animal(4, "Kangur", true);
    animals[2] = Animal(4, "Slon", true);
    animals[3] = Animal(4, "Krowa", false);
    animals[4] = Animal(4, "Pies", false);

    std::cout << "Ilosc chronionych zwierzat: "
        << howManyProtectedAnimals(animals, 5)
        << std::endl;

    Dog dogs[3];
    dogs[0] = Dog(4, "Dog", false, "Poodle", 4, 6);
    dogs[1] = Dog(4, "Dog", false, "Pitbull", 6, 2);
    dogs[2] = Dog(4, "Dog", false, "Golden Retriever", 5, 8);

    std::cout << "Ilosc psow szukajacych: "
        << howManyTrackerDogs(dogs, 3)
        << std::endl;

    Cat cats[3];
    cats[0] = Cat(4, "Cat", false);
    cats[1] = Cat(4, "Cat", false);
    cats[2] = Cat(4, "Cat", false);
    int mice0[] = { 1, 1, 1, 1, 1 };
    int mice1[] = { 2, 2, 2, 2, 2 };
    int mice2[] = { 3, 3, 3, 3, 3 };
    cats[0].initCat(4, mice0);
    cats[1].initCat(4, mice1);
    cats[2].initCat(4, mice2);

    howManyCats(cats, 3);

    return EXIT_SUCCESS;
}