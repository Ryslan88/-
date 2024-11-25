// List.cpp
#include "List.h"

// Конструктор за замовчуванням
List::List() {}

// Конструктор з параметрами
List::List(const std::vector<int>& elems) : elements(elems) {}

// Деструктор
List::~List() {}

// Перевантаження оператора >=
bool List::operator>=(const List& other) const {
    return elements.size() >= other.elements.size();
}

// Видалення заданого елемента зі списку
void List::removeElement(int element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}

// Виведення елементів списку
void List::display() const {
    std::cout << "[ ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << "] (розмір: " << elements.size() << ")\n";
}

// Отримання елементів списку
std::vector<int> List::getElements() const {
    return elements;
}
