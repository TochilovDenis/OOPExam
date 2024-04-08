#include <iostream>
#include <string>

using namespace std;

enum EnumMaleFemale { Male, Female };
class Human {
	string mName;
	string mSurname;
	int mAge;
	EnumMaleFemale mGrader;
	static int mCount;
public:
	Human(string name, string surname, int age, EnumMaleFemale grader)
		: mName{ name }, mSurname{ surname }, mAge{ age }, mGrader{ grader } { mCount++; }
	Human() : Human("", " ", 0, Male) { mCount++; }
	Human(Human& other) : Human(other.mName, other.mSurname, other.mAge + 1, other.mGrader) {}
	~Human() {}

	string GetName()           const { return mName; }
	string GetSurname()        const { return mSurname; }
	int GetAge()               const { return mAge; }
	EnumMaleFemale GetGrader() const { return mGrader; }
	static int GetHumanCount() { return mCount; }
	void SetName(string value) { mName = value; }
	void SetSurname(string value) { mSurname = value; }
	void SetAge(int value) { mAge = value; }
	void SetGrader(EnumMaleFemale value) { mGrader = value; }
	void SetHumanCount(int value) { mCount = value; }

	string GetString() const {
		return "Имя: " + GetName() + " | Фамилия: " + GetSurname()
			+ " | Возраст: " + to_string(GetAge()) + " | Пол: " + (GetGrader() == Male ? "Мужской" : "Женский");
	}
	void Print() const {
		cout << GetString() << endl;
	}
};

int Human::mCount = 0;

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

	cout << "Количество созданных людей: " << Human::GetHumanCount() << endl;
	return 0;
}

/*
Задача 2024.04.03.02

В описанный выше класс добавьте счётчик всех людей, чтобы он был доступен каждому человеку 
и увеличивался на 1 при создании каждого человека. И геттер для него.

Также всевозможные константные методы опишите константными.

В программе после создания трёх случайных людей выведите на экран текущее значение количества 
созданных на данный момент людей.
*/