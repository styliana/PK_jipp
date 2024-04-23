#pragma once
#include "Book.h"
#include <string>
#include <vector>

class Order {
public:
    std::string book_titles;
    int quantity;
    std::vector<Book> books;

public:
    Order(const std::string& book_titles, int quantity);
    Order();
    Order& operator+=(const Book& book);
    void getOrder() const;
    int calculate_total_price() const;
    void add_order();
};
