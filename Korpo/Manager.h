#pragma once

#include "KorpoWorkers.h"
#include <iostream>

class Employee; // Forward declaration is needed

class Manager : public KorpoWorkers {
private:
    int numSubordinates;

public:
    Manager(std::string name, std::string lastname, double salary, int podwladni);

    void IntroduceYourself() const override;

    // Function adding subordinate
    void addSubordinate();

    // Function deleting subordinate
    void deleteSubordinate();

    // Friend function changing employee's salary
    friend void changeSalary(Manager& manager, Employee& employee, double newSalary);
    double GetNewSalaryFromUser();
};
