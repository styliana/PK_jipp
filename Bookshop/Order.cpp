#include "Order.h"
#include <iostream>

Order::Order(const std::string& book_titles, int quantity) : book_titles(book_titles), quantity(quantity) {}

Order::Order() : quantity(0) {} // Implementacja domyœlnego konstruktora

Order& Order::operator+=(const Book& book) {
    books.push_back(book);
    return *this;
}

void Order::add_order() {
    std::string answer;
    std::cout << "Czy chcesz dodaæ ksi¹¿kê do zamówienia? (yes/no): " << std::endl;
    std::cin >> answer;
    while (answer == "yes" || answer == "YES") {
        // Pytanie u¿ytkownika o numer ksi¹¿ki
        int bookIndex;
        std::cout << "Podaj numer indeksu ksi¹¿ki, któr¹ chcesz dodaæ do zamówienia: ";
        std::cin >> bookIndex;
        if (bookIndex >= 1 && bookIndex <= 3) {
            *this += books[bookIndex - 1]; // U¿ywamy operatora += dla bie¿¹cego obiektu Order
        }
        else {
            std::cout << "Nieprawid³owy numer indeksu. Wybierz ponownie." << std::endl;
        }
        std::cout << "Czy chcesz dodaæ kolejn¹ ksi¹¿kê do zamówienia? (yes/no): ";
        std::cin >> answer;
    }
}

void Order::getOrder() const {
    std::cout << "Ksi¹¿ki w zamówieniu:" << std::endl;
    for (const auto& book : books) {
        std::cout << "\t" << book.title << std::endl; 
    }
}

int Order::calculate_total_price() const {
    int total_price = 0;
    for (const auto& book : books) {
        total_price += book.price;
    }
    if (total_price < 100) {
        std::cout << "Dodalismy 20$ za dostawê, poniewa¿ twoje zamówienie nie przekroczy³o 100$." << std::endl;
        return total_price+20;
    }
    else {
        return total_price;
    }

}
