#include "Shop.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Shop::Shop()
{
    std::vector<Dog *> dogs;
    std::vector<Cat *> cats;
    std::vector<Bird *> birds;
    Shop::readFromFile();
}

Shop::~Shop()
{
    for (Dog *d : dogs)
    {
        delete d;
    }
    for (Cat *c : cats)
    {
        delete c;
    }
    for (Bird *b : birds)
    {
        delete b;
    }
}

void Shop::searchPetID()
{
    bool found = false;

    cout << "-------------------------------" << endl;
    cout << "Enter a pet ID to search for: " << flush;
    string inputStr;
    getline(cin, inputStr);
    int inputInt = stoi(inputStr);

    for (Dog *d : dogs)
    {
        if (inputInt == d->getPetID())
        {
            found = true;
            d->displayPetDetails();
            cout << "-------------------------------" << endl;
        }
    }
    if (found != true)
    {
        for (Cat *c : cats)
        {
            if (inputInt == c->getPetID())
            {
                found = true;
                c->displayPetDetails();
                cout << "-------------------------------" << endl;
            }
        }
    }
    if (found != true)
    {
        for (Bird *b : birds)
        {
            if (inputInt == b->getPetID())
            {
                found = true;
                b->displayPetDetails();
                cout << "-------------------------------" << endl;
            }
        }
    }

    if (found == false)
        cout << "We do not currently have a pet with this ID." << endl; // ERROR CHECKING NEEDED.
}

void Shop::searchPetPrice()
{
    cout << "-------------------------------" << endl;
    bool found = false;
    double lower_bound;
    double upper_bound;

    cout << "Enter lower bound of price range: " << flush;
    string inputStr1;
    getline(cin, inputStr1);
    lower_bound = stod(inputStr1);

    cout << "Enter upper bound of price range: " << flush;
    string inputStr2;
    getline(cin, inputStr2);
    lower_bound = stod(inputStr2);

    for (Dog *d : dogs)
    {
        if (d->getPetPrice() >= lower_bound && d->getPetPrice() <= upper_bound)
        {
            found = true;
            d->displayPetDetails();
            cout << "-------------------------------" << endl;
        }
    }

    for (Cat *c : cats)
    {
        if (c->getPetPrice() >= lower_bound && c->getPetPrice() <= upper_bound)
        {
            found = true;
            c->displayPetDetails();
            cout << "-------------------------------" << endl;
        }
    }

    for (Bird *b : birds)
    {
        if (b->getPetPrice() >= lower_bound && b->getPetPrice() <= upper_bound)
        {
            found = true;
            b->displayPetDetails();
            cout << "-------------------------------" << endl;
        }
    }

    if (found == false)
        cout << "We do not currently have any pets within this price range." << endl;
}

void Shop::searchPetType()
{
    bool found = false;
    cout << "-------------------------------" << endl;
    cout << "1. Dog" << endl;
    cout << "2. Cat" << endl;
    cout << "3. Bird" << endl;
    cout << "Enter the number for the above pet type that you would like to check for: " << flush;

    string inputStr;
    getline(cin, inputStr);
    int inputInt = stoi(inputStr);

    if (inputInt == 1)
    {
        for (Dog *d : dogs)
        {
            found = true;
            d->displayPetDetails();
            cout << "-------------------------------" << endl;
        }
    }
    else if (inputInt == 2)
    {
        for (Cat *c : cats)
        {
            found = true;
            c->displayPetDetails();
            cout << "-------------------------------" << endl;
        }
    }
    else if (inputInt == 3)
    {
        for (Bird *b : birds)
        {
            found = true;
            b->displayPetDetails();
            cout << "-------------------------------" << endl;
        }
    }
    if (found == false)
        cout << "We do not currently have any of this pet in the store." << endl; // ERROR CHECKING NEEDED.
}

void Shop::searchPetByDetails()
{
    bool found = false;

    cout << "-------------------------------" << endl;
    cout << "1. Dog" << endl;
    cout << "2. Cat" << endl;
    cout << "3. Bird" << endl;
    cout << "Enter the number for the pet type that you would like to check for: " << flush;
    string inputStr;
    getline(cin, inputStr);
    int inputInt = stoi(inputStr);

    if (inputInt == 2)
    {

        cout << "-------------------------------" << endl;
        cout << "1. Vaccinated?" << endl;
        cout << "2. Neutered?" << endl;
        cout << "3. Age?" << endl;
        cout << "Enter the number for the above detail that you would like to check for: " << flush;
        string inputStr;
        getline(cin, inputStr);
        int inputInt = stoi(inputStr);
        if (inputInt == 1)
        {
            for (Cat *c : cats)
            {
                if (c->getIsNeutered() == true)
                {
                    found = true;
                    c->displayPetDetails();
                    cout << "-------------------------------" << endl;
                }
            }
            if (found == false)
                cout << "No cats found with this detail." << endl;
        }
        else if (inputInt == 2)
        {
            for (Cat *c : cats)
            {
                if (c->getIsVaccinated() == true)
                {
                    found = true;
                    c->displayPetDetails();
                    cout << "-------------------------------" << endl;
                }
            }
            if (found == false)
                cout << "No cats found with this detail." << endl;
        }
        else if (inputInt == 3)
        {
            cout << "Enter the age of cats you would like to search for: " << flush;
            string ageInputStr;
            getline(cin, ageInputStr);
            int ageInputInt = stoi(ageInputStr);
            for (Cat *c : cats)
            {
                if (c->getPetAge() == ageInputInt)
                {
                    found = true;
                    c->displayPetDetails();
                    cout << "-------------------------------" << endl;
                }
            }
            if (found == false)
                cout << "No cats found with this age." << endl;
        }
        else
            cout << "Invalid input!" << endl;
    }
    else if (inputInt == 1)
    {

        cout << "-------------------------------" << endl;
        cout << "1. Vaccinated?" << endl;
        cout << "2. Neutered?" << endl;
        cout << "3. Age?" << endl;
        cout << "Enter the number for the above detail that you would like to check for: " << flush;
        string inputStr;
        getline(cin, inputStr);
        int inputInt = stoi(inputStr);
        if (inputInt == 1)
        {
            for (Dog *d : dogs)
            {
                if (d->getIsNeutered() == true)
                {
                    found = true;
                    d->displayPetDetails();
                    cout << "-------------------------------" << endl;
                }
            }
            if (found == false)
                cout << "No dogs found with this detail." << endl;
        }
        else if (inputInt == 2)
        {
            for (Dog *d : dogs)
            {
                if (d->getIsVaccinated() == true)
                {
                    found = true;
                    d->displayPetDetails();
                    cout << "-------------------------------" << endl;
                }
            }
            if (found == false)
                cout << "No dogs found with this detail." << endl;
        }
        else if (inputInt == 3)
        {
            cout << "Enter the age of dogs you would like to search for: " << flush;
            string ageInputStr;
            getline(cin, ageInputStr);
            int ageInputInt = stoi(ageInputStr);
            for (Dog *d : dogs)
            {
                if (d->getPetAge() == ageInputInt)
                {
                    found = true;
                    d->displayPetDetails();
                    cout << "-------------------------------" << endl;
                }
            }
            if (found == false)
                cout << "No dogs found with this age." << endl;
        }
        else
            cout << "Invalid input!" << endl;
    }
    else if (inputInt == 3)
    {

        cout << "-------------------------------" << endl;
        cout << "1. Council Licenced?" << endl;
        cout << "2. Age?" << endl;
        cout << "Enter the number for the above detail that you would like to check for: " << flush;
        string inputStr;
        getline(cin, inputStr);
        int inputInt = stoi(inputStr);
        if (inputInt == 1)
        {
            for (Bird *b : birds)
            {
                if (b->getIsCouncilLicenced() == true)
                {
                    found = true;
                    b->displayPetDetails();
                    cout << "-------------------------------" << endl;
                }
            }
            if (found == false)
                cout << "No birds found with this detail." << endl;
        }
        else if (inputInt == 2)
        {
            cout << "Enter the age of birds you would like to search for: " << flush;
            string ageInputStr;
            getline(cin, ageInputStr);
            int ageInputInt = stoi(ageInputStr);
            for (Bird *b : birds)
            {
                if (b->getPetAge() == ageInputInt)
                {
                    found = true;
                    b->displayPetDetails();
                    cout << "-------------------------------" << endl;
                }
            }
            if (found == false)
                cout << "No birds found with this age." << endl;
        }
        else
            cout << "Invalid input!" << endl;
    }
    else
        cout << "Invalid input! Please try again." << endl;

    // if (found == false)
    //     cout << "We do not currently have any " << pet_type << "s in the store." << endl; // ERROR CHECKING NEEDED.
}

void Shop::displayAllPets()
{
    int pet_counter = 0;
    for (Dog *d : dogs)
    {
        pet_counter++;
        d->displayPetDetails();
        cout << "-------------------------------" << endl;
    }
    for (Cat *c : cats)
    {
        pet_counter++;
        c->displayPetDetails();
        cout << "-------------------------------" << endl;
    }
    for (Bird *b : birds)
    {
        pet_counter++;
        b->displayPetDetails();
        cout << "-------------------------------" << endl;
    }
    cout << "Total number of pets is: " << pet_counter << endl;
}

void Shop::removePet()
{
    bool removed = false;
    cout << "1. Dog" << endl;
    cout << "2. Cat" << endl;
    cout << "3. Bird" << endl;
    cout << "Enter the number for the pet type you would like to remove: " << flush;
    string inputStr;
    getline(cin, inputStr);
    int inputInt = stoi(inputStr);
    if (inputInt == 1)
    {
        cout << "Enter the ID of the dog you would like to remove: " << flush;
        string inputStr;
        getline(cin, inputStr);
        int inputInt = stoi(inputStr);
        // Here I am removing an object from the vector using 2 iterators.
        vector<Dog *>::iterator it = dogs.begin();
        for (Dog *d : dogs)
        {
            if (d->getPetID() == inputInt)
            {
                delete d;
                removed = true;
            }
            else
            {
                *it++ = d;
            }
        }
        dogs.erase(it, dogs.end());
    }
    else if (inputInt == 2)
    {
        cout << "Enter the ID of the cat you would like to remove: " << flush;
        string inputStr;
        getline(cin, inputStr);
        int inputInt = stoi(inputStr);
        vector<Cat *>::iterator it = cats.begin();
        for (Cat *c : cats)
        {
            if (c->getPetID() == inputInt)
            {
                delete c;
                removed = true;
            }
            else
            {
                *it++ = c;
            }
        }
        cats.erase(it, cats.end());
    }
    else if (inputInt == 3)
    {
        cout << "Enter the ID of the bird you would like to remove: " << flush;
        string inputStr;
        getline(cin, inputStr);
        int inputInt = stoi(inputStr);
        vector<Bird *>::iterator it = birds.begin();
        for (Bird *b : birds)
        {
            if (b->getPetID() == inputInt)
            {
                delete b;
                removed = true;
            }
            else
            {
                *it++ = b;
            }
        }
        birds.erase(it, birds.end());
    }
    else
    {
        cout << "Invalid input, please try again." << endl;
    }
    if (removed == true)
        cout << "Pet successfully removed." << endl;
    else
        cout << "There are no pets with this ID. No pets removed." << endl;
}

void Shop::addPet()
{
    int uniqueId = getMaxId();
    uniqueId++;

    cout << "1. Dog" << endl;
    cout << "2. Cat" << endl;
    cout << "3. Bird" << endl;
    cout << "Enter the number for the pet type you would like to add: " << flush;

    string inputStr;
    getline(cin, inputStr);
    int inputInt = stoi(inputStr);

    if (inputInt == 1)
    {
        cout << "Is the dog neutered? Enter 1 for Yes or 2 for No: " << flush;
        string isNeutered_input_str;
        getline(cin, isNeutered_input_str);
        int isNeutered_input_int = stoi(isNeutered_input_str);
        if (isNeutered_input_int == 1)
            isNeutered_input_int = true;
        else if (isNeutered_input_int == 2)
            isNeutered_input_int = false;
        else
            cout << "Incorrect input, please try again." << endl;

        cout << "Is the dog vaccinated? Enter 1 for Yes or 2 for No: " << flush;
        string isVaccinated_input_str;
        getline(cin, isVaccinated_input_str);
        int isVaccinated_input_int = stoi(isVaccinated_input_str);
        if (isVaccinated_input_int == 1)
            isVaccinated_input_int = true;
        else if (isVaccinated_input_int == 2)
            isVaccinated_input_int = false;
        else
            cout << "Incorrect input, please try again." << endl;

        int petAge_input_int;
        while (true)
        {
            cout << "Enter a value for the dog's age: " << flush;
            string petAge_input_str;
            getline(cin, petAge_input_str);
            petAge_input_int = stoi(petAge_input_str);
            if (petAge_input_int >= 0)
                break;
        }

        double petPrice_input_double;
        while (true)
        {
            cout << "Enter a value for the dog's price: " << flush;
            string petPrice_input_str;
            getline(cin, petPrice_input_str);
            petPrice_input_double = stod(petPrice_input_str);
            if (petPrice_input_double >= 0)
                break;
        }

        string dogBreed_inputted;

        cout << "1. Labrador-Retriever" << endl;
        cout << "2. Bulldog" << endl;
        cout << "3. German-Shepherd" << endl;
        cout << "4. Golden-Retriever" << endl;
        cout << "5. Poodle" << endl;
        cout << "Enter the number for the dog breed you would like to add: " << flush;
        string dogBreed_input_str;
        getline(cin, dogBreed_input_str);
        int dogBreed_input_int = stoi(dogBreed_input_str);
        if (dogBreed_input_int == 1)
            dogBreed_inputted = "Labrador-Retriever";
        else if (dogBreed_input_int == 2)
            dogBreed_inputted = "Bulldog";
        else if (dogBreed_input_int == 3)
            dogBreed_inputted = "German-Shepherd";
        else if (dogBreed_input_int == 4)
            dogBreed_inputted = "Golden-Retriever";
        else if (dogBreed_input_int == 5)
            dogBreed_inputted = "Poodle";
        else
            cout << "Incorrect input, please try again." << endl;

        string dogColour_inputted;
        cout << "1. Black" << endl;
        cout << "2. White" << endl;
        cout << "3. Brown" << endl;
        cout << "4. Grey" << endl;
        cout << "5. Other" << endl;
        cout << "Enter the number for the dog colour you would like to add: " << flush;
        string dogColour_input_str;
        getline(cin, dogColour_input_str);
        int dogColour_input_int = stoi(dogColour_input_str);
        if (dogColour_input_int == 1)
            dogColour_inputted = "Black";
        else if (dogColour_input_int == 2)
            dogColour_inputted = "White";
        else if (dogColour_input_int == 3)
            dogColour_inputted = "Brown";
        else if (dogColour_input_int == 4)
            dogColour_inputted = "Grey";
        else if (dogColour_input_int == 5)
            dogColour_inputted = "Other";
        else
            cout << "Incorrect input, please try again." << endl;

        string dogCountryOriginInputted;
        if (dogBreed_inputted == "Labrador-Retriever")
            dogCountryOriginInputted = "Newfoundland";
        else if (dogBreed_inputted == "Bulldog")
            dogCountryOriginInputted = "England";
        else if (dogBreed_inputted == "German-Shepherd")
            dogCountryOriginInputted = "Germany";
        else if (dogBreed_inputted == "Golden-Retriever")
            dogCountryOriginInputted = "Scotland";
        else if (dogBreed_inputted == "Poodle")
            dogCountryOriginInputted = "Germany";

        int petId = uniqueId;

        dogs.push_back(new Dog(isNeutered_input_int, isVaccinated_input_int, petAge_input_int, petPrice_input_double, dogBreed_inputted, dogColour_inputted, dogCountryOriginInputted, petId));
        cout << "Successfully added this dog to the inventory." << endl;
    }
    else if (inputInt == 2) // HERE!!!
    {
        cout << "Is the cat neutered? Enter 1 for Yes or 2 for No: " << flush;
        string isNeutered_input_str;
        getline(cin, isNeutered_input_str);
        int isNeutered_input_int = stoi(isNeutered_input_str);
        if (isNeutered_input_int == 1)
            isNeutered_input_int = true;
        else if (isNeutered_input_int == 2)
            isNeutered_input_int = false;
        else
            cout << "Incorrect input, please try again." << endl;

        cout << "Is the cat vaccinated? Enter 1 for Yes or 2 for No: " << flush;
        string isVaccinated_input_str;
        getline(cin, isVaccinated_input_str);
        int isVaccinated_input_int = stoi(isVaccinated_input_str);
        if (isVaccinated_input_int == 1)
            isVaccinated_input_int = true;
        else if (isVaccinated_input_int == 2)
            isVaccinated_input_int = false;
        else
            cout << "Incorrect input, please try again." << endl;

        int petAge_input_int;
        while (true)
        {
            cout << "Enter a value for the cat's age: " << flush;
            string petAge_input_str;
            getline(cin, petAge_input_str);
            petAge_input_int = stoi(petAge_input_str);
            if (petAge_input_int >= 0)
                break;
        }

        double petPrice_input_double;
        while (true)
        {
            cout << "Enter a value for the cat's price: " << flush;
            string petPrice_input_str;
            getline(cin, petPrice_input_str);
            petPrice_input_double = stod(petPrice_input_str);
            if (petPrice_input_double >= 0)
                break;
        }

        string catBreed_inputted;
        cout << "1. Maine-Coon" << endl;
        cout << "2. Ragdoll" << endl;
        cout << "3. Siamese-cat" << endl;
        cout << "4. Persian-cat" << endl;
        cout << "5. British-Shorthair" << endl;
        cout << "Enter the number for the cat breed you would like to add: " << flush;
        string catBreed_input_str;
        getline(cin, catBreed_input_str);
        int catBreed_input_int = stoi(catBreed_input_str);
        if (catBreed_input_int == 1)
            catBreed_inputted = "Maine-Coon";
        else if (catBreed_input_int == 2)
            catBreed_inputted = "Ragdoll";
        else if (catBreed_input_int == 3)
            catBreed_inputted = "Siamese-cat";
        else if (catBreed_input_int == 4)
            catBreed_inputted = "Persian-cat";
        else if (catBreed_input_int == 5)
            catBreed_inputted = "British-Shorthair";
        else
            cout << "Incorrect input, please try again." << endl;

        string catColour_inputted;
        cout << "1. Black" << endl;
        cout << "2. White" << endl;
        cout << "3. Brown" << endl;
        cout << "4. Grey" << endl;
        cout << "5. Other" << endl;
        cout << "Enter the number for the cat colour you would like to add: " << flush;
        string catColour_input_str;
        getline(cin, catColour_input_str);
        int catColour_input_int = stoi(catColour_input_str);
        if (catColour_input_int == 1)
            catColour_inputted = "Black";
        else if (catColour_input_int == 2)
            catColour_inputted = "White";
        else if (catColour_input_int == 3)
            catColour_inputted = "Brown";
        else if (catColour_input_int == 4)
            catColour_inputted = "Grey";
        else if (catColour_input_int == 5)
            catColour_inputted = "Other";
        else
            cout << "Incorrect input, please try again." << endl;

        string catCountryOriginInputted;
        if (catBreed_inputted == "Maine-Coon")
            catCountryOriginInputted = "Maine-USA";
        else if (catBreed_inputted == "Ragdoll")
            catCountryOriginInputted = "California-USA";
        else if (catBreed_inputted == "Siamese-cat")
            catCountryOriginInputted = "Thailand";
        else if (catBreed_inputted == "Persian-cat")
            catCountryOriginInputted = "Iran";
        else if (catBreed_inputted == "British-Shorthair")
            catCountryOriginInputted = "Britain";

        int petId = uniqueId;

        cats.push_back(new Cat(isNeutered_input_int, isVaccinated_input_int, petAge_input_int, petPrice_input_double, catBreed_inputted, catColour_inputted, catCountryOriginInputted, petId));
        cout << "Successfully added this cat to the inventory." << endl;
    }
    else if (inputInt == 3)
    {
        cout << "Has the bird got a council licence? Enter 1 for Yes or 2 for No: " << flush;
        string hasCouncilLicence_input_str;
        getline(cin, hasCouncilLicence_input_str);
        int hasCouncilLicence_input_int = stoi(hasCouncilLicence_input_str);
        if (hasCouncilLicence_input_int == 1)
            hasCouncilLicence_input_int = true;
        else if (hasCouncilLicence_input_int == 2)
            hasCouncilLicence_input_int = false;
        else
            cout << "Incorrect input, please try again." << endl;

        int petAge_input_int;
        while (true)
        {
            cout << "Enter a value for the bird's age: " << flush;
            string petAge_input_str;
            getline(cin, petAge_input_str);
            petAge_input_int = stoi(petAge_input_str);
            if (petAge_input_int >= 0)
                break;
        }

        double petPrice_input_double;
        while (true)
        {
            cout << "Enter a value for the bird's price: " << flush;
            string petPrice_input_str;
            getline(cin, petPrice_input_str);
            petPrice_input_double = stod(petPrice_input_str);
            if (petPrice_input_double >= 0)
                break;
        }

        string birdBreed_inputted;
        cout << "1. Budgie" << endl;
        cout << "2. Cockatiel" << endl;
        cout << "3. Finch" << endl;
        cout << "4. Lovebird" << endl;
        cout << "5. African Gray Parrot" << endl;
        cout << "Enter the number for the bird breed you would like to add: " << flush;
        string birdBreed_input_str;
        getline(cin, birdBreed_input_str);
        int birdBreed_input_int = stoi(birdBreed_input_str);
        if (birdBreed_input_int == 1)
            birdBreed_inputted = "Budgie";
        else if (birdBreed_input_int == 2)
            birdBreed_inputted = "Cockatiel";
        else if (birdBreed_input_int == 3)
            birdBreed_inputted = "Finch";
        else if (birdBreed_input_int == 4)
            birdBreed_inputted = "Lovebird";
        else if (birdBreed_input_int == 5)
            birdBreed_inputted = "African Gray Parrot";
        else
            cout << "Incorrect input, please try again." << endl;

        string birdColour_inputted;
        cout << "1. Black" << endl;
        cout << "2. White" << endl;
        cout << "3. Brown" << endl;
        cout << "4. Grey" << endl;
        cout << "5. Other" << endl;
        cout << "Enter the number for the bird colour you would like to add: " << flush;
        string birdColour_input_str;
        getline(cin, birdColour_input_str);
        int birdColour_input_int = stoi(birdColour_input_str);
        if (birdColour_input_int == 1)
            birdColour_inputted = "Black";
        else if (birdColour_input_int == 2)
            birdColour_inputted = "White";
        else if (birdColour_input_int == 3)
            birdColour_inputted = "Brown";
        else if (birdColour_input_int == 4)
            birdColour_inputted = "Grey";
        else if (birdColour_input_int == 5)
            birdColour_inputted = "Other";
        else
            cout << "Incorrect input, please try again." << endl;

        string birdCountryOriginInputted;
        if (birdBreed_inputted == "Budgie")
            birdCountryOriginInputted = "Australia";
        else if (birdBreed_inputted == "Cockatiel")
            birdCountryOriginInputted = "Australia";
        else if (birdBreed_inputted == "Finch")
            birdCountryOriginInputted = "Hungary";
        else if (birdBreed_inputted == "Lovebird")
            birdCountryOriginInputted = "Madagascar";
        else if (birdBreed_inputted == "African Gray Parrot")
            birdCountryOriginInputted = "Central African Countries";

        int petId = uniqueId;

        birds.push_back(new Bird(hasCouncilLicence_input_int, petAge_input_int, petPrice_input_double, birdBreed_inputted, birdColour_inputted, birdCountryOriginInputted, petId));
        cout << "Successfully added this bird to the inventory." << endl;
    }
    else
    {
        cout << "Invalid input, you will be returned to the main menu." << endl;
    }
}

int Shop::getMaxId()
{
    int max_id = 0;
    for (Dog *d : dogs)
    {
        if (d->getPetID() > max_id)
            max_id = d->getPetID();
    }
    for (Cat *c : cats)
    {
        if (c->getPetID() > max_id)
            max_id = c->getPetID();
    }
    for (Bird *b : birds)
    {
        if (b->getPetID() > max_id)
            max_id = b->getPetID();
    }
    return max_id;
}

void Shop::readFromFile()
{
    ifstream myFile;
    string fPath = "Pets.csv";
    myFile.open(fPath);
    if (myFile.is_open())
    {
        bool neutered, vaccinated, councilLicence;
        int petAge, petID;
        double petPrice;
        string breed, colour, countryOrigin;
        while (myFile >> neutered >> vaccinated >> petAge >> petPrice >> breed >> colour >> countryOrigin >> petID)
        {
            if (breed == "Labrador-Retriever" || breed == "Bulldog" || breed == "German-Shepherd" || breed == "Golden-Retriever" || breed == "Poodle")
            {
                dogs.push_back(new Dog(neutered, vaccinated, petAge, petPrice, breed, colour, countryOrigin, petID));
            }
            else if (breed == "Maine-Coon" || breed == "Ragdoll" || breed == "Siamese-cat" || breed == "Persian-cat" || breed == "British-Shorthair")
            {
                cats.push_back(new Cat(neutered, vaccinated, petAge, petPrice, breed, colour, countryOrigin, petID));
            }
            else
                birds.push_back(new Bird(neutered, petAge, petPrice, breed, colour, countryOrigin, petID));
        }
    }
    else
        cout << "Couldn't open file!" << endl;
}

void Shop::saveToFile()
{
    ofstream myFile;
    string fPath = "Pets.csv";
    myFile.open(fPath);
    if (myFile.is_open())
    {
        for (Dog *d : dogs)
        {
            myFile << d->getIsNeutered() << " " << d->getIsVaccinated() << " " << d->getPetAge() << " " << d->getPetPrice() << " " << d->getPetBreed() << " " << d->getPetColour() << " " << d->getPetCountryOrigin() << " " << d->getPetID() << "\n";
            if (myFile.fail())
                cout << "Failed!" << flush;
        }
        for (Cat *c : cats)
        {
            myFile << c->getIsNeutered() << " " << c->getIsVaccinated() << " " << c->getPetAge() << " " << c->getPetPrice() << " " << c->getPetBreed() << " " << c->getPetColour() << " " << c->getPetCountryOrigin() << " " << c->getPetID() << "\n";
            if (myFile.fail())
                cout << "Failed!" << flush;
        }
        for (Bird *b : birds)
        {
            myFile << b->getIsCouncilLicenced() << " "
                   << 1
                   << " " << b->getPetAge() << " " << b->getPetPrice() << " " << b->getPetBreed() << " " << b->getPetColour() << " " << b->getPetCountryOrigin() << " " << b->getPetID() << "\n";
            if (myFile.fail())
                cout << "Failed!" << flush;
        }
    }
    else
        cout << "Couldn't open file!" << endl;
}
