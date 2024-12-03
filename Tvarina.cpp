#ifndef KHIZHAK_H
#define KHIZHAK_H

#include "Tvarina.h"
#include "display.h"

class Khizhak : public Tvarina {
private:
    int strength; // Сила хижака

public:
    Khizhak(std::string n = "", double c = 0.0, int d = 0, int s = 0);
    ~Khizhak();

    friend class Display; // Дружній клас

    void display() const override;
    void input() override; // Введення даних
};

#endif
