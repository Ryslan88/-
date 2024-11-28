#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <fstream>

class Animal {
protected:
    std::string name;
    std::string food;

public:
    Animal(const std::string& name = "", const std::string& food = "") : name(name), food(food) {}
    virtual ~Animal() {}

    virtual void showInfo() const = 0; // Чисто віртуальний метод для виведення інформації
    virtual void saveToFile(std::ofstream& ofs) const = 0; // Віртуальний метод для запису у файл
    virtual void loadFromFile(std::ifstream& ifs) = 0; // Віртуальний метод для читання з файлу
};

#endif // ANIMAL_H
