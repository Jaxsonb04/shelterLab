//
// Created by Jaxson Bie on 2/19/24.
//
#include <string>
#include <fstream>
#include <sstream>
#include "Pets.h"

#ifndef LAB_1_SHELTER_H
#define LAB_1_SHELTER_H

const int MAXSIZE = 10;

class Shelter {
public:
    //constructor
    Shelter();

    Shelter(std::string fileName);

    //getters
    int getDayCount() const;

    Pets *getPet(int id) const;

    int getCurrentAnimals() const;

    //setters
    void addPets(std::string name, int ID, std::string fur, std::string type);

    void saveDay(std::string);

    //print
    void printShelter();

    //Return pet that stayed in the shelter the longest
    void beenLongest();

private:
    int dayCount;
    std::string fileName;
    int shelterCapacity = MAXSIZE;
    int currentAnimals = 0;
    Pets **petPointer = new Pets *[shelterCapacity];
};

#endif //LAB_1_SHELTER_H
