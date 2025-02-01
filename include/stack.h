﻿// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память


#ifndef STACK_H
#define STACK_H

#include <stdexcept>  // Для обработки ошибок

template <typename T>
class Stack {
private:
    T* data;        // Динамический массив для хранения элементов
    int capacity;   // Максимальный размер стека
    int top;        // Индекс верхнего элемента (-1, если стек пуст)

    void Resize();  // Увеличение размера стека

public:
    explicit Stack(int size = 10);  // Конструктор
    ~Stack();  // Деструктор

    void Push(T value);  // Вставка элемента
    T Pop();             // Извлечение элемента
    T Top() const;       // Просмотр верхнего элемента (без удаления)
    bool IsEmpty() const; // Проверка на пустоту
    int Size() const;     // Получение количества элементов
    void Clear();         // Очистка стека
};

#include "stack.hpp" // Подключаем реализацию шаблонных методов
#endif // STACK_H
