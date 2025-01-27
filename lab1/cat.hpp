#ifndef CAT_H
#define CAT_H

#include "animal.hpp"

class Cat : public Animal {
private:
    int levelOfMouseHunting;
    int mice[5];
public:
    Cat(int limbNr, std::string name, bool protectedAnimal)
        : Animal(limbNr, name, protectedAnimal) { }

    Cat() { }

    void initMice(int mice[5]) {
        for (int i = 0; i < 5; ++i) {
            this->mice[i] = mice[i];
        }
    }

    void initCat(int levelOfMouseHunting, int mice[5]) {
        this->levelOfMouseHunting = levelOfMouseHunting;
        this->initMice(mice);
    }

    int getLevelOfMouseHunting() { return this->levelOfMouseHunting; }
    void setLevelOfMouseHunting(int levelOfMouseHunting) { this->levelOfMouseHunting = levelOfMouseHunting; }

    int getMice(int index) {
        return this->mice[index];
    }

    void giveVoice() override {
        std::cout << "Miau miau";
    }

    void info() override {
        Animal::info();
        std::cout << "Cat {\n"
            << "\tLevel of mouse hunting skill: " << this->levelOfMouseHunting << "\n"
            << "\tMice hunted in the recent 5 years: ";

        for (auto& m : this->mice) {
            std::cout << m << ", ";
        }

        std::cout << "}" << std::endl;
    }
};

#endif