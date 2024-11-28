#include <iostream>
#include <vector>
#include <limits>
#include "Tvarina.h"
#include "Khizhak.h"
#include "Travoidni.h"
#include "Display.h"

int main() {
    std::vector<Tvarina*> tvarini;
    int predatorCount = 0, herbivoreCount = 0;

    // Введення кількості хижаків
    while (true) {
        std::cout << "Скільки хижаків ви хочете додати? ";
        std::cin >> predatorCount;
        if (std::cin.fail() || predatorCount <= 0) {
            std::cout << "Введіть дійсне ціле число більше 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Введення кількості травоїдних
    while (true) {
        std::cout << "Скільки травоїдних ви хочете додати? ";
        std::cin >> herbivoreCount;
        if (std::cin.fail() || herbivoreCount <= 0) {
            std::cout << "Введіть дійсне ціле число більше 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Введення хижаків
    for (int i = 0; i < predatorCount; i++) {
        std::cout << "\nВведення даних для хижака №" << (i + 1) << ":\n";
        Khizhak* khizhak = new Khizhak();
        khizhak->input();
        tvarini.push_back(khizhak);
    }

    // Введення травоїдних
    for (int i = 0; i < herbivoreCount; i++) {
        std::cout << "\nВведення даних для травоїдної №" << (i + 1) << ":\n";
        Travoidni* travoidni = new Travoidni();
        travoidni->input();
        tvarini.push_back(travoidni);
    }

    Display display;

    // Виведення даних
    for (const auto& t : tvarini) {
        display.show(*t);
        if (auto* khizhak = dynamic_cast<Khizhak*>(t)) {
            display.showPredatorInfo(*khizhak);
            display.resetPredatorStrength(*khizhak); // Скидаємо силу хижака
        } else if (auto* travoidni = dynamic_cast<Travoidni*>(t)) {
            display.showHerbivoreInfo(*travoidni);
            display.resetHerbivoreWeight(*travoidni); // Скидаємо вагу травоїдної
        }
        std::cout << "---------------------\n";
    }

    // Очищення пам'яті
    for (auto t : tvarini) {
        delete t;
    }

    return 0;
}
