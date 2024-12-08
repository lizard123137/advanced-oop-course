#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <cstdint>
#include "employee.hpp"

using std::string, std::uint8_t, std::uint32_t;

class Developer : public Employee {
public:
    Developer(string surname, uint8_t age, uint8_t experience, uint32_t salary)
        : Employee(surname, age, experience, salary) { }
    ~Developer() {}

    virtual uint32_t calculateSalary(uint32_t value) override;
    virtual float calculateBonus(uint32_t value) const override;
};
    
uint32_t Developer::calculateSalary(uint32_t value) {
    // Not sure how to exactly calculate salary, since bonus is a float
    return this->getSalary() + static_cast<uint32_t>(this->calculateBonus(value));
}

float Developer::calculateBonus(uint32_t value) const {
    return value + 0.2 * value * (this->getSalary() + this->getExperience());
}

#endif