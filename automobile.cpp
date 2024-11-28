#include "automobile.h"
#include <iostream>
#include <limits>

// Конструктор класу Automobile: встановлює кількість автомобілів на 0
// та ініціалізує автомобілі за замовчуванням
Automobile::Automobile() : count(0) {
    initializeAutomobiles(); // Ініціалізувати автомобілі
}

// Деструктор класу Automobile (не виконує спеціальних дій)
Automobile::~Automobile() {}

// Ініціалізація масиву автомобілів за замовчуванням
void Automobile::inputAutomobileData() {
    for (int i = count; i < SIZE; ++i) {
        std::cout << "Введіть дані для автомобіля " << (i + 1) << ":\n";
        automobile_s_t autoData;
        
        while (true) {
            std::cout << "Марка: ";
            std::getline(std::cin, autoData.brand);
            if (autoData.brand.empty()) {
                std::cout << "Марка не може бути порожньою. Введіть ще раз.\n";
            } else {
                break;
            }
        }

        while (true) {
            std::cout << "Модель: ";
            std::getline(std::cin, autoData.model);
            if (autoData.model.empty()) {
                std::cout << "Модель не може бути порожньою. Введіть ще раз.\n";
            } else {
                break;
            }
        }

        while (true) {
            std::cout << "Рік випуску: ";
            if (!(std::cin >> autoData.year)) {
                std::cout << "Невірне значення. Введіть числове значення року.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (autoData.year < 1886 || autoData.year > 2024) {
                std::cout << "Невірний рік, введіть ще раз.\n";
            } else {
                break;
            }
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        validateAutomobileData(autoData); // Перевірка правильності введених даних

        automobiles[i] = autoData; // Збереження даних в масив
        count++; // Збільшення кількості автомобілів
    }
}

void Automobile::updateAutomobileByNumber() {
    int number;
    std::cout << "Введіть номер автомобіля для оновлення (1-" << count << "): ";
    std::cin >> number;

    if (number < 1 || number > count) {
        std::cout << "Некоректний номер.\n";
        return;
    }

    automobile_s_t autoData;
    int index = number - 1;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Оновлення даних автомобіля " << number << ":\n";

    while (true) {
        std::cout << "Марка: ";
        std::getline(std::cin, autoData.brand);
        if (autoData.brand.empty()) {
            std::cout << "Марка не може бути порожньою. Введіть ще раз.\n";
        } else {
            break;
        }
    }

    while (true) {
        std::cout << "Модель: ";
        std::getline(std::cin, autoData.model);
        if (autoData.model.empty()) {
            std::cout << "Модель не може бути порожньою. Введіть ще раз.\n";
        } else {
            break;
        }
    }

    while (true) {
        std::cout << "Рік випуску: ";
        if (!(std::cin >> autoData.year)) {
            std::cout << "Невірне значення. Введіть числове значення року.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (autoData.year < 1886 || autoData.year > 2024) {
            std::cout << "Невірний рік, введіть ще раз.\n";
        } else {
            break;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    validateAutomobileData(autoData); // Перевірка правильності введених даних

    automobiles[index] = autoData; // Оновлення даних в масиві
}
