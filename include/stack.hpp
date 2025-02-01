#ifndef STACK_HPP
#define STACK_HPP

#include "stack.h"

// Конструктор
template <typename T>
Stack<T>::Stack(int size) {
    if (size <= 0) throw std::invalid_argument("Размер стека должен быть положительным");
    capacity = size;
    data = new T[capacity];
    top = -1; // Стек пуст
}

//Деструктор
template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

//Увеличение размера стека (удваиваем при необходимости)
template <typename T>
void Stack<T>::Resize() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];

    for (int i = 0; i <= top; i++)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Добавление элемента в стек
template <typename T>
void Stack<T>::Push(T value) {
    if (top + 1 == capacity) // Если стек заполнен, увеличиваем размер
        Resize();
    data[++top] = value;
}

// Удаление и возврат верхнего элемента
template <typename T>
T Stack<T>::Pop() {
    if (IsEmpty()) throw std::underflow_error("Стек пуст");
    return data[top--];
}

// Просмотр верхнего элемента без удаления
template <typename T>
T Stack<T>::Top() const {
    if (IsEmpty()) throw std::underflow_error("Стек пуст");
    return data[top];
}

// Проверка, пуст ли стек
template <typename T>
bool Stack<T>::IsEmpty() const {
    return top == -1;
}

// Получение количества элементов в стеке
template <typename T>
int Stack<T>::Size() const {
    return top + 1;
}

// Очистка стека
template <typename T>
void Stack<T>::Clear() {
    top = -1;
}

#endif // STACK_HPP
