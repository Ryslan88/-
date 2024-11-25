#include <iostream>
#include <vector>
#include <limits>
#include "Hizhak.h"
#include "Travoyidni.h"
#include "Tvaryna.h"

int main() {
    std::vector<Tvaryna*> tvaryny;
    int hizhakCount = 0, travoyidniCount = 0;
    int totalHizhakFood = 0, totalTravoyidniFood = 0;

    // Запитуємо кількість хижих тварин
    while (true) {
        std::cout << "Скільки хижих тварин ви хочете додати? ";
        std::cin >> hizhakCount;
        if (std::cin.fail() || hizhakCount < 1) {
            std::cout << "Кількість повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Запитуємо кількість травоїдних тварин
    while (true) {
        std::cout << "Скільки травоїдних тварин ви хочете додати? ";
        std::cin >> travoyidniCount;
        if (std::cin.fail() || travoyidniCount < 1) {
            std::cout << "Кількість повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Введення даних для хижих тварин
    for (int i = 0; i < hizhakCount; i++) {
        std::cout << "\nВведення даних для хижої тварини №" << (i + 1) << ":\n";
        Hizhak* h = new Hizhak();
        h->input();
        tvaryny.push_back(h);
    }

    // Введення даних для травоїдних тварин
    for (int i = 0; i < travoyidniCount; i++) {
        std::cout << "\nВведення даних для травоїдної тварини №" << (i + 1) << ":\n";
        Travoyidni* t = new Travoyidni();
        t->input();
        tvaryny.push_back(t);
    }

    // Обробка та виведення даних
    for (const auto& t : tvaryny) {
        t->display();
        std::cout << "---------------------\n";

        if (auto h = dynamic_cast<Hizhak*>(t)) {
            totalHizhakFood += h->getFoodAmount();
        } else if (auto tr = dynamic_cast<Travoyidni*>(t)) {
            totalTravoyidniFood += tr->getFoodAmount();
        }
    }

    std::cout << "Загальна кількість їжі для хижаків: " << totalHizhakFood << " кг\n";
    std::cout << "Загальна кількість їжі для травоїдних: " << totalTravoyidniFood << " кг\n";

    for (auto& t : tvaryny) {
        delete t;
    }

    return 0;
}
