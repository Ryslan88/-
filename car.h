#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <vector>
#include <string>

struct car_s_t {
    std::string make;
    std::string model;
    int year;
};

class Car {
private:
    std::vector<car_s_t> cars;

public:
    Car();
    ~Car();

    void inputCarData();
    void displayCarData() const;
    void updateCarByNumber();
    void deleteCar();
    void clearCars();
    void swapCars(); // Метод для обміну автомобілів
    void insertCarAtPosition(); // Метод для вставки автомобіля в позицію
};

#endif // CAR_H
