//
// Created by Jaxson Bie on 2/19/24.
//

#include "Pets.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

//Constructor
Pets::Pets(std::string Name, int ID, std::string fur, std::string animalType, int day) {
    this->Name = Name;
    this->ID = ID;
    this->furColor = fur;
    this->animalType = animalType;
    this->petDay = day;
}

//getters
std::string Pets::getName() const {
    return Name;
}

int Pets::getID() const {
    return ID;
}

std::string Pets::getFurColor() const {
    return furColor;
}

std::string Pets::getAnimalType() const {
    return animalType;
}

int Pets::getPetDate() const {
    return petDay;
}

//setters
void Pets::setName(std::string name) {
    this->Name = name;
}

void Pets::setID(int id) {
    this->ID = id;
}

void Pets::setFur(std::string fur) {
    this->furColor = fur;
}

void Pets::setAnimal(std::string type) {
    this->animalType = type;
}

void Pets::setDay(int day) {
    this->petDay = day;
}

void Pets::printPet() {
    std::cout << "ID: " << ID << " " << "Pet name: " << Name << " " << "Fur Color: " << furColor << " "
              << "Animal Type: " << animalType << " " << " Shelter Day: " << petDay << std::endl;
}


