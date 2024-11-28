#include "Travoidni.h"
#include <iostream>
#include <limits>

Travoidni::Travoidni(std::string n, double a, int d, double w)
    : Tvarina(n, a, d), weight(w) {}

Travoidni::~Travoidni() {}

void Travoidni::input() {
    Tvarina::input();
    std::cout << "Введіть вагу травоїдної (кг): ";
    while (!(std::cin >> weight) || weight <= 0) {
        std::cout << "Вага має бути числом більше 0. Спробуйте ще раз: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Travoidni::display() const {
    Tvarina::display();
    std::cout << "Вага: " << weight << " кг\n";
}
