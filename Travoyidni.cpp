#include "Travoyidni.h"
#include <iostream>

Travoyidni::Travoyidni(std::string n, int f) : Tvaryna(n, f) {}

Travoyidni::~Travoyidni() {}

void Travoyidni::display() const {
    std::cout << "Травоїдна тварина: " << name << "\n"
              << "Кількість їжі: " << foodAmount << " кг\n";
}

void Travoyidni::input() {
    Tvaryna::input();
}
