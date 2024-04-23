#include "KorpoWorkers.h"
#include <iostream>

// ofc constructor
KorpoWorkers::KorpoWorkers(std::string name, std::string lastname, double salary)
    : name(name), lastname(lastname), salary(salary) {}

// Implementation of the IntroduceYourself function
void KorpoWorkers::IntroduceYourself() const {
    std::cout << "Hello, I'm " << name << " " << lastname << ". My salary is $" << salary << "." << std::endl;
}

// Implementation of the changeSalary function
void KorpoWorkers::changeSalary(double newSalary) {
    salary = newSalary;
}

// Implementation of the getSalary function
double KorpoWorkers::getSalary() const {
    return salary; // Returns the salary value
}
