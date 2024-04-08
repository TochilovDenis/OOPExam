#include <iostream>
using namespace std;

template<typename T>
class DoubleValue {
    T mValue;
public:
    DoubleValue() : mValue(0.0) {}
    DoubleValue(T value) : mValue(value) {}
    DoubleValue(const DoubleValue& other) : DoubleValue(other.mValue) { }

    T GetValue() const { return mValue; }
    void SetValue(T value) { mValue = value; }

    friend DoubleValue operator+(const DoubleValue<T>& l, const DoubleValue<T>& r) {
        return l.GetValue() + r.GetValue();
    }
    friend ostream& operator<<(ostream& os, const DoubleValue<T>& other) {
        os << other.GetValue();
        return os;
    }
};

template<typename T>
T Sum(T a, T b) {  return a + b; }

int main()
{
    cout << "5 + 8 = " << Sum<int>(5, 8) << endl;
    cout << "2.0 + 4.1 = " << Sum<double>(2.0, 4.1) << endl;

    DoubleValue<int> dv11(3.2), dv22(7.3);
    cout << "3.2 + 7.3 = " << Sum(dv11, dv22) << endl;
    DoubleValue<double> dv1(3.2), dv2(7.3);
    cout << "3.2 + 7.3 = " << Sum(dv1, dv2) << endl;

    return 0;
}

/*
Задача 2024.04.03.04

Напишите шаблон функции Sum, которая на вход принимает два объекта и выводит их сумму.

Выведите на экран результат работы этой функции с двумя целыми числами,
с двумя дробными числами, с двумя объектами DoubleValue
*/