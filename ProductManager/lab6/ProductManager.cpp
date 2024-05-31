#include "ProductManager.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

Product::Product(int id, const std::string& name, double price)
    : id(id), name(name), price(price) {}

int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void ProductManager::addProduct(const Product& product) {
    for (const auto& p : products) {
        if (p.getId() == product.getId()) {
            throw std::invalid_argument("Product with the same ID already exists.");
        }
    }
    products.push_back(product);
}

void ProductManager::removeProduct(int id) {
    auto it = std::find_if(products.begin(), products.end(), [id](const Product& p) {
        return p.getId() == id;
        });

    if (it != products.end()) {
        products.erase(it);
    }
    else {
        throw std::invalid_argument("Product with the given ID does not exist.");
    }
}

void ProductManager::displayProducts() const {
    for (const auto& product : products) {
        std::cout << "ID: " << product.getId() << ", Name: " << product.getName() << ", Price: " << product.getPrice() << std::endl;
    }
}

void ProductManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Unable to open file for writing.");
    }

    for (const auto& product : products) {
        int id = product.getId();
        file.write(reinterpret_cast<const char*>(&id), sizeof(int)); // Write ID

        int nameLength = static_cast<int>(product.getName().length());
        file.write(reinterpret_cast<const char*>(&nameLength), sizeof(int)); // Write name length
        file.write(product.getName().c_str(), nameLength); // Pass the address of the string's buffer


        double price = product.getPrice();
        file.write(reinterpret_cast<const char*>(&price), sizeof(double)); // Write price

        if (!file) {
            throw std::runtime_error("Error occurred while writing to file.");
        }
    }
    file.close();
}

void ProductManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Unable to open file for reading.");
    }

    products.clear(); // Clear the vector before loading from the file

    while (true) {
        int id = 0; // Initialize ID
        if (!file.read(reinterpret_cast<char*>(&id), sizeof(int))) {
            break; // If unable to read ID, end loading
        }

        int nameLength = 0; // Initialize name length
        file.read(reinterpret_cast<char*>(&nameLength), sizeof(int)); // Read name length
        if (nameLength <= 0 || nameLength > 100) {
            throw std::runtime_error("Invalid name length.");
        }
        char nameBuffer[101] = { 0 }; // Initialize buffer for name
        file.read(nameBuffer, nameLength); // Read name
        std::string name(nameBuffer); // Convert to std::string

        double price = 0.0; // Initialize price
        file.read(reinterpret_cast<char*>(&price), sizeof(double)); 

        products.emplace_back(id, name, price); 
    }

    file.close();
}
