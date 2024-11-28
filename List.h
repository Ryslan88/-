// List.h
#ifndef LIST_H
#define LIST_H

#include <vector>
#include <algorithm>
#include <iostream>

class List {
private:
    std::vector<int> elements;

public:
    List(); // Конструктор за замовчуванням
    List(const std::vector<int>& elems); // Конструктор з параметрами
    ~List(); // Деструктор

    bool operator>=(const List& other) const; // Порівняння списків за кількістю елементів
    void removeElement(int element); // Видалення заданого елемента зі списку

    void display() const; // Виведення елементів списку
    std::vector<int> getElements() const; // Отримання елементів списку
};

#endif
