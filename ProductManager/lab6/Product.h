#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;

public:
    Product() : id(0), name(""), price(0.0) {} // Konstruktor domyœlny
    Product(int id, const std::string& name, double price);
    int getId() const;
    std::string getName() const;
    double getPrice() const;
};

#endif // PRODUCT_H
