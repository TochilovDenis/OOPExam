#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Fruct {
protected:
    static int mCount;
    string mName;
public:
    Fruct() : mName("") { mCount = 0; };
    Fruct(const string& name) : mName(name) { mCount++; }
    virtual ~Fruct() {}

    virtual string GetName() const = 0;
    int GetCount() const { return mCount; }
};
int Fruct::mCount = 0;

class Apple : public Fruct {
public:
    Apple() : Fruct("Яблоко") {}
    string GetName() const { return "Яблоко"; }
};

class Pear : public Fruct {
public:
    Pear() : Fruct("Груша") {}
    string GetName() const { return "Груша"; }
};

class Pineapple : public Fruct {
public:
    Pineapple() : Fruct("Ананас") {}
    string GetName() const { return "Ананас"; }
};

class FruitsArray {
    vector<Fruct*> fruits;
public:
    void Print() {
        for (auto fruit : fruits)
            cout << fruit->GetName() << endl;
    }
    void Amount() { cout << "Общее количество фруктов: " << fruits.size() << endl; }
    void Amount(const string& name) {
        int count = 0;
        for (auto fruit : fruits)
            if (fruit->GetName() == name) { count++; }
        cout << left << setw(6) << name << " количество: " << count << endl;
    }
    void Add(Fruct* fruit) {
        fruits.push_back(fruit);
    }
};

int main() {
    setlocale(LC_ALL, "");
    FruitsArray fruitsArray;
    fruitsArray.Add(new Apple());
    fruitsArray.Add(new Pear());
    fruitsArray.Add(new Pineapple());
    fruitsArray.Add(new Apple());
    fruitsArray.Add(new Pear());

    fruitsArray.Print();
    fruitsArray.Amount();
    fruitsArray.Amount("Яблоко");
    fruitsArray.Amount("Груша");
    fruitsArray.Amount("Ананас");
}

/*
Задача 2024.04.03.09

Опишите класс Фрукт, у которого есть параметр Название.

Опишите классы Яблоко, Груша и Ананас. У каждого из этих трёх классов есть счётчик, сколько именно груш, яблок и ананасов было создано.

Создайте класс FruitsArray, куда вы будете складывать и яблоки, и груши и ананасы.

У FruitsArray есть методы Print() который выводит на экран все список всех фруктов, Amount() выводит количество всех фруктов, Amount(string name) - выводит количество всех фруктов с именем name и Add, который добавляет фрукт.

В main() случайно заполнить FruitsArray фруктами, вывести на экран список всех фруктов и сколько их всего,

а также вывести сколько всего яблок, груш и ананасов.
*/