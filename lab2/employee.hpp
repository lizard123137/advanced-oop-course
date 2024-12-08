#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstdint>
#include <iostream>
#include <string>

using std::string, std::uint8_t;

class Employee {
private:
    string surname;
    uint8_t age;
    uint8_t experience;
    uint32_t salary;
public:
    Employee(string surname, uint8_t age, uint8_t experience, uint32_t salary)
        : surname(surname), age(age), experience(experience), salary(salary) { }
    Employee();
    virtual ~Employee() {}

    virtual void show() const;
    virtual float calculateBonus(uint32_t value) const = 0;
    virtual uint32_t calculateSalary(uint32_t value) = 0;

    uint8_t ageEmployment() const;

    string getSurname() const;
    void setSurname(string surname);
    uint8_t getAge() const;
    void setAge(uint8_t age);
    uint8_t getExperience() const;
    void setExperience(uint8_t experience);
    uint32_t getSalary() const;
    void setSalary(uint32_t salary);
};

void Employee::show() const {
    std::cout << "Pracownik [\n"
        << "\tNazwisko: " << this->getSurname() << "\n"
        << "\tWiek: " << this->getAge() << "\n"
        << "\tDoswiadczenie: " << this->getExperience() << "\n"
        << "\tPensja: " << this->getSalary()
        << std::endl;
}

uint8_t Employee::ageEmployment() const {
    return this->getAge() - this->getExperience();
}

string Employee::getSurname() const {
    return this->surname;
}

void Employee::setSurname(string surname) {
    this->surname = surname;
}

uint8_t Employee::getAge() const {
    return this->age;
}

void Employee::setAge(uint8_t age) {
    this->age = age;
}

uint8_t Employee::getExperience() const {
    return this->experience;
}

void Employee::setExperience(uint8_t experience) {
    this->experience = experience;
}

uint32_t Employee::getSalary() const {
    return this->salary;
}

void Employee::setSalary(uint32_t salary) {
    this->salary = salary;
}

#endif