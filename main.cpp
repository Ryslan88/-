#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Carnivore.h"
#include "Herbivore.h"
#include "Carnivore.cpp"
#include "Herbivore.cpp"

// Функція для перевірки правильності введеного числа
bool isValidChoice(int choice) {
    return (choice >= 1 && choice <= 3); // Перевірка, чи вибір у межах 1-3
}

// Функція для перевірки, чи є введене значення числом
bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isValidPositiveNumber(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return std::stoi(str) > 0;
}

void addAnimal(std::vector<Animal*>& animals) {
    int choice;

    while (true) {
        std::cout << "Оберіть тип тварини для додавання:\n";
        std::cout << "1. Хижак\n";
        std::cout << "2. Травоїдне\n";
        std::cin >> choice;

        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cout << "Невірний вибір. Введіть 1 або 2.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cin.ignore(); // Очищення буфера вводу перед використанням getline

    std::string name;
    std::string foodAmountStr;

    while (true) {
        std::cout << "Введіть ім'я тварини: ";
        std::getline(std::cin, name);
        if (!name.empty()) {
            break;
        } else {
            std::cout << "Ім'я не може бути порожнім. Спробуйте ще раз.\n";
        }
    }

    while (true) {
        std::cout << "Введіть кількість їжі (кг): ";
        std::getline(std::cin, foodAmountStr);
        if (isValidPositiveNumber(foodAmountStr)) {
            break;
        } else {
            std::cout << "Кількість їжі має бути дійсним числом більше 0. Спробуйте ще раз.\n";
        }
    }

    int foodAmount = std::stoi(foodAmountStr);

    if (choice == 1) {
        animals.push_back(new Carnivore(name, foodAmount));
    } else if (choice == 2) {
        animals.push_back(new Herbivore(name, foodAmount));
    }
}

int main() {
    std::vector<Animal*> animals;

    animals.push_back(new Carnivore("Лев", 20));
    animals.push_back(new Herbivore("Жираф", 15));

    int option;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Додати нову тварину\n";
        std::cout << "2. Вивести інформацію про всіх тварин\n";
        std::cout << "3. Вийти\n";

        std::string input;
        std::cin >> input;

        // Перевірка, чи введене значення є числом
        if (!isNumber(input)) {
            std::cout << "Невірний вибір. Введіть число 1, 2 або 3.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення буфера
            continue;
        }

        option = std::stoi(input);

        // Перевірка, чи вибір в межах допустимих
        if (!isValidChoice(option)) {
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            continue;
        }

        switch (option) {
            case 1:
                addAnimal(animals); // Додавання нової тварини
                break;
            case 2:
                std::cout << "\nІнформація про тварин:\n";
                for (const auto& animal : animals) {
                    animal->showInfo(); // Виведення інформації про тварину
                    std::cout << "-----------------------\n";
                }
                break;
            case 3:
                std::cout << "Вихід...\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    } while (option != 3);

    // Звільнення пам'яті
    for (auto& animal : animals) {
        delete animal;
    }

    return 0;
}
