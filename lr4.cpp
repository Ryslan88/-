#include <iostream>
#include <string>
#include <Windows.h>
#include <limits>

using namespace std;

class Car {
private:
    string mark;
    string model;
    int year;

public:
    Car(const string& carMark, const string& carModel, int carYear)
        : mark(carMark), model(carModel), year(carYear) {}

    Car() : mark(""), model(""), year(0) {}

    void inputCarData() {
        while (true) {
            cout << "Введіть марку: ";
            getline(cin, mark);
            if (mark.empty()) {
                cout << "Поле 'Марка' не може бути порожнім. Повторіть ввід.\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Введіть модель: ";
            getline(cin, model);
            if (model.empty()) {
                cout << "Поле 'Модель' не може бути порожнім. Повторіть ввід.\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Введіть рік випуску: ";
            cin >> year;
            if (cin.fail() || year < 1886 || year > 2024) {
                cout << "Рік має бути від 1886 до 2024. Повторіть ввод.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
    }

    void printCarData() const {
        cout << "Марка: " << mark << "\nМодель: " << model << "\nРік випуску: " << year << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Car car1("Mercedes-Benz", "W124", 1990);

    Car car2;
    cout << "Введіть дані для другого автомобіля:\n";
    car2.inputCarData();

    Car car3("Mercedes-Benz", "Vito", 2023);

    cout << "\nПерший автомобіль:\n";
    car1.printCarData();

    cout << "\nДругий автомобіль:\n";
    car2.printCarData();

    cout << "\nТретій автомобіль:\n";
    car3.printCarData();

    return 0;
}

