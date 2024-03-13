#include "Member.h"

Member::Member(std::string name) : name(name), booksBorrowed(0) {}

void Member::borrowBook() {
    booksBorrowed++;
}

void Member::returnBook() {
    if (booksBorrowed > 0)
        booksBorrowed--;
}

std::string Member::getName() const {
    return name;
}

void Member::setName(std::string name) {
    this->name = name;
}

unsigned int Member::getBooksBorrowed() const {
    return booksBorrowed;
}
