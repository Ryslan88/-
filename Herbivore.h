#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "Animal.h"

class Herbivore : public Animal {
public:
    Herbivore(const std::string& name, int foodAmount)
        : Animal(name, "Травоїдні", foodAmount) {}

    void showInfo() const override;  // тільки оголошення, без тіла функції
};

#endif
