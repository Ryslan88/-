#include <iostream>
#include <cmath>
#include <stdexcept> // Для обробки винятків

using namespace std;

// Нова функція для обчислення виразу
double calculateY(double x, double a, double b) {
    // Перевірка на допустимість значень для уникнення ділення на нуль і некоректних обчислень
    if (sin(b * x) == 0) {
        throw invalid_argument("Ділення на нуль: sin(b * x) = 0.");
    }
    if (x / a <= 0) {
        throw invalid_argument("Корінь з від'ємного числа: x / a <= 0.");
    }

    // Обчислення значення y
    double numerator = (pow(x, 2) + 1) - (1 / sin(b * x)); // Чисельник
    double denominator = cbrt(x / a) - 0.39;              // Знаменник
    if (denominator == 0) {
        throw invalid_argument("Ділення на нуль: знаменник = 0.");
    }

    return numerator / denominator;
}

// Функція для обчислення значень у циклі
void Values(double x1, double x2, double h, double a, double b, double &sum, int &count) {
    for (double x = x1; x <= x2; x += h) {
        try {
            double y = calculateY(x, a, b);

            if (y > 1) {
                sum += y;
                count++;
            }
        } catch (const invalid_argument& e) {
            cerr << "Помилка для x = " << x << ": " << e.what() << endl;
        }
    }
}

int main() {
    double x1 = 0.2;
    double x2 = 1.6;
    double h = 0.1;
    double a = 0.36;
    double b = 0.74;

    double sum = 0;
    int count = 0;

    // Виклик функції
    Values(x1, x2, h, a, b, sum, count);

    // Виведення результатів
    cout << "Сума значень y > 1: " << sum << endl;
    cout << "Кількість значень y > 1: " << count << endl;

    return 0;
}

