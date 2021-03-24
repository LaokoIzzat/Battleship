// Name: Laoko Izzat
// Student ID: 160419328

#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Shop.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int menuInput()
{
    string inputStr;
    getline(cin, inputStr);
    int inputInt = stoi(inputStr);
    return inputInt;
}

void mainMenu()
{
    Shop s; // shop constructor has a readfromfile.
    while (true)
    {
        cout << "-------------------------------" << endl;
        cout << "           Pet Shop            " << endl;
        cout << "           Main Menu           " << endl;
        cout << "-------------------------------" << endl;
        cout << "    1. Display all pets        " << endl;
        cout << "    2. Search pets by type     " << endl;
        cout << "    3. Search pets by ID       " << endl;
        cout << "    4. Search pets by price    " << endl;
        cout << "    5. Search pets by details  " << endl;
        cout << "    6. Add a pet               " << endl;
        cout << "    7. Remove a pet            " << endl;
        cout << "    8. Exit                    " << endl;
        cout << "-------------------------------" << endl;

        cout << "Enter menu selection (1-8): " << flush;
        int input = menuInput();
        if (input == 1)
            s.displayAllPets();
        else if (input == 2)
            s.searchPetType();
        else if (input == 3)
            s.searchPetID();
        else if (input == 4)
            s.searchPetPrice();
        else if (input == 5)
            s.searchPetByDetails();
        else if (input == 6)
            s.addPet();
        else if (input == 7)
            s.removePet();
        else if (input == 8)
        {
            s.saveToFile();
            break;
        }
        else
            cout << "Invalid input, please try again." << endl;
    }
}

int main()
{
    mainMenu();
    return 0;
}
