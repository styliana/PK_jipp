#include "Book.h"
#include <iostream>

Book::Book(std::string title, std::string author, std::string isbn)
    : title(title), author(author), isbn(isbn), available(true) {}

Book::~Book() {
    //std::cout << "Niszczê ksi¹¿kê" << std::endl;
}

void Book::getInfo() const {
    std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << ", Available: " << (available ? "Yes" : "No") << std::endl;
}

std::string Book::getTitle() const {
    return title;
}

void Book::setTitle(std::string title) {
    this->title = title;
}

std::string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(std::string author) {
    this->author = author;
}

std::string Book::getISBN() const {
    return isbn;
}

void Book::setISBN(std::string isbn) {
    this->isbn = isbn;
}

bool Book::isAvailable() const {
    return available;
}

void Book::setAvailable(bool available) {
    this->available = available;
}
