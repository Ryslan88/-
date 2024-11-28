#ifndef DISPLAY_H
#define DISPLAY_H

#include "Tvarina.h"
#include "Khizhak.h"
#include "Travoidni.h"
#include <iostream>

class Display {
public:
    void show(const Tvarina& tvarina) const {
        tvarina.display();
    }

    void showPredatorInfo(const Khizhak& khizhak) const {
        std::cout << "Сила хижака: " << khizhak.getStrength() << std::endl;
    }

    void showHerbivoreInfo(const Travoidni& travoidni) const {
        std::cout << "Вага травоїдної: " << travoidni.getWeight() << " кг" << std::endl;
    }

    void resetPredatorStrength(Khizhak& khizhak) const {
        resetStrength(khizhak);
        std::cout << "Сила хижака скинута.\n";
    }

    void resetHerbivoreWeight(Travoidni& travoidni) const {
        resetWeight(travoidni);
        std::cout << "Вага травоїдної скинута.\n";
    }
};

#endif
