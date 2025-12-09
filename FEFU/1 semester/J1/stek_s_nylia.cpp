#include <iostream>
using namespace std;

class Stack {
private:
    int arr[5];     // Массив для хранения элементов стека (ёмкость 5)
    int topIndex;   // Индекс верхнего элемента

public:
    // Конструктор: инициализация стека
    Stack() {
        topIndex = -1; // Изначально стек пуст
    }

    // Операция push: добавление элемента в стек
    void push(int value) {
        if (topIndex == 4) { // Если индекс стал равен 4, стек заполнен
            cout << "Stack overflow!" << endl;
            return;
        }
        topIndex++;           // Увеличиваем индекс
        arr[topIndex] = value; // Добавляем элемент
    }

    // Операция pop: удаление верхнего элемента
    void pop() {
        if (topIndex == -1) { // Если стек пуст
            cout << "Stack underflow!" << endl;
            return;
        }
        topIndex--; // Просто уменьшаем индекс
    }

    // Операция top: получаем верхний элемент
    int top() {
        if (topIndex == -1) { // Если стек пуст
            cout << "Stack is empty!" << endl;
            return -1; // Возвращаем значение по умолчанию
        }
        return arr[topIndex]; // Возвращаем верхний элемент
    }

    // Операция isEmpty: проверка на пустоту
    bool isEmpty() {
        return topIndex == -1; // Если индекс -1, стек пуст
    }
};
