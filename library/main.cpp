#include <iostream>
#include "Library.h"
#include <clocale>

int main() {
    std::setlocale(LC_ALL, "Polish");

    Library library;

    // Dodanie kilku ksi¹¿ek
    library.addBook(Book("Harry Potter", "J.K. Rowling", "123"));
    library.addBook(Book("The Hobbit", "J.R.R. Tolkien", "456"));
    library.addBook(Book("1984", "George Orwell", "789"));

    // Wyœwietlenie dostêpnych ksi¹¿ek
    std::cout << "Dostêpne ksi¹¿ki:" << std::endl;
    library.displayBooks();

    // Utworzenie kilku czytelników
    std::string userName;
    std::cout << "Podaj swoje imiê: ";
    std::cin >> userName;
    Member member(userName);

    // Wypo¿yczenie ksi¹¿ek
    std::string isbn;
    std::cout << "Podaj numer ISBN ksi¹¿ki do wypo¿yczenia: ";
    std::cin >> isbn;
    library.borrowBook(member, isbn);

    // Wyœwietlenie dostêpnych ksi¹¿ek po wypo¿yczeniu
    std::cout << "Dostêpne ksi¹¿ki po wypo¿yczeniu:" << std::endl;
    library.displayBooks();

    // Zwrot ksi¹¿ek
    std::cout << "Podaj numer ISBN ksi¹¿ki do zwrotu: ";
    std::cin >> isbn;
    library.returnBook(member, isbn);

    // Wyœwietlenie dostêpnych ksi¹¿ek po zwrocie
    std::cout << "Dostêpne ksi¹¿ki po zwrocie:" << std::endl;
    library.displayBooks();

    // Wyœwietlenie liczby wypo¿yczonych ksi¹¿ek
    std::cout << userName << "Liczba wypo¿yczonych ksi¹¿ek: " << (-(32 -library.countBorrowedBooks())) << std::endl;

    return 0;
}
