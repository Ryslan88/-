#ifndef HIZHAK_H
#define HIZHAK_H

#include "Tvaryna.h"

class Hizhak : public Tvaryna {
public:
    Hizhak(std::string n = "", int f = 0);
    ~Hizhak();

    void display() const override;
    void input() override;
};

#endif
