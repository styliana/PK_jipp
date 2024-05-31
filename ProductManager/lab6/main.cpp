#include <iostream>
#include "Product.h"
#include "ProductManager.h"

int main() {
    ProductManager manager;
    setlocale(LC_ALL, "polish");

    try {
        // Dodaj kilka produktów
        manager.addProduct(Product(1, "Żywiec", 55));
        manager.addProduct(Product(2, "Perła", 4));
        manager.addProduct(Product(3, "Heineken", 5));

        // Wyświetl produkty
        std::cout << "Products:" << std::endl;
        manager.displayProducts();

        // Zapisz produkty do pliku
        manager.saveToFile("products.bin");

        // Usuń produkt o ID 2
        manager.removeProduct(2);

        // Wyświetl produkty po usunięciu
        std::cout << "\nProducts after removal:" << std::endl;
        manager.displayProducts();

        // Wczytaj produkty z pliku
        manager.loadFromFile("products.bin");

        // Wyświetl produkty po wczytaniu z pliku
        std::cout << "\nProducts after loading from file:" << std::endl;
        manager.displayProducts();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
