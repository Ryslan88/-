#include "Tvaryna.h"
#include <iostream>
#include <limits>

Tvaryna::Tvaryna(std::string n, int f) : name(n), foodAmount(f) {}

Tvaryna::~Tvaryna() {}

std::string Tvaryna::getName() const {
    return name;
}

int Tvaryna::getFoodAmount() const {
    return foodAmount;
}

void Tvaryna::setName(std::string n) {
    name = n;
}

void Tvaryna::setFoodAmount(int f) {
    if (f >= 0)
        foodAmount = f;
    else
        std::cout << "Кількість їжі не може бути негативною!" << std::endl;
}

void Tvaryna::input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введіть назву тварини: ";
    std::getline(std::cin, name);

    while (true) {
        std::cout << "Введіть кількість їжі (кг): ";
        std::cin >> foodAmount;
        if (std::cin.fail() || foodAmount < 0) {
            std::cout << "Кількість їжі повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}
