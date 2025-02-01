// реализация пользовательского приложения
#include <Windows.h>
#include <iostream>
#include "stack.h"

void initialization() {
    SetConsoleOutputCP(CP_UTF8);
}

int main()
{
    initialization();
    Stack<int> stack(2);  // Создаем стек размером 2 (но он увеличится при необходимости)

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);  // Здесь сработает увеличение размера

    std::cout << "Верхний элемент: " << stack.Top() << std::endl;
    std::cout << "Размер стека: " << stack.Size() << std::endl;

    std::cout << "Извлекаем элементы: ";
    while (!stack.IsEmpty()) {
        std::cout << stack.Pop() << " ";
    }

    std::cout << "\nРазмер после очистки: " << stack.Size() << std::endl;

    return 0;
}
