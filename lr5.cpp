#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Automobile {
private:
    string brand;
    string model;
    int year;

public:
    Automobile(string autoBrand = "Unknown", string autoModel = "Unknown", int autoYear = 2000)
        : brand(autoBrand), model(autoModel), year(autoYear) {
        if (year < 1886) {
            cout << "Помилка. Рік не може бути меншим за 1886. Встановлено за замовчуванням 2000 рік." << endl;
            year = 2000;
        }
    }

    void input() {
        cout << "Введіть марку: ";
        getline(cin, brand);
        cout << "Введіть модель: ";
        getline(cin, model);
        cout << "Введіть рік випуску: ";
        cin >> year;
        cin.ignore();
        if (year < 1886) {
            cout << "Помилка. Рік не може бути меншим за 1886. Встановлено за замовчуванням 2000 рік." << endl;
            year = 2000;
        }
    }

    void display() const {
        cout << "Марка: " << brand << ", Модель: " << model << ", Рік випуску: " << year << endl;
    }

    int getYear() const {
        return year;
    }

    string getModel() const {
        return model;
    }
};

void displayByYear(const vector<Automobile>& automobiles, int yearCriteria) {
    bool found = false;
    for (const auto& autoObj : automobiles) {
        if (autoObj.getYear() > yearCriteria) {
            autoObj.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Не знайдено автомобілів, рік випуску яких більший за " << yearCriteria << "." << endl;
    }
}

void displayByModel(const vector<Automobile>& automobiles, const string& modelCriteria) {
    bool found = false;
    for (const auto& autoObj : automobiles) {
        if (autoObj.getModel() == modelCriteria) {
            autoObj.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Не знайдено автомобілів з моделлю: " << modelCriteria << "." << endl;
    }
}

int main() {
    Automobile auto1("Toyota", "Camry", 2010);
    Automobile auto2("Honda", "Civic", 2015);
    Automobile auto3;

    auto1.display();
    auto2.display();
    auto3.input();
    auto3.display();

    vector<Automobile> automobiles = {auto1, auto2, auto3};

    int choice;
    cout << "Фільтрувати за: 1 - Роком випуску, 2 - Моделлю. Виберіть: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        int yearCriteria;
        cout << "Введіть рік для фільтру: ";
        cin >> yearCriteria;
        displayByYear(automobiles, yearCriteria);
    } else if (choice == 2) {
        string modelCriteria;
        cout << "Введіть назву моделі для фільтру: ";
        cin >> modelCriteria;
        displayByModel(automobiles, modelCriteria);
    } else {
        cout << "Невірний вибір!" << endl;
    }

    return 0;
}

