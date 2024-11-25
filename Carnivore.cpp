#include "Carnivore.h"
#include <iostream>

void Carnivore::showInfo() const {
    std::cout << "Тварина: " << name << "\nКатегорія: " << category
              << "\nКількість їжі: " << foodAmount << " кг" << std::endl;
}
