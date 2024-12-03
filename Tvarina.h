#ifndef TVARINA_H
#define TVARINA_H

#include <string>
#include <iostream>

class Tvarina {
protected:
    std::string name;
    double cost;
    int days;

public:
    Tvarina(std::string n = "", double c = 0.0, int d = 0)
        : name(n), cost(c), days(d) {}

    virtual ~Tvarina() {}

    virtual void display() const {
        std::cout << "Ім'я: " << name << '\n';
        std::cout << "Вартість: " << cost << '\n';
        std::cout << "Дні: " << days << '\n';
    }

    virtual void input() {
        std::cout << "Введіть ім'я: ";
        std::cin >> name;
        std::cout << "Введіть вартість: ";
        std::cin >> cost;
        std::cout << "Введіть кількість днів: ";
        std::cin >> days;
    }
};

#endif
