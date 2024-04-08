/*Задача 2024.04.03.08
Исправьте ошибки в коде.
*/

#include <iostream>

class Base {
public:
    virtual void Do() = 0;
    virtual std::string Run() = 0;
};

class Sample : private Base {
public:
    void Do() { std::cout << "Sample Do!"; }
    std::string Run() { return "Sample Run!"; }
};

class Foobar : public Sample {
public:
    void Do() { std::cout << "Foobar Do"; }
    std::string Run() { return "Foobar Run"; }
};

int main()
{
    Sample sample;
    sample.Do();
    sample.Run();
    Foobar foobar;
    foobar.Do();
    foobar.Run();
}