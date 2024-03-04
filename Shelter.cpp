//
// Created by Jaxson Bie on 2/19/24.
//
#include <iostream>
#include "Shelter.h"
#include <fstream>
#include <string>
#include <sstream>


//default constructor that make sure everything is set to 0
Shelter::Shelter() {
    dayCount = 0;
    currentAnimals = 0;
}

//constructor takes an file.txt and convert file into pointer arrays
Shelter::Shelter(std::string file) {
    std::string line;
    std::string trash;
    std::ifstream ifs;
    ifs.open(file);

    if (ifs.fail()) {
        std::cout << "fail to open\n";
        exit(1);
    }

    getline(ifs, line);
    std::istringstream iss(line);

    std::string tempDayName;
    int dayCountNum;

    iss >> tempDayName >> dayCountNum;

    dayCount = dayCountNum;

    while (getline(ifs, line) && currentAnimals < MAXSIZE) {
        std::istringstream iss(line);

        std::string tempName;
        int tempID;
        std::string tempAnimalType;
        std::string tempFurColor;
        int tempPetDay;

        iss >> tempID >> tempName >> tempAnimalType >> tempFurColor >> tempPetDay;

        Pets *tempPet = new Pets(tempName, tempID, tempFurColor, tempAnimalType, tempPetDay);
        petPointer[currentAnimals] = tempPet;
        currentAnimals++;
    }
    ifs.close();
}

//getters
int Shelter::getDayCount() const {
    return dayCount;
}

Pets *Shelter::getPet(int id) const {
    for (int i = 0; i < currentAnimals; i++) {
        if (petPointer[i]->getID() == id) {
            std::cout << "found" << std::endl;
            return petPointer[i];
            std::cout << std::endl;
        }
    }
    return nullptr;
}

int Shelter::getCurrentAnimals() const {
    return currentAnimals;
}

//add pet function that takes all necessary parameter to create new pets into file user provided
void Shelter::addPets(std::string name, int ID, std::string fur, std::string type) {
    //make sure it is within max shelter size
    if (currentAnimals <= MAXSIZE) {
        for (int i = 0; i < currentAnimals; i++) {
            //duplicate id check
            if (ID == petPointer[i]->getID()) {
                std::cout << "unable to add, duplicate id" << std::endl;
                break;
            }
        }
        Pets *tempPet = new Pets(name, ID, fur, type, 0);
        petPointer[currentAnimals] = tempPet;
        currentAnimals++;
    } else {
        std::cout << "shelter is full, please go to another shelter like Mission pet Shelter";
    }
}

// save all the progress, increment days in shelter and pets, and then exit the program
void Shelter::saveDay(std::string fileName) {
    dayCount++;
    std::ofstream ofs;
    ofs.open(fileName);
    ofs << "dayCount " << dayCount << std::endl;
    for (int i = 0; i < currentAnimals; i++) {
        petPointer[i]->setDay(petPointer[i]->getPetDate() + 1);
        ofs << petPointer[i]->getID() << " "
            << petPointer[i]->getName() << " " << petPointer[i]->getAnimalType() <<
            " " << petPointer[i]->getFurColor() << " " << petPointer[i]->getPetDate() << std::endl;
        delete petPointer[i];
    }
    ofs.close();
    exit(0);
}

//print out pet(s) that been in the shelter the longest
void Shelter::beenLongest() {
    int longestDuration = petPointer[0]->getPetDate();
    //first for loop is to find the highest number
    for (int i = 0; i < currentAnimals; i++) {
        if (petPointer[i]->getPetDate() > longestDuration) {
            longestDuration = petPointer[i]->getPetDate();
        }
    }
    //second for loop is to print pets that has the highest number
    for (int i = 0; i < currentAnimals; i++) {
        if (petPointer[i]->getPetDate() == longestDuration) {
            petPointer[i]->printPet();
        }
    }
}

//print
 void Shelter::printShelter() {
    for (int i = 0; i < currentAnimals; i++) {
        petPointer[i]->printPet();
        std::cout << std::endl;
    }
}

