#ifndef CAT_H
#define CAT_H
#include "Pet.h"
#include <string>

class Cat : public Pet
{
public:
    Cat(bool isNeutered, bool isVaccinated, int petAge, double petPrice, std::string catBreed, std::string catColour, std::string catCountryOrigin, int petID);
    std::string getPetType();
    void displayPetDetails();
    bool getIsNeutered();
    bool getIsVaccinated();

private:
    bool isNeutered, isVaccinated;
};

#endif