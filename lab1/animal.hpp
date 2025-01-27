#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
private:
    int limbNr;
    std::string name;
    bool protectedAnimal;
public:
    Animal(int limbNr, std::string name, bool protectedAnimal = true)
        : limbNr(limbNr), name(name), protectedAnimal(protectedAnimal) { }
    Animal() { }

    int getLimbNr() { return this->limbNr; }
    void setLimbNr(int limbNr) { this->limbNr = limbNr; }

    std::string getName() { return this->name; }
    void setName(std::string name) { this->name = name; }

    bool getProtectedAnimal() { return this->protectedAnimal; }
    void setProtectedAnimal(bool protectedAnimal) { this->protectedAnimal = protectedAnimal; }

    virtual void giveVoice() {
        std::cout << "Chrum, miau, hau, piiiii" << std::endl;
    }

    virtual void info() {
        std::cout << "Animal {\n"
            << "\tNumber of limbs: " << this->limbNr << "\n"
            << "\tName: " << this->name << "\n"
            << "\tIs Protected Species: "
            << (this->protectedAnimal ? "True" : "False")
            << "}"
            << std::endl;
    }
};

#endif