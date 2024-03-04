//
// Created by Jaxson Bie on 2/19/24.
//
#include <string>

#ifndef LAB_1_PETS_H
#define LAB_1_PETS_H

class Pets {
public:
    //constructor
    Pets(std::string Name, int ID, std::string fur, std::string animalType, int day);

    //getters
    int getID() const;

    std::string getName() const;

    std::string getFurColor() const;

    std::string getAnimalType() const;

    int getPetDate() const;

    //setters
    void setName(std::string name);

    void setID(int id);

    void setFur(std::string fur);

    void setAnimal(std::string type);

    void setDay(int day);

    void printPet();

private:
    std::string Name;
    int ID;
    std::string furColor;
    std::string animalType;
    int petDay;
};

#endif //LAB_1_PETS_H
