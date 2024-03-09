#include <vector>
#include "Book.h"
#include "Member.h"

class Library {
private:
    std::vector<Book> books;

public:
    Library();
    void addBook(Book b);
    void removeBook(Book b);
    void borrowBook(Member& m, std::string isbn);
    void returnBook(Member& m, std::string isbn);
    void displayBooks() const;
    int countBorrowedBooks() const;
};
