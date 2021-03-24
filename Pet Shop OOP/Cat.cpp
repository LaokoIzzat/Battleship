#include "Cat.h"
#include <iostream>
#include <string>

using namespace std;

Cat::Cat(bool isNeutered, bool isVaccinated, int petAge, double petPrice, string catBreed, string catColour, string catCountryOrigin, int petID) : Pet(petAge, petPrice, catBreed, catColour, catCountryOrigin, petID)
{
    this->isNeutered = isNeutered;
    this->isVaccinated = isVaccinated;
}

string Cat::getPetType()
{
    return "Cat";
}

void Cat::displayPetDetails()
{
    cout << "Pet type: " << getPetType() << ", " << flush;
    cout << "Pet ID: " << getPetID() << ", " << flush;
    cout << "Pet Age: " << getPetAge() << ", " << flush;
    cout << "Pet Breed: " << getPetBreed() << ", " << flush;
    cout << "Pet Colour: " << getPetColour() << ", " << flush;
    cout << "Pet Country Origin: " << getPetCountryOrigin() << ", " << flush;
    cout << "Pet Price: " << getPetPrice() << ", " << flush;
    cout << "Neutered: " << (isNeutered ? "Yes" : "No") << ", " << flush;
    cout << "Vaccinated: " << (isVaccinated ? "Yes" : "No") << endl;
}

bool Cat::getIsVaccinated()
{
    return isVaccinated;
}

bool Cat::getIsNeutered()
{
    return isNeutered;
}