#pragma once

#include <string>

// those are essential here:
class Manager; // Forward declaration of Manager class
class Employee; // Forward declaration of Employee class

class KorpoWorkers {
protected:
    std::string name;
    std::string lastname;
    double salary;

public:
    KorpoWorkers(std::string name, std::string lastname, double salary);

    virtual void IntroduceYourself() const;

    // Method to change salary
    void changeSalary(double newSalary);

    // Method to get salary
    double getSalary() const;


    // Friend function declaration (for manager class)
    friend void changeSalary(Manager& manager, Employee& employee, double newSalary);
};
