#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <array>
#include <iostream>
#include <string>

// Максимальна кількість автомобілів
const int SIZE = 5;

struct automobile_s_t {
    std::string brand; // Бренд автомобіля
    std::string model; // Модель автомобіля
    int year;          // Рік випуску
};

class Automobile {
private:
    std::array<automobile_s_t, SIZE> automobiles; // Масив автомобілів
    int count; // Фактична кількість автомобілів

public:
    Automobile();  // Конструктор
    ~Automobile(); // Деструктор
    
    void initializeAutomobiles(); // Ініціалізація автомобілів за замовчуванням
    void inputAutomobileData();   // Введення даних про автомобілі
    void displayAutomobileData() const; // Виведення даних про автомобілі
    void updateAutomobileByNumber();    // Оновлення даних автомобіля за номером
    void validateAutomobileData(automobile_s_t& autoData) const; // Валідація даних автомобіля
    void searchAutomobile(); // Пошук автомобіля
};

#endif // AUTOMOBILE_H
