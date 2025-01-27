#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "animal.hpp"

enum SkillType {
    SKILL_GUIDE,
    SKILL_TRACKER,
};

class Dog : public Animal {
private:
    std::string breed;
    int levelOfGuideSkills;
    int levelOfTrackerSkills;
public:
    Dog(
        int limbNr,
        std::string name,
        bool protectedAnimal,
        std::string breed,
        int levelOfGuideSkills,
        int levelOfTrackerSkills
    ) : Animal(limbNr, name, protectedAnimal),
        breed(breed),
        levelOfGuideSkills(levelOfGuideSkills),
        levelOfTrackerSkills(levelOfTrackerSkills) { }
    
    Dog(int limbNr, std::string name, bool protectedAnimal)
        : Animal(limbNr, name, protectedAnimal) { }

    Dog() { }
    
    int getSkillLevel(int type) {
        switch(type) {
            case SkillType::SKILL_GUIDE:
                return this->levelOfGuideSkills;
            case SkillType::SKILL_TRACKER:
                return this->levelOfTrackerSkills;
            default:
                return -1;
        }
    }

    void setSkillLevel(int type, int value) {
        switch(type) {
            case SkillType::SKILL_GUIDE:
                this->levelOfGuideSkills = value;
            case SkillType::SKILL_TRACKER:
                this->levelOfTrackerSkills = value;
        }
    }

    void giveVoice() override {
        std::cout << "Hau, hau" << std::endl;
    }

    void info() override {
        Animal::info();
        std::cout << "Dog {\n"
            << "\tBreed: " << this->breed << "\n"
            << "\tLevel of guide skill: " << this->levelOfGuideSkills << "\n"
            << "\tLevel of tracker skill: " << this->levelOfTrackerSkills << "\n"
            << "}"
            << std::endl;
    }
};

#endif