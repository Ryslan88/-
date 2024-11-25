#include "Tvarina.h"
#include <iostream>
#include <limits>

Tvarina::Tvarina(std::string n, double a, int d) : name(n), age(a), duration(d) {}

Tvarina::~Tvarina() {}

std::string Tvarina::getName() const {
    return name;
}

double Tvarina::getAge() const {
    return age;
}

int Tvarina::getDuration() const {
    return duration;
}

void Tvarina::setName(std::string n) {
    name = n;
}

void Tvarina::setAge(double a) {
    if (a >= 0)
        age = a;
    else
        std::cout << "Вік не може бути негативним!" << std::endl;
}

void Tvarina::setDuration(int d) {
    if (d >= 0)
        duration = d;
    else
        std::cout << "Тривалість не може бути негативною!" << std::endl;
}

void Tvarina::input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        std::cout << "Введіть назву тварини: ";
        std::getline(std::cin, name);
        if (!name.empty()) {
            break;
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }

    while (true) {
        std::cout << "Введіть вік тварини: ";
        std::cin >> age;
        if (std::cin.fail() || age < 0) {
            std::cout << "Вік має бути числом більше або рівне 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            setAge(age);
            break;
        }
    }

    while (true) {
        std::cout << "Введіть тривалість життя (роки): ";
        std::cin >> duration;
        if (std::cin.fail() || duration < 0) {
            std::cout << "Тривалість має бути числом більше або рівне 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            setDuration(duration);
            break;
        }
    }
}
