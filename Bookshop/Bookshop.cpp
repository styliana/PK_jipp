#include <iostream>
#include <string>
#include "Book.h"
#include "Order.h"
#include <clocale>
#include <iomanip>

using namespace std;

int main() {
    //Polish znaki
    setlocale(LC_ALL, "");

    // Inicjalizacja ksi¹¿ek
    Book books[3] = {
        Book("ABC", 45),
        Book("DEF", 10),
        Book("GHI", 22)
    };

    // Tworzenie zamówienia
    Order order;

    // Wyœwietlanie dostêpnych ksi¹¿ek z numerami indeksów
    std::cout << "-----------------------" << std::endl;
    std::cout << "Nr   Tytu³      Cena" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << ".   " << std::setw(10) << std::left << books[i].title << " " << std::setw(2) << books[i].price << " $" << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    string answer;
    cout << "Czy chcesz dodaæ ksi¹¿kê do zamówienia? (yes/no): " << endl;
    cin >> answer;
    while (answer == "yes" || answer == "YES") {

        // Pytanie u¿ytkownika o numer ksi¹¿ki
        int bookIndex;
        cout << "Podaj numer ksiazki, ktora chcesz dodac do zamowienia: ";
        cin >> bookIndex;

        // Dodanie odpowiedniej ksi¹¿ki do zamówienia na podstawie numeru indeksu
        if (bookIndex >= 1 && bookIndex <= 3) {
            order += books[bookIndex - 1];
        }
        else {
            cout << "Nieprawidlowy numer indeksu. Wybierz ponownie." << endl;
        }

        cout << "Czy chcesz dodaæ ksi¹¿kê do zamówienia? (yes/no): " << endl;
        cin >> answer;
    }

    std::cout << "-----------------------" << std::endl;
    // Wyœwietlanie zamówienia po zakoñczeniu sk³adania
    order.getOrder();
    std::cout << "-----------------------" << std::endl;
    // Wyœwietlanie ca³kowitego kosztu zamówienia
    cout << "Ca³kowity koszt zamówienia: " << order.calculate_total_price() << " $" << endl;

    return 0;
}

/* output

-----------------------
Nr   Tytu³      Cena
1.   ABC        45 $
2.   DEF        10 $
3.   GHI        22 $
-----------------------
Czy chcesz dodaæ ksi¹¿kê do zamówienia? (yes/no):
yes
Podaj numer ksiazki, ktora chcesz dodac do zamowienia: 1
Czy chcesz dodaæ ksi¹¿kê do zamówienia? (yes/no):
yes
Podaj numer ksiazki, ktora chcesz dodac do zamowienia: 3
Czy chcesz dodaæ ksi¹¿kê do zamówienia? (yes/no):
yes
Podaj numer ksiazki, ktora chcesz dodac do zamowienia: 2
Czy chcesz dodaæ ksi¹¿kê do zamówienia? (yes/no):
no
-----------------------
Ksi¹¿ki w zamówieniu:
        ABC
        GHI
        DEF
-----------------------
Dodalismy 20$ za dostawê, poniewa¿ twoje zamówienie nie przekroczy³o 100$.
Ca³kowity koszt zamówienia: 97 $



A:\jipp2\Bookshop\x64\Debug\Bookshop.exe (proces 2436) zakoñczono z kodem 0.
Naciœnij dowolny klawisz, aby zamkn¹æ to okno...
*/