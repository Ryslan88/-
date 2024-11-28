#include "Khizhak.h"
#include <iostream>
#include <limits>

Khizhak::Khizhak(std::string n, double a, int d, int s)
    : Tvarina(n, a, d), strength(s) {}

Khizhak::~Khizhak() {}

void Khizhak::input() {
    Tvarina::input();

    while (true) {
        std::cout << "Введіть силу хижака: ";
        std::cin >> strength;
        if (std::cin.fail() || strength <= 0) {
            std::cout << "Сила має бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void Khizhak::display() const {
    std::cout << "Хижак: " << name << "\n"
              << "Вік: " << age << "\n"
              << "Тривалість життя: " << duration << " років\n";
}

// Дружня функція для скидання сили хижака
void resetStrength(Khizhak& khizhak) {
    khizhak.strength = 0;
}
