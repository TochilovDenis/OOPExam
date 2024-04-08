#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    vector<int> elements;
public:
    void Push(int value) { elements.push_back(value); }
    bool IsEmpty() { return elements.empty(); }
    int DelQueue() {
        if (IsEmpty()) {
            cout << "Очередь пуста!" << endl;
            return -1;
        }
        int removedValue = elements.front();
        elements.erase(elements.begin());
        return removedValue;
    }
    void PrintQueue() {
        cout << "Элемент    очереди: ";
        for (int el : elements)
            cout << el << " ";
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "");
    Queue q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.PrintQueue();
    cout << "Удаленное значение: " << q.DelQueue() << endl;
    q.PrintQueue();

    return 0;
}
/* 
Задача 2024.04.03.05

Опишите класс Очередь для целых чисел.

У очереди есть методы
- Добавить - добавляет в конец
- Удалить - удаляет из начала и возвращает удалённый объект
- ПустаяЛиОчередь - проверяет пустая ли очередь
- Вывод всей очереди на экран
*/