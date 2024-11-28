#include "Khizhak.h"
#include <iostream>
#include <limits>

Khizhak::Khizhak(std::string n, double a, int d, int s)
    : Tvarina(n, a, d), strength(s) {}

Khizhak::~Khizhak() {}

void Khizhak::input() {
    Tvarina::input();
    std::cout << "Введіть силу хижака: ";
    while (!(std::cin >> strength) || strength <= 0) {
        std::cout << "Сила має бути числом більше 0. Спробуйте ще раз: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Khizhak::display() const {
    Tvarina::display();
    std::cout << "Сила: " << strength << '\n';
}
