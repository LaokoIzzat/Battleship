#ifndef PET_H
#define PET_H
#include <string>

class Pet
{
public:
    Pet(int petAge, double petPrice, std::string petBreed, std::string petColour, std::string petCountryOrigin, int petID);
    ~Pet();
    int getPetID();
    int getPetAge();
    double getPetPrice();
    std::string getPetBreed();
    std::string getPetColour();
    std::string getPetCountryOrigin();
    virtual void displayPetDetails();
    virtual std::string getPetType() = 0;

private:
    int petID, petAge;
    double petPrice;
    std::string petBreed, petColour, petCountryOrigin;
};

#endif