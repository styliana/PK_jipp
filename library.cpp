#include "Library.h"
#include <iostream>

Library::Library() : books(32) {}

void Library::addBook(Book b) {
    bool spaceAvailable = false;
    for (const auto& book : books) {
        if (book.getISBN().empty()) {
            spaceAvailable = true;
            break;
        }
    }

    if (spaceAvailable) {
        books.push_back(b);
    }
}

void Library::displayBooks() const {
    bool anyBooks = false;
    for (const auto& book : books) {
        if (!book.getISBN().empty()) {
            anyBooks = true;
            book.getInfo();
        }
    }
    if (!anyBooks) {
        std::cout << "Brak dostêpnych ksi¹¿ek.\n" << std::endl;
    }
}



void Library::removeBook(Book b) {
    for (auto& book : books) {
        if (book.getISBN() == b.getISBN()) {
            book = Book("", "", ""); // clear book data
            return;
        }
    }
    std::cout << "Ksi¹¿ka nie zosta³a znaleziona.\n" << std::endl;
}

void Library::borrowBook(Member& m, std::string isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn && book.isAvailable()) {
            book.setAvailable(false);
            m.borrowBook();
            std::cout << "Ksi¹¿ka zosta³a po¿yczona.\n" << std::endl;
            return;
        }
    }
    std::cout << "Ksi¹¿ka o podanym ISBN nie jest dostêpna.\n" << std::endl;
}

void Library::returnBook(Member& m, std::string isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn && !book.isAvailable()) {
            book.setAvailable(true);
            m.returnBook();
            std::cout << "Ksi¹¿ka zosta³a zwrócona.\n" << std::endl;
            return;
        }
    }
    std::cout << "Ksi¹¿ka o podanym ISBN nie zosta³a po¿yczona przez tego u¿ytkownika.\n" << std::endl;
}

int Library::countBorrowedBooks() const {
    int borrowedCount = 0;
    for (const auto& book : books) {
        if (!book.isAvailable()) {
            borrowedCount++;
        }
    }
    return borrowedCount;
}
