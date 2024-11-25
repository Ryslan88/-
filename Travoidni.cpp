#include "Travoidni.h"
#include <iostream>
#include <limits>

Travoidni::Travoidni(std::string n, double a, int d, double w)
    : Tvarina(n, a, d), weight(w) {}

Travoidni::~Travoidni() {}

void Travoidni::input() {
    Tvarina::input();

    while (true) {
        std::cout << "Введіть вагу травоїдної (кг): ";
        std::cin >> weight;
        if (std::cin.fail() || weight <= 0) {
            std::cout << "Вага має бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void Travoidni::display() const {
    std::cout << "Травоїдна: " << name << "\n"
              << "Вік: " << age << "\n"
              << "Тривалість життя: " << duration << " років\n";
}
