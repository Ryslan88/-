#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "Animal.h"

class Carnivore : public Animal {
public:
    Carnivore(const std::string& name, int foodAmount)
        : Animal(name, "Хижаки", foodAmount) {}

    void showInfo() const override;  // тільки оголошення, без тіла функції
};

#endif
