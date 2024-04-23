#include "AddressBook.h"
#include <algorithm>
#include <iostream>

bool compareContacts(const Contact& a, const Contact& b) {
    return a.name < b.name;
}

void AddressBook::addContact(const std::string& name, const std::string& phoneNumber) {
    contacts.push_back({ name, phoneNumber });
}

void AddressBook::addContact() {
    std::cout << "------- Add a new contact -------" << std::endl;
    std::string newFirstName, newLastName, phoneNumber;
    std::cout << "Enter first name: ";
    std::cin >> newFirstName;
    std::cout << "Enter last name: ";
    std::cin >> newLastName;
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;

    addContact(newFirstName + " " + newLastName, phoneNumber);
}

void AddressBook::sortAddressBook() {
    std::sort(contacts.begin(), contacts.end(), compareContacts);
}

void AddressBook::displayAddressBook() const {
    std::cout << "------- MY ADDRESS BOOK -------" << std::endl;
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << std::endl;
    }
}

void AddressBook::searchForContact() {
    std::cout << "------- Search for a contact -------" << std::endl;
    std::string firstName, lastName;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;

    searchContact(firstName + " " + lastName);
}

void AddressBook::searchContact(const std::string& fullName) const {
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name == fullName) {
            std::cout << "Contact found: " << contact.name << ", Phone: " << contact.phoneNumber << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Contact not found." << std::endl;
    }
}
