#include <iostream>
#include <cmath>

double First(double a, double b, double x) {
    return (pow(x, 2) + pow(a, 2)) / (pow(b, 2) + 1);
}

double Second(double a, double x) {
    return pow(tan(a * x), 3);
}

double Third(double x) {
    return log(pow(sqrt(pow(x, 2) + 1), 3))
}

void calculateResult(double a, double b, double x) {
    double result;

    if (x <= 0) {
        result = First(a, b, x);
    } else if (x > 0 && x <= 3) {
        result = Second(a, x);
    } else {
        result = Third(x);
    }

    std::cout << "Відповідь: " << result << std::endl;
}

int main() {
    double a = 4;
    double b = 6;
    double x;
    
    std::cout << "Ведіть число x: ";
    std::cin >> x;

    calculateResult(a, b, x);

    return 0;
}

