#include <iostream>
#include "AddressBook.h"

int main() {
    AddressBook addressBook;

    addressBook.addContact("John Crown", "12 628 29 94");
    addressBook.addContact("Vladimir Deer", "12 628 29 88");
    addressBook.addContact("Michael Valley", "510 825 521");
    addressBook.addContact("John Box", "12 628 29 94");
    addressBook.addContact("Elisabeth Shabat", "997 998 999");

    addressBook.sortAddressBook();
    addressBook.displayAddressBook();

    addressBook.searchForContact();

    addressBook.addContact();

    addressBook.sortAddressBook();
    addressBook.displayAddressBook();
    return 0;
}




/* przykładowe działanie programu
------ - MY ADDRESS BOOK------ -
Name: Elisabeth Shabat, Phone : 997 998 999
Name : John Box, Phone : 12 628 29 94
Name : John Crown, Phone : 12 628 29 94
Name : Michael Valley, Phone : 510 825 521
Name : Vladimir Deer, Phone : 12 628 29 88
------ - Search for a contact------ -
Enter first name : John
Enter last name : Box
Contact found : John Box, Phone : 12 628 29 94
------ - Add a new contact------ -
Enter first name : Jan
Enter last name : Kowalski
Enter phone number : 100200300
------ - MY ADDRESS BOOK------ -
Name : Elisabeth Shabat, Phone : 997 998 999
Name : Jan Kowalski, Phone : 100200300
Name : John Box, Phone : 12 628 29 94
Name : John Crown, Phone : 12 628 29 94
Name : Michael Valley, Phone : 510 825 521
Name : Vladimir Deer, Phone : 12 628 29 88

C : \Users\Aleksandra\Desktop\stl\x64\Debug\stl.exe(proces 23868) zakończono z kodem 0.
Naciśnij dowolny klawisz, aby zamknąć to okno...*/