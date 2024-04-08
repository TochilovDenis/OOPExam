#include <iostream>
#include <vector>
using namespace std;

class Batya {
public:
    virtual void Do() { cout << "Do like Batya\n"; }
};
class Son : public Batya {
public:
    void Do() { cout << "Do like Son\n"; }
};
int main()
{
    vector<Batya*> vec;
    for (size_t i = 0; i < 10; i++) {
        (i % 2 == 0) ? vec.push_back(new Batya()) : vec.push_back(new Son());
    }
    for (auto& obj : vec) { obj->Do(); }
    for (auto& obj : vec) { delete obj; }

    return 0;
}
/*
Задача 2024.04.03.07

Создать Класс Batya, у которого всего один метод Do(), который выводит на экран слова Do like Batya

И создать класс Son, наследник класса Batya, у которого перегружен метод Do() и он выводит на экран слова Do like Son

В main запустить цикл от 0 до 10, и в нём добавлять в вектор объекты Batya или Son.

если i - чётное - добавляем Batya, а если не чётное - добавляем Son.

Для всех 10 элементов потом запустим функцию Do()
*/