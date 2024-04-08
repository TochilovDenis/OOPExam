

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Queue {
private:
    vector<T> elements;
public:
    void Push(T value) { elements.push_back(value); }
    bool IsEmpty()     { return elements.empty(); }
    T DelQueue() {
        if (IsEmpty()) {
            cout << "Очередь пуста!" << endl;
            return T();
        }
        T removedValue = elements.front();
        elements.erase(elements.begin());
        return removedValue;
    }
    void PrintQueue() {
        cout << "Элемент    очереди: ";
        for (T el : elements)
            cout << el << " ";
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "");
    Queue<int> IntQ;
    IntQ.Push(1);
    IntQ.Push(2);
    IntQ.Push(3);
    IntQ.PrintQueue();
    cout << "Удаленное значение: " << IntQ.DelQueue() << endl;
    IntQ.PrintQueue();

    cout << endl;

    Queue<string> strQ;
    strQ.Push("Привет");
    strQ.Push("Мир");
    strQ.Push("!!!");
    strQ.PrintQueue();
    cout << "Удаленное значение: " << strQ.DelQueue() << endl;
    strQ.PrintQueue();
    return 0;
}

/*
Задача 2024.04.03.06

Опишите шаблон Очередь на основе класса Очередь в задаче 2024.04.03.05.
*/