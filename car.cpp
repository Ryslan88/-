#include <iostream>
#include <vector>
#include <limits>
#include "car.h"

Car::Car() {}

Car::~Car() {}

void Car::inputCarData() {
    int numberOfCars;
    std::cout << "Введіть кількість автомобілів для додавання: ";
    std::cin >> numberOfCars;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numberOfCars; ++i) {
        car_s_t car;
        std::cout << "Введіть дані для автомобіля " << (i + 1) << ":\n";

        while (true) {
            std::cout << "Марка: ";
            std::getline(std::cin, car.make);
            if (!car.make.empty()) break;
            std::cout << "Марка не може бути порожньою. Спробуйте ще раз.\n";
        }

        while (true) {
            std::cout << "Модель: ";
            std::getline(std::cin, car.model);
            if (!car.model.empty()) break;
            std::cout << "Модель не може бути порожньою. Спробуйте ще раз.\n";
        }

        std::cout << "Рік випуску: ";
        while (true) {
            std::cin >> car.year;
            if (car.year < 1886) {
                std::cout << "Рік випуску не може бути менше 1886. Введіть рік знову: ";
            } else if (car.year > 2024) {
                std::cout << "Рік випуску не може бути більше 2024. Введіть рік знову: ";
            } else {
                break;
            }
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cars.push_back(car);
    }
}

void Car::displayCarData() const {
    if (cars.empty()) {
        std::cout << "Немає даних про автомобілі.\n";
        return;
    }

    std::cout << "\nДані автомобілів:\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        std::cout << "Автомобіль " << (i + 1) << ": "
                  << "Марка: " << cars[i].make
                  << ", Модель: " << cars[i].model
                  << ", Рік випуску: " << cars[i].year << "\n";
    }
}

void Car::updateCarByNumber() {
    int carNumber;
    while (true) {
        std::cout << "Введіть номер автомобіля для оновлення: ";
        std::cin >> carNumber;

        if (carNumber < 1 || carNumber > cars.size()) {
            std::cout << "Неправильний номер автомобіля. Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    car_s_t& car = cars[carNumber - 1];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Оновлення даних для автомобіля " << carNumber << ":\n";

    while (true) {
        std::cout << "Нова марка (залиште порожнім для пропуску): ";
        std::string newMake;
        std::getline(std::cin, newMake);
        if (newMake.empty()) break;
        car.make = newMake;
        break;
    }

    while (true) {
        std::cout << "Нова модель (залиште порожнім для пропуску): ";
        std::string newModel;
        std::getline(std::cin, newModel);
        if (newModel.empty()) break;
        car.model = newModel;
        break;
    }

    std::cout << "Новий рік випуску (залиште порожнім для пропуску): ";
    std::string newYearInput;
    std::getline(std::cin, newYearInput);
    if (!newYearInput.empty()) {
        int newYear = std::stoi(newYearInput);
        if (newYear >= 1886 && newYear <= 2024) {
            car.year = newYear;
        } else {
            std::cout << "Рік випуску не може бути менше 1886 або більше 2024. Оновлення не виконано.\n";
        }
    }

    std::cout << "Дані автомобіля оновлено.\n";
}

void Car::deleteCar() {
    int number;
    while (true) {
        std::cout << "Введіть номер автомобіля для видалення (1-" << cars.size() << "): ";
        std::cin >> number;

        if (number < 1 || number > cars.size()) {
            std::cout << "Некоректний номер. Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    cars.erase(cars.begin() + (number - 1));
    std::cout << "Автомобіль " << number << " успішно видалений.\n";
}

void Car::swapCars() {
    int index1, index2;
    while (true) {
        std::cout << "Введіть номер першого автомобіля для обміну: ";
        std::cin >> index1;
        std::cout << "Введіть номер другого автомобіля для обміну: ";
        std::cin >> index2;

        if (index1 < 1 || index1 > cars.size() || index2 < 1 || index2 > cars.size()) {
            std::cout << "Некоректні номери. Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    std::swap(cars[index1 - 1], cars[index2 - 1]);
    std::cout << "Автомобілі " << index1 << " та " << index2 << " успішно обміняно місцями.\n";
}

void Car::insertCarAtPosition() {
    int position;
    while (true) {
        std::cout << "Введіть номер автомобіля після якого потрібно додати новий (0-" << cars.size() << "): ";
        std::cin >> position;

        if (position < 0 || position > cars.size()) {
            std::cout << "Некоректний номер. Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    car_s_t car;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        std::cout << "Марка: ";
        std::getline(std::cin, car.make);
        if (!car.make.empty()) break;
        std::cout << "Марка не може бути порожньою. Спробуйте ще раз.\n";
    }

    while (true) {
        std::cout << "Модель: ";
        std::getline(std::cin, car.model);
        if (!car.model.empty()) break;
        std::cout << "Модель не може бути порожньою. Спробуйте ще раз.\n";
    }

    std::cout << "Рік випуску: ";
    while (true) {
        std::cin >> car.year;
        if (car.year < 1886) {
            std::cout << "Рік випуску не може бути менше 1886. Введіть рік знову: ";
        } else if (car.year > 2024) {
            std::cout << "Рік випуску не може бути більше 2024. Введіть рік знову: ";
        } else {
            break;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cars.insert(cars.begin() + position, car);
    std::cout << "Новий автомобіль успішно доданий після автомобіля " << position + 1 << ".\n";
}

void Car::clearCars() {
    cars.clear();
    std::cout << "Всі дані автомобілів успішно очищені.\n";
}
