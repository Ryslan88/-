#ifndef TRAVOIDNI_H
#define TRAVOIDNI_H

#include "Tvarina.h"

class Display;

class Travoidni : public Tvarina {
private:
    double weight; // Вага травоїдної

public:
    Travoidni(std::string n = "", double c = 0.0, int d = 0, double w = 0.0);
    ~Travoidni();

    friend class Display;
    friend void resetWeight(Travoidni& travoidni);

    void display() const override;
    void input() override; // Метод для введення даних
    double getWeight() const { return weight; }
};

#endif
