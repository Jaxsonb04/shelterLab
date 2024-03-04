#include <iostream>
#include "Pets.h"
#include "Shelter.h"

int main() {

    std::string userInput;
    std::string fileName;
    Shelter newShelter;
    bool loopRun = true;
    while (loopRun) {
        std::cout << "Is there an existing file? ";
        std::cin >> userInput;
        if (userInput == "y") {
            std::cout << "file name? ";
            std::cin >> fileName;
            newShelter = Shelter(fileName);
            loopRun = false;
        } else if (userInput == "n") {
            newShelter = Shelter();
            loopRun = false;
        } else {
            std::cout << "doesn't recognize input, please enter y or n" << std::endl;
        }
    }

    newShelter.printShelter();

    bool run = true;

    while (run) {
        int userInput;
        std::cout << "Pet Shelter Menu" << std::endl;
        std::cout << "Please pick a number" << std::endl;
        std::cout << "1. add pets" << std::endl;
        std::cout << "2. get pets" << std::endl;
        std::cout << "3. save " << std::endl;
        std::cout << "4. pet that is been here the longest " << std::endl;
        std::cout << "5. exit " << std::endl;
        std::cin >> userInput;
        switch (userInput) {
            case 1: {
                if (newShelter.getCurrentAnimals() > 10) {
                    std::cout << "Shelter full. unable to add pets" << std::endl;
                    break;
                } else {
                    bool progRunn = true;
                    while (progRunn) {
                        int newPetID;
                        std::string newPetName;
                        std::string newPetType;
                        std::string newPetColor;
                        std::cout << "please enter new pet id: ";
                        std::cin >> newPetID;
                        if (newShelter.getPet(newPetID) == nullptr) {
                            std::cout << "please enter new pet name: ";
                            std::cin >> newPetName;
                            std::cout << "please enter new pet type: ";
                            std::cin >> newPetType;
                            std::cout << "please enter new pet color: ";
                            std::cin >> newPetColor;
                            newShelter.addPets(newPetName, newPetID, newPetColor, newPetType);
                            std::cout << "successfully added!" << std::endl;
                            progRunn = false;
                        } else {
                            std::cout << "ID exists, please pick another one" << std::endl;
                        }
                    }
                }
                break;
            }

            case 2: {
                int petID;
                bool run = true;
                while (run) {
                    std::cout << "please enter pet id: ";
                    std::cin >> petID;
                    if (newShelter.getPet(petID) != nullptr) {
                        newShelter.getPet(petID)->printPet();
                        run = false;
                    } else {
                        std::cout << "please enter a existing pet ID" << std::endl;
                    }
                }
                break;

            }
            case 3:
                newShelter.saveDay("petData");
                break;
            case 4:
                newShelter.beenLongest();

                break;
            case 5:
                run = false;
                break;
        }
    }
}
