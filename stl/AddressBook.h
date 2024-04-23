#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <vector>
#include "Contact.h"

class AddressBook {
public:
    void addContact(const std::string& name, const std::string& phoneNumber);
    void sortAddressBook();
    void displayAddressBook() const;
    void searchForContact();
    void addContact();
    void searchContact(const std::string& fullName) const;

private:
    std::vector<Contact> contacts;
};

#endif // ADDRESSBOOK_H
