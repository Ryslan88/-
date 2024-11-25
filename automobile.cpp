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
void Automobile::initializeAutomobiles() {
    automobiles[0] = {"BMW", "m5", 2010};
    automobiles[1] = {"Volkswagen", "Caddy", 2005};
    automobiles[2] = {"Ford", "Mustang", 2020};
    count = 3; // Встановити фактичну кількість автомобілів
}

// Метод для введення даних про автомобілі
void Automobile::inputAutomobileData() {
    for (int i = count; i < SIZE; ++i) {
        std::cout << "Введіть дані для автомобіля " << (i + 1) << ":\n";
        automobile_s_t autoData;
        
        std::cout << "Марка: ";
        std::getline(std::cin, autoData.brand);

        std::cout << "Модель: ";
        std::getline(std::cin, autoData.model);

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

// Метод для виведення даних про всі автомобілі
void Automobile::displayAutomobileData() const {
    std::cout << "\nДані автомобілів:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "Автомобіль " << (i + 1) << ": "
                  << "Марка: " << automobiles[i].brand
                  << ", Модель: " << automobiles[i].model
                  << ", Рік випуску: " << automobiles[i].year << "\n";
    }
}

// Метод для оновлення даних автомобіля за його номером
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
    
    std::cout << "Марка: ";
    std::getline(std::cin, autoData.brand);

    std::cout << "Модель: ";
    std::getline(std::cin, autoData.model);

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

// Метод для валідації (перевірки) введених даних про автомобіль
void Automobile::validateAutomobileData(automobile_s_t& autoData) const {
    if (autoData.brand.empty() || autoData.model.empty()) {
        std::cout << "Некоректна марка або модель. Поля не повинні бути пустими.\n";
    }
}

// Метод для пошуку автомобілів за певними критеріями
void Automobile::searchAutomobile() {
    int choice;
    std::cout << "Шукати за:\n1. Роком випуску\n2. Моделлю\nВведіть вибір: ";
    std::cin >> choice;

    if (choice == 1) {
        int year;
        std::cout << "Введіть рік для пошуку: ";
        std::cin >> year;

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (automobiles[i].year == year) {
                std::cout << "Автомобіль " << (i + 1) << ": "
                          << "Марка: " << automobiles[i].brand
                          << ", Модель: " << automobiles[i].model
                          << ", Рік випуску: " << automobiles[i].year << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "Немає жодного автомобіля з таким роком випуску.\n";
        }
    } else if (choice == 2) {
        std::string model;
        std::cout << "Введіть модель для пошуку: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, model);

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (automobiles[i].model == model) {
                std::cout << "Автомобіль " << (i + 1) << ": "
                          << "Марка: " << automobiles[i].brand
                          << ", Модель: " << automobiles[i].model
                          << ", Рік випуску: " << automobiles[i].year << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "Немає жодного автомобіля з такою моделлю.\n";
        }
    } else {
        std::cout << "Некоректний вибір.\n";
    }
}
