#ifndef CARNIVOROUS_ANIMAL_H
#define CARNIVOROUS_ANIMAL_H

#include "Animal.h"
#include <iostream>

class CarnivorousAnimal : public Animal {
private:
    int preyCount; // Кількість здобичі

public:
    CarnivorousAnimal(const std::string& name = "", const std::string& food = "meat", int preyCount = 0)
        : Animal(name, food), preyCount(preyCount) {}

    void showInfo() const override {
        std::cout << "Carnivorous Animal: " << name << "\nFood: " << food
                  << "\nPrey count: " << preyCount << std::endl;
    }

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Carnivorous " << name << " " << food << " " << preyCount << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
        ifs >> name >> food >> preyCount;
    }
};

#endif // CARNIVOROUS_ANIMAL_H
