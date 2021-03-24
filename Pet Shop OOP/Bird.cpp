#include "Bird.h"
#include <iostream>
#include <string>

using namespace std;

Bird::Bird(bool hasCouncilLicence, int petAge, double petPrice, string birdBreed, string birdColour, string birdCountryOrigin, int petID) : Pet(petAge, petPrice, birdBreed, birdColour, birdCountryOrigin, petID)
{
    this->hasCouncilLicence = hasCouncilLicence;
}

string Bird::getPetType()
{
    return "Bird";
}

void Bird::displayPetDetails()
{
    cout << "Pet type: " << getPetType() << ", " << flush;
    cout << "Pet ID: " << getPetID() << ", " << flush;
    cout << "Pet Age: " << getPetAge() << ", " << flush;
    cout << "Pet Breed: " << getPetBreed() << ", " << flush;
    cout << "Pet Colour: " << getPetColour() << ", " << flush;
    cout << "Pet Country Origin: " << getPetCountryOrigin() << ", " << flush;
    cout << "Pet Price: " << getPetPrice() << ", " << flush;
    cout << "Council Licence: " << (hasCouncilLicence ? "Yes" : "No") << endl;
}

bool Bird::getIsCouncilLicenced()
{
    return hasCouncilLicence;
}