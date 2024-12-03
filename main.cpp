#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "CarnivorousAnimal.h"
#include "HerbivorousAnimal.h"
#include "Animal.h"

// Функція для перевірки, чи рядок не є порожнім
bool isValidName(const std::string& name) {
    return !name.empty();
}

// Функція для перевірки, чи їжа є валідною (не порожня і не містить цифр)
bool isValidFood(const std::string& food) {
    if (food.empty()) return false;
    for (char c : food) {
        if (std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Функція для збереження даних у файл
void saveToFile(const std::string& filename, const std::vector<Animal*>& animals) {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Не вдалося відкрити файл для запису.\n";
        return;
    }
    for (const auto& animal : animals) {
        animal->saveToFile(ofs);
    }
    ofs.close();
    std::cout << "Дані успішно збережено у файл.\n";
}

// Функція для завантаження даних з файлу
void loadFromFile(const std::string& filename, std::vector<Animal*>& animals) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Не вдалося відкрити файл для читання.\n";
        return;
    }

    std::string type;
    while (std::getline(ifs, type)) {
        if (type == "Carnivorous") {
            Animal* animal = new CarnivorousAnimal();
            animal->loadFromFile(ifs);
            animals.push_back(animal);
        } else if (type == "Herbivorous") {
            Animal* animal = new HerbivorousAnimal();
            animal->loadFromFile(ifs);
            animals.push_back(animal);
        }
    }
    ifs.close();
    std::cout << "Дані успішно завантажено з файлу.\n";
}

// Функція для введення нових тварин
void addAnimal(std::vector<Animal*>& animals) {
    int choice;

    while (true) {
        std::cout << "Оберіть тип тварини для додавання:\n";
        std::cout << "1. Хижа тварина\n";
        std::cout << "2. Травоїдна тварина\n";
        std::cin >> choice;

        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cout << "Невірний вибір. Будь ласка, введіть 1 або 2.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cin.ignore(); // Очищення буфера вводу

    std::string name;
    std::string food;
    int count;

    while (true) {
        std::cout << "Введіть назву тварини: ";
        std::getline(std::cin, name);
        if (isValidName(name)) {
            break;
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }

    while (true) {
        std::cout << "Введіть їжу, яку споживає тварина: ";
        std::getline(std::cin, food);
        if (isValidFood(food)) {
            break;
        } else {
            std::cout << "Їжа не може бути порожньою або складатися лише з цифр. Спробуйте ще раз.\n";
        }
    }

    while (true) {
        std::cout << "Введіть кількість їжі: ";
        std::cin >> count;
        if (count > 0) {
            break;
        } else {
            std::cout << "Кількість має бути більшою за 0. Спробуйте ще раз.\n";
        }
    }

    if (choice == 1) {
        animals.push_back(new CarnivorousAnimal(name, food, count));
    } else if (choice == 2) {
        animals.push_back(new HerbivorousAnimal(name, food, count));
    }
}

int main() {
    std::vector<Animal*> animals;
    std::string filename = "animals.txt";  // Тут була проблема, в попередньому коді відсутній правильний ініціалізатор

    int option;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Додати нову тварину\n";
        std::cout << "2. Вивести інформацію про всіх тварин\n";
        std::cout << "3. Зберегти дані у файл\n";
        std::cout << "4. Завантажити дані з файлу\n";
        std::cout << "5. Вийти\n";

        std::string input;
        std::getline(std::cin, input);

        try {
            option = std::stoi(input);  // Преобразуємо в ціле число
        } catch (const std::invalid_argument& e) {
            std::cout << "Помилка: введено нечислове значення. Спробуйте ще раз.\n";
            continue;
        } catch (const std::out_of_range& e) {
            std::cout << "Помилка: число виходить за межі допустимого діапазону.\n";
            continue;
        }

        switch (option) {
            case 1:
                addAnimal(animals);
                break;
            case 2:
                for (const auto& animal : animals) {
                    animal->showInfo();
                }
                break;
            case 3:
                saveToFile(filename, animals);
                break;
            case 4:
                loadFromFile(filename, animals);
                break;
            case 5:
                std::cout << "Вихід...\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    } while (option != 5);

    // Очищення пам'яті
    for (auto animal : animals) {
        delete animal;
    }

    return 0;
}
