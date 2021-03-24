#include "Pet.h"
#include <iostream>
#include <string>

using namespace std;

Pet::Pet(int petAge, double petPrice, string petBreed, string petColour, string petCountryOrigin, int petID)
{
    this->petAge = petAge;
    this->petPrice = petPrice;
    this->petBreed = petBreed;
    this->petColour = petColour;
    this->petCountryOrigin = petCountryOrigin;
    this->petID = petID;
}

Pet::~Pet() = default;

int Pet::getPetID()
{
    return petID;
}

int Pet::getPetAge()
{
    return petAge;
}

double Pet::getPetPrice()
{
    return petPrice;
}

string Pet::getPetBreed()
{
    return petBreed;
}

string Pet::getPetColour()
{
    return petColour;
}

string Pet::getPetCountryOrigin()
{
    return petCountryOrigin;
}

void Pet::displayPetDetails()
{
    cout << "Pet type: " << getPetType() << endl;
    cout << "Pet ID: " << petID << endl;
    cout << "Pet Age: " << petAge << endl;
    cout << "Pet Breed: " << petBreed << endl;
    cout << "Pet Colour: " << petColour << endl;
    cout << "Pet Price: " << petPrice << endl;
}
