#ifndef TVARYNA_H
#define TVARYNA_H

#include <string>

class Tvaryna {
protected:
    std::string name;
    int foodAmount; // Кількість їжі, яку споживає тварина (кг)

public:
    Tvaryna(std::string n = "", int f = 0);
    virtual ~Tvaryna();

    std::string getName() const;
    int getFoodAmount() const;

    virtual void display() const = 0;
    virtual void input(); // Метод для введення даних

    void setName(std::string n);
    void setFoodAmount(int f);
};

#endif
