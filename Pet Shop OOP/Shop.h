#ifndef SHOP_H
#define SHOP_H

#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include <vector>
#include <string>

class Shop
{
public:
    Shop();
    ~Shop();
    void addPet();
    void removePet();
    void displayAllPets();
    void searchPetType();
    void searchPetID();
    void searchPetPrice();
    void searchPetByDetails();
    void readFromFile();
    void saveToFile();
    int getMaxId();

private:
    std::vector<Dog *> dogs;
    std::vector<Cat *> cats;
    std::vector<Bird *> birds;
};

#endif