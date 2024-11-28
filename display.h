#ifndef DISPLAY_H
#define DISPLAY_H

#include "Tvarina.h"
#include "Khizhak.h"
#include "Travoidni.h"
#include <iostream>

class Display {
public:
    void show(const Tvarina& tvarina) const {
        tvarina.display(); // Виклик методу display() об'єкта
    }

    void showDetailed(const Khizhak& khizhak) const {
        std::cout << "Детальна інформація про хижака:\n"
                  << "Назва: " << khizhak.name << "\n"
                  << "Сила: " << khizhak.strength << "\n"
                  << "Тривалість життя: " << khizhak.duration << " років\n";
    }

    void showDetailed(const Travoidni& travoidni) const {
        std::cout << "Детальна інформація про травоїдну:\n"
                  << "Назва: " << travoidni.name << "\n"
                  << "Вага: " << travoidni.weight << " кг\n"
                  << "Тривалість життя: " << travoidni.duration << " років\n";
    }

    void reset(Tvarina& tvarina) const {
        // Динамічне приведення типу для роботи з похідними класами
        if (Khizhak* khizhak = dynamic_cast<Khizhak*>(&tvarina)) {
            khizhak->strength = 0;
            std::cout << "Сила хижака скинута до 0.\n";
        } else if (Travoidni* travoidni = dynamic_cast<Travoidni*>(&tvarina)) {
            travoidni->weight = 0;
            std::cout << "Вага травоїдної скинута до 0.\n";
        }
    }
};

#endif
