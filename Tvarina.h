#ifndef TVARINA_H
#define TVARINA_H

#include <string>

class Display;

class Tvarina {
protected:
    std::string name; // Назва тварини
    double age;       // Вік
    int duration;     // Тривалість життя

public:
    Tvarina(std::string n = "", double a = 0.0, int d = 0);
    virtual ~Tvarina();

    friend class Display; // Дружній клас

    virtual void display() const = 0; // Чисто віртуальний метод
    virtual void input();             // Метод для введення даних
};

#endif
