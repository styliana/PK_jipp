#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <string>
#include <vector>
#include "Product.h"

class ProductManager {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    void removeProduct(int id);
    void displayProducts() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // PRODUCTMANAGER_H
