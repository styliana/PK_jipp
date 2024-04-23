#include "Manager.h"
#include "Employee.h"

//Define Manager and its methods
Manager::Manager(std::string name, std::string lastname, double salary, int podwladni)
    : KorpoWorkers(name, lastname, salary), numSubordinates(podwladni) {}

//Adding to introduceyourself (originaly in korpoworkers) number of subordinates
void Manager::IntroduceYourself() const {
    KorpoWorkers::IntroduceYourself();
    std::cout << "Number of subordinates: " << numSubordinates << std::endl;
}

//---------------------------------------------- Employee's salary management

//Get the input - new salary
double Manager::GetNewSalaryFromUser() {
    double newSalary;
    std::cout << "Podaj nowe wynagrodzenie pracownika: ";
    std::cin >> newSalary;
    return newSalary;
}

// Friend function to change the salary
void changeSalary(Manager& manager, Employee& employee, double newSalary) {
    employee.changeSalary(newSalary);
}

//---------------------------------------------- number of subordinates management

void Manager::addSubordinate() {
    ++numSubordinates;
}

void Manager::deleteSubordinate() {
    --numSubordinates;
}