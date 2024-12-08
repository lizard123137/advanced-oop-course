#ifndef TEAM_LEADER_H
#define TEAM_LEADER_H

#include <iostream>
#include "employee.hpp"

using std::string, std::uint8_t, std::uint32_t;

class TeamLeader : public Employee {
public:
    TeamLeader(string surname, uint8_t age, uint8_t experience, uint32_t salary)
        : Employee(surname, age, experience, salary) { }
    ~TeamLeader() {}
    
    virtual void show() const override;
    virtual uint32_t calculateSalary(uint32_t value);

    virtual float calculateBonus(uint32_t value) const override;
};

void TeamLeader::show() const {
    std::cout << "TeamLeader[\n"
        << "\tNazwisko: " << this->getSurname() << "\n"
        << "\tWiek: " << this->getAge() << "\n"
        << "\tDoswiadczenie: " << this->getExperience() << "\n"
        << "\tPensja Bazowa: " << this->getSalary() << "\n"
        << "]\n"
        << "Jestem Team Leader z " << this->getExperience()
        << " letnim doswiadczeniem"
        << std::endl;
}

uint32_t TeamLeader::calculateSalary(uint32_t value) {
    return this->getSalary() + static_cast<uint32_t>(this->calculateBonus(value));
}

float TeamLeader::calculateBonus(uint32_t value) const {
    return value * (1 + this->getSalary() + this->getExperience());
}

#endif