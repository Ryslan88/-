#ifndef KHIZHAK_H
#define KHIZHAK_H

#include <string>  // Для std::string
#include "Tvarina.h"  // Для базового класу Tvarina

class Khizhak : public Tvarina {
private:
    int strength; // Сила хижака

public:
    Khizhak(std::string n = "", double c = 0.0, int d = 0, int s = 0);
    ~Khizhak();

    void display() const override;
    void input() override; // Введення даних
};

#endif
