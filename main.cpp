// main.cpp
#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include "List.h"

int main() {
    // Масив списків
    List lists[] = {
        List({1, 2, 3}),
        List({4, 5}),
        List({6, 7, 8, 9}),
        List({10})
    };

    int n = sizeof(lists) / sizeof(lists[0]);

    // Виведення початкових списків
    std::cout << "Початкові списки:\n";
    for (int i = 0; i < n; ++i) {
        lists[i].display();
    }

    // Сортування списків за спаданням кількості елементів
    std::sort(lists, lists + n, [](const List& l1, const List& l2) {
        return l1 >= l2; // Використовуємо перевантажений оператор >=
    });

    std::cout << "\nВідсортовані списки за спаданням кількості елементів:\n";
    for (int i = 0; i < n; ++i) {
        lists[i].display();
    }

    // Знаходимо список з найменшою кількістю елементів
    List smallest = lists[n - 1];

    // Вилучення елементів з усіх списків, які є у найменшому списку
    for (int i = 0; i < n; ++i) {
        for (int elem : smallest.getElements()) {
            lists[i].removeElement(elem); // Використовуємо метод для вилучення елементів
        }
    }

    std::cout << "\nСписки після вилучення елементів найменшого списку:\n";
    for (int i = 0; i < n; ++i) {
        lists[i].display();
    }

    return 0;
}
