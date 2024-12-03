#include "automobile.h"
#include <iostream>
#include <limits>

// Конструктор класу Automobile: встановлює кількість автомобілів на 0
Automobile::Automobile() : count(0) {
    initializeAutomobiles();
}

// Деструктор класу Automobile
Automobile::~Automobile() {}

// Ініціалізація масиву автомобілів за замовчуванням
void Automobile::initializeAutomobiles() {
    for (int i = 0; i < SIZE; ++i) {
        automobiles[i] = {"", "", 0};
    }
    count = 0;
}

// Виведення даних про автомобілі
void Automobile::displayAutomobileData() const {
    if (count == 0) {
        std::cout << "Немає даних про автомобілі.\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        std::cout << "Автомобіль " << (i + 1) << ":\n";
        std::cout << "Марка: " << automobiles[i].brand << "\n";
        std::cout << "Модель: " << automobiles[i].model << "\n";
        std::cout << "Рік: " << automobiles[i].year << "\n";
    }
}

// Перевірка даних автомобіля
void Automobile::validateAutomobileData(automobile_s_t& autoData) const {
    if (autoData.brand.empty() || autoData.model.empty() || 
        autoData.year < 1886 || autoData.year > 2024) {
        throw std::invalid_argument("Дані автомобіля некоректні.");
    }
}

// Введення даних про автомобілі
void Automobile::inputAutomobileData() {
    for (int i = count; i < SIZE; ++i) {
        std::cout << "Введіть дані для автомобіля " << (i + 1) << ":\n";
        automobile_s_t autoData;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Марка: ";
        std::getline(std::cin, autoData.brand);

        std::cout << "Модель: ";
        std::getline(std::cin, autoData.model);

        std::cout << "Рік випуску: ";
        while (!(std::cin >> autoData.year) || autoData.year < 1886 || autoData.year > 2024) {
            std::cout << "Некоректний рік. Введіть ще раз: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        validateAutomobileData(autoData); // Валідація введених даних

        automobiles[i] = autoData; // Збереження даних
        count++; // Збільшення кількості автомобілів
    }
}

// Оновлення даних автомобіля за номером
void Automobile::updateAutomobileByNumber() {
    int number;
    std::cout << "Введіть номер автомобіля для оновлення (1-" << count << "): ";
    std::cin >> number;

    if (number < 1 || number > count) {
        std::cout << "Некоректний номер.\n";
        return;
    }

    int index = number - 1;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Оновлення даних автомобіля " << number << ":\n";

    std::cout << "Марка: ";
    std::getline(std::cin, automobiles[index].brand);

    std::cout << "Модель: ";
    std::getline(std::cin, automobiles[index].model);

    std::cout << "Рік випуску: ";
    while (!(std::cin >> automobiles[index].year) || automobiles[index].year < 1886 || automobiles[index].year > 2024) {
        std::cout << "Некоректний рік. Введіть ще раз: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Пошук автомобіля
void Automobile::searchAutomobile() {
    std::string searchBrand;
    std::cout << "Введіть марку автомобіля для пошуку: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, searchBrand);

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (automobiles[i].brand == searchBrand) {
            std::cout << "Знайдено автомобіль:\n";
            std::cout << "Марка: " << automobiles[i].brand << "\n";
            std::cout << "Модель: " << automobiles[i].model << "\n";
            std::cout << "Рік: " << automobiles[i].year << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Автомобіль з маркою \"" << searchBrand << "\" не знайдено.\n";
    }
}
