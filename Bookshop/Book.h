#pragma once
#include <string>

class Book {
public:
    Book(const std::string& t, int p) : title(t), price(p) {}
    std::string title;
    int price;
};
