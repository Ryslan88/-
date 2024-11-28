#ifndef HERBIVOROUS_ANIMAL_H
#define HERBIVOROUS_ANIMAL_H

#include "Animal.h"
#include <iostream>

class HerbivorousAnimal : public Animal {
private:
    int plantCount; // Кількість рослин, яку споживає тварина

public:
    HerbivorousAnimal(const std::string& name = "", const std::string& food = "plants", int plantCount = 0)
        : Animal(name, food), plantCount(plantCount) {}

    void showInfo() const override {
        std::cout << "Herbivorous Animal: " << name << "\nFood: " << food
                  << "\nPlant count: " << plantCount << std::endl;
    }

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Herbivorous " << name << " " << food << " " << plantCount << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
        ifs >> name >> food >> plantCount;
    }
};

#endif // HERBIVOROUS_ANIMAL_H
