#include "Hizhak.h"
#include <iostream>

Hizhak::Hizhak(std::string n, int f) : Tvaryna(n, f) {}

Hizhak::~Hizhak() {}

void Hizhak::display() const {
    std::cout << "Хижа тварина: " << name << "\n"
              << "Кількість їжі: " << foodAmount << " кг\n";
}

void Hizhak::input() {
    Tvaryna::input();
}
