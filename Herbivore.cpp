#include "Herbivore.h"
#include <iostream>

void Herbivore::showInfo() const {
    std::cout << "Тварина: " << name << "\nКатегорія: " << category
              << "\nКількість їжі: " << foodAmount << " кг" << std::endl;
}
