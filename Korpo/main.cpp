#include <iostream>
#include <string>
#include "Manager.h"
#include "Employee.h"
#include "Intern.h"

// Function prototype for changing salary
void changeSalary(Manager& manager, Employee& employee, double newSalary);

int main() {
    // Set Polish locale
    setlocale(LC_ALL, "polish");

    // Create objects
    Manager manager("Jakub", "Dolina", 5000, 10);
    Employee emp("Jasiu", "Dec", 3000);
    Intern intern("Micha³", "Koroñski");

    // Display initial message
    std::cout << "Welcome to the corporation!\n\nThe manager has 10 subordinates by default." << std::endl;

    // Prompt user for adding or deleting subordinates
    std::string decision;
    std::cout << "Do you want to add a subordinate? (yes/no): ";
    std::cin >> decision;

    if (decision == "yes") {
        manager.addSubordinate(); // Add a subordinate
    }

    std::cout << "Do you want to delete a subordinate? (yes/no): ";
    std::cin >> decision;

    if (decision == "yes") {
        manager.deleteSubordinate(); // Delete a subordinate
    }

    std::cout << "-----------------------------------------------";

    // Display information about objects
    std::cout << std::endl << "Manager:" << std::endl;
    manager.IntroduceYourself();

    std::cout << std::endl << "Employee:" << std::endl;
    emp.IntroduceYourself();

    std::cout << std::endl << "Intern:" << std::endl;
    intern.IntroduceYourself();

    std::cout << "-----------------------------------------------";

    // Prompt manager for new employee salary
    std::cout << std::endl << "Hi manager! Give a new salary for a regular employee: ";
    double new_emp_salary;
    std::cin >> new_emp_salary;
    changeSalary(manager, emp, new_emp_salary); // Change employee salary

    std::cout << std::endl << "Employee:" << std::endl;
    emp.IntroduceYourself(); // Display updated employee information

    return 0;
}

/*
* 
Welcome to the corporation!

The manager has 10 subordinates by default.
Do you want to add a subordinate ? (yes / no) : yes
Do you want to delete a subordinate ? (yes / no) : no
---------------------------------------------- -
Manager :
Hello, I'm Jakub Dolina. My salary is $5000.
Number of subordinates : 11

Employee :
Hello, I'm Jasiu Dec. My salary is $3000.

Intern :
Hello, I'm Micha³ Koroñski. My salary is $0.
---------------------------------------------- -
Hi manager!Give a new salary for a regular employee : 4500

Employee :
Hello, I'm Jasiu Dec. My salary is $4500.


A : \jipp2\Korpo\x64\Debug\Korpo.exe(proces 4804) zakoñczono z kodem 0.
Naciœnij dowolny klawisz, aby zamkn¹æ to okno...'
*/