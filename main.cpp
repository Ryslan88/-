#include <iostream>
#include "Tvarina.h"
#include "Khizhak.h"

int main() {
    // Створюємо об'єкт хижака
    Khizhak khizhak("Тигр", 1500.0, 5, 100);

    // Виводимо дані про хижака
    khizhak.display();

    // Вводимо нові дані для хижака
    std::cout << "Введіть нові дані для хижака:" << std::endl;
    khizhak.input();

    // Виводимо оновлені дані
    khizhak.display();

    return 0;
}
