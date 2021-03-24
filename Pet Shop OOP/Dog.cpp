#include "Dog.h"
#include <iostream>
#include <string>

using namespace std;

Dog::Dog(bool isNeutered, bool isVaccinated, int petAge, double petPrice, string dogBreed, string dogColour, string dogCountryOrigin, int petID) : Pet(petAge, petPrice, dogBreed, dogColour, dogCountryOrigin, petID)
{
    this->isNeutered = isNeutered;
    this->isVaccinated = isVaccinated;
}

string Dog::getPetType()
{
    return "Dog";
}

void Dog::displayPetDetails()
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

bool Dog::getIsVaccinated()
{
    return isVaccinated;
}

bool Dog::getIsNeutered()
{
    return isNeutered;
}