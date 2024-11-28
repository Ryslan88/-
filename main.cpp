#include <iostream>
#include <vector>
#include <limits>
#include "Tvarina.h"
#include "Khizhak.h"
#include "Travoidni.h"
#include "Display.h"

int main() {
    std::vector<Tvarina*> tvarini;
    int predatorCount, herbivoreCount;

    std::cout << "Скільки хижаків ви хочете додати? ";
    while (!(std::cin >> predatorCount) || predatorCount <= 0) {
        std::cout << "Введіть дійсне ціле число більше 0: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Скільки травоїдних ви хочете додати? ";
    while (!(std::cin >> herbivoreCount) || herbivoreCount <= 0) {
        std::cout << "Введіть дійсне ціле число більше 0: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < predatorCount; ++i) {
        Khizhak* khizhak = new Khizhak();
        khizhak->input();
        tvarini.push_back(khizhak);
    }
    for (int i = 0; i < herbivoreCount; ++i) {
        Travoidni* travoidni = new Travoidni();
        travoidni->input();
        tvarini.push_back(travoidni);
    }

    Display display;
    for (Tvarina* t : tvarini) {
        display.show(*t);
        display.reset(*t); // Скидання значень
        std::cout << "---------------------\n";
    }

    for (Tvarina* t : tvarini) delete t;

    return 0;
}
