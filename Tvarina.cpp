#include "Tvarina.h"
#include <iostream>
#include <limits>

Tvarina::Tvarina(std::string n, double a, int d) : name(n), age(a), duration(d) {}

Tvarina::~Tvarina() {}

void Tvarina::input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введіть назву тварини: ";
    while (std::getline(std::cin, name) && name.empty()) {
        std::cout << "Назва не може бути порожньою. Спробуйте ще раз: ";
    }

    std::cout << "Введіть вік тварини: ";
    while (!(std::cin >> age) || age < 0) {
        std::cout << "Вік має бути числом більше або рівне 0. Спробуйте ще раз: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введіть тривалість життя (роки): ";
    while (!(std::cin >> duration) || duration < 0) {
        std::cout << "Тривалість має бути числом більше або рівне 0. Спробуйте ще раз: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Tvarina::display() const {
    std::cout << "Назва: " << name << "\nВік: " << age 
              << "\nТривалість життя: " << duration << " років\n";
}
