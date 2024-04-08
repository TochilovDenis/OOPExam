#include <iostream>
using namespace std;

class DoubleValue {
    double mValue;
public:
    DoubleValue() : mValue(0.0) {}
    DoubleValue(double value) : mValue(value) {}
    DoubleValue(const DoubleValue& other) : DoubleValue(other.mValue) { }

    double GetValue() const       { return mValue; }
    void   SetValue(double value) { mValue = value; }
    friend DoubleValue operator+(const DoubleValue& l, const DoubleValue& r);
    friend DoubleValue operator-(const DoubleValue& l, const DoubleValue& r);
    friend DoubleValue operator*(const DoubleValue& l, const DoubleValue& r);
    friend DoubleValue operator/(const DoubleValue& l, const DoubleValue& r);

    friend bool operator==(const DoubleValue& l, const DoubleValue& r);
    friend bool operator!=(const DoubleValue& l, const DoubleValue& r);
    friend bool operator<(const DoubleValue& l, const DoubleValue& r);
    friend bool operator>(const DoubleValue& l, const DoubleValue& r);

    friend ostream& operator<<(ostream& os, const DoubleValue& other);

};
DoubleValue operator+(const DoubleValue& l, const DoubleValue& r) {
    return l.GetValue() + r.GetValue();
}
DoubleValue operator-(const DoubleValue& l, const DoubleValue& r) {
    return l.GetValue() - r.GetValue();
}
DoubleValue operator*(const DoubleValue& l, const DoubleValue& r) {
    return l.GetValue() * r.GetValue();
}
DoubleValue operator/(const DoubleValue& l, const DoubleValue& r) {
    if (r.GetValue() == 0) {
        cout << "Ошибка: Попытка деления на ноль." << endl;
        return 0;
    }
    return DoubleValue(l.GetValue() / r.GetValue());
}

bool operator==(const DoubleValue& l, const DoubleValue& r) {
    return l.GetValue() == r.GetValue();
}
bool operator!=(const DoubleValue& l, const DoubleValue& r) {
    return l.GetValue() != r.GetValue();
}
bool operator<(const DoubleValue& l, const DoubleValue& r) {
    return l.GetValue() < r.GetValue();
}
bool operator>(const DoubleValue& l, const DoubleValue& r) {
    return l.GetValue() > r.GetValue();
}

ostream& operator<<(ostream& os, const DoubleValue& other) {
    os << other.GetValue();
    return os;
}

int main() {
    setlocale(LC_ALL, "");
    DoubleValue dv1(6.1);
    DoubleValue dv2(1.5);

    DoubleValue sum = dv1 + dv2;
    DoubleValue diff = dv1 - dv2;
    DoubleValue prod = dv1 * dv2;
    DoubleValue quot = dv1 / dv2;

    cout << "Сумма: "       << sum << endl
        << "Разность: "     << diff << endl
        << "Произведение: " << prod << endl
        << "Частное: "      << quot << endl;

    cout << "Сравнение:" << endl
        << "dv1 > dv2:  " << (dv1 > dv2 ? "true" : "false")  << endl
        << "dv1 < dv2:  " << (dv1 < dv2 ? "true" : "false")  << endl
        << "dv1 == dv2: " << (dv1 == dv2 ? "true" : "false") << endl
        << "dv1 != dv2: " << (dv1 != dv2 ? "true" : "false") << endl;

    return 0;
}

/*
Задача 2024.04.03.03

Опишите класс DoubleValue, у которого одно поле double mValue,
описать его геттер и сеттер, пустой конструктор со значением по умолчанию, равным 0,
параметризированный и конструктор копирования.

А также перегрузите для него операторы `+`, `-`, `*`, `/`, `<`, `>`, `==` и `<<`

В программе создайте два DoubleValue.

Выведите на экран их сумму, разность, произведение и частное, а также сравнение `>`, `<` и `==`
*/