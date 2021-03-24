#ifndef DOG_H
#define DOG_H
#include "Pet.h"
#include <string>

class Dog : public Pet
{
public:
    Dog(bool isNeutered, bool isVaccinated, int petAge, double petPrice, std::string dogBreed, std::string dogColour, std::string dogCountryOrigin, int petID);
    std::string getPetType();
    void displayPetDetails();
    bool getIsNeutered();
    bool getIsVaccinated();

private:
    bool isNeutered, isVaccinated;
};

#endif