#ifndef BIRD_H
#define BIRD_H
#include "Pet.h"
#include <string>

class Bird : public Pet
{
public:
    Bird(bool hasCouncilLicence, int petAge, double petPrice, std::string birdBreed, std::string birdColour, std::string birdCountryOrigin, int petID);
    std::string getPetType();
    void displayPetDetails();
    bool getIsCouncilLicenced();

private:
    bool hasCouncilLicence;
};

#endif