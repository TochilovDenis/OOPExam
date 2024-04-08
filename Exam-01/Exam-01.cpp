#include <iostream>
#include <string>

using namespace std;

enum EnumMaleFemale{ Male, Female };
class Human {
	string mName;
	string mSurname;
	int mAge;
	EnumMaleFemale mGrader;
public:
	Human(string name, string surname, int age, EnumMaleFemale grader) 
		: mName{ name }, mSurname{ surname }, mAge{ age }, mGrader{grader} {}
	Human() : Human("", " ", 0, Male) {}
	Human(Human& other) : Human(other.mSurname, other.mName, other.mAge + 1, other.mGrader) {}
	~Human() {}
	
	string GetName()           const { return mName; }
	string GetSurname()        const { return mSurname; }
	int GetAge()               const { return mAge; }
	EnumMaleFemale GetGrader() const { return mGrader; }

	void SetName(string value)          { mName = value; }
	void SetSurname(string value)       { mSurname = value; }
	void SetAge(int value)              { mAge = value; }
	void SetGrader(EnumMaleFemale value){ mGrader = value; }

	string GetString() const {
		return "Имя: " + GetName() + " | Фамилия: " + GetSurname()
			+ " | Возраст: " + to_string(GetAge()) + " | Пол: " + (GetGrader() == Male ? "Мужской" : "Женский");
	}
	void Print() const { 
		cout << GetString() << endl;
	}
};


int main() {
	setlocale(LC_ALL, "");
	Human p0("Точилов", "Денис", 32, Male);
	Human p1("Третьяков", "Павел", 50, Male);
	Human p2("Шанина", "Анна", 20, Female);
	Human copyP(p0);

	p0.Print();
	p1.Print();
	p2.Print();
	copyP.Print();

	return 0;
}

/*
2024.04.03.01

Создайте класс Human с полями Name и Surname типа string, Age типа int, Sex(пол) типа EnumMaleFemale {Male, Female}.

В классе должны быть описаны все геттеры и сеттеры, 
пустой конструктор, параметризированный конструктор,
конструктор копирования (тот что принимает на вход объект типа Human),
должен быть метод GetString() - формирующий строку описания человека со всеми параметрами, 
и метод Print( )который выводит строку GetString на экран

Создать в программе трёх случайных людей и вывести их на экран.
*/