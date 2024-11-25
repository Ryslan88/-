#ifndef TRAVOYIDNI_H
#define TRAVOYIDNI_H

#include "Tvaryna.h"

class Travoyidni : public Tvaryna {
public:
    Travoyidni(std::string n = "", int f = 0);
    ~Travoyidni();

    void display() const override;
    void input() override;
};

#endif
