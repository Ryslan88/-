#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string name;
    std::string category;
    int foodAmount;

public:
    Animal(const std::string& name, const std::string& category, int foodAmount)
        : name(name), category(category), foodAmount(foodAmount) {}

    virtual void showInfo() const = 0; // Чисто віртуальна функція
    virtual ~Animal() {} // Віртуальний деструктор
};

#endif
