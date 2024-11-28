#include "car.h"

int main() {
    Car car;

    car.inputCarData();
    car.displayCarData();

    car.updateCarByNumber();
    car.displayCarData();

    car.deleteCar();
    car.displayCarData();

    car.swapCars(); // Виклик обміну автомобілів місцями
    car.displayCarData();

    car.insertCarAtPosition(); // Виклик вставки автомобіля після певного номера
    car.displayCarData();

    car.clearCars();
    car.displayCarData();

    return 0;
}
 
 
