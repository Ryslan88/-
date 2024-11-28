#ifndef TRAVOIDNI_H
#define TRAVOIDNI_H

#include "Tvarina.h"
#include "Display.h"

class Travoidni : public Tvarina {
private:
    double weight; // Вага травоїдної

public:
    Travoidni(std::string n = "", double c = 0.0, int d = 0, double w = 0.0);
    ~Travoidni();

    friend class Display; // Дружній клас

    void display() const override;
    void input() override; // Введення даних
};

#endif
