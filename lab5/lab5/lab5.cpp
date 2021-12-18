#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


class BASE {
public:
	int i;

	BASE() {
		cout << "Вызов конструктора по умолчанию BASE" << endl;
	}

	BASE(int i, long l, double d) {
		cout << "Вызов конструктора BASE" << endl;
		this->i = i;
		this->l = l;
		this->d = d;
	}
	~BASE()
	{
		cout << "Вызов деструктора BASE" << endl;
	}

	double* GetAdressD()
	{
		return &d;
	}

	long* GetAdressL()
	{
		return &l;
	}

	int* GetAdressI()
	{
		return &i;
	}

	double GetDBase() {
		return d;
	}
	void SetDBase(double newD) { d = newD; }


private: //доступ открыт только самому классу
	double d;
protected: //доступ открыт наследникам
	long l;

	void ff()
	{
		cout << "   Уровень BASE" << endl;
	}
};

class DERIVED : public BASE {
private:
	float f;

public:
	DERIVED() {
		cout << "Вызов конструктора по умолчанию DERIVED" << endl;
	}

	DERIVED(int i, long l, double d, float f) : BASE(i, l, d) {
		cout << "Вызов конструктора DERIVED" << endl;
		this->f = f;
	}
	~DERIVED()
	{
		cout << "Вызов деструктора DERIVED" << endl;
	}

	float* GetAdressF()
	{
		return &f;
	}

	float GetFDerived() { return f; }
	int GetIDerived() { return i; }
	long GetLDerived() { return l; }
	double GetDDerived() { return GetDBase(); }

	void SetFDerived(float newF) { f = newF; }

protected:
	void ff(){
		cout << "   Уровень DERIVED" << endl;
	}
};

class DERIVED_L : public DERIVED
{
public:
	DERIVED_L() {
		cout << "Вызов конструктора по умолчанию DERIVED_L" << endl;
	}

	DERIVED_L(int i, long l, double d, float f) : DERIVED(f, i, l, d)
	{
		foo();
	}

	void foo() {
		SetFDerived(GetFDerived() + 1);
		i++;
		l++;
		SetDBase(GetDDerived() + 1);
		ff();
	}

};


ostream& operator << (ostream& os, DERIVED& derived)
{
	os << "Adress i: " << derived.GetAdressI() << endl;
	os << "Adress l: " << derived.GetAdressL() << endl;
	os << "Adress d: " << derived.GetAdressD() << endl;
	os << "Adress f: " << derived.GetAdressF() << endl;
	return os;
}

ostream& operator << (ostream& os, DERIVED_L& derivedL)
{
	auto test = derivedL.GetAdressF();
	os << "Adress i: " << derivedL.GetAdressI() << endl;
	os << "Adress l: " << derivedL.GetAdressL() << endl;
	os << "Adress d: " << derivedL.GetAdressD() << endl;
	os << "Adress f: " << derivedL.GetAdressF() << endl;
	return os;
}

void ff()
{
	cout << "   Глобальный уровень" << endl;
}


int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Вход в функцию main" << endl;
	DERIVED obj();
	cout << "Размер типа BASE: " << sizeof(BASE) << endl;
	cout << "Размер типа DERIVED: " << sizeof(DERIVED) << endl << endl;
	//DERIVED больше, так как он наследует от родителя + новые данные
	DERIVED test(1.0, 5, 8, 1);
	cout << test << endl;
	DERIVED_L testL(1.0, 5, 8, 1);
	cout << testL;
	// Сначала отображается уровень DERIVED. Если убрать ff() оттуда, то уровень станет BASE. Если же убрать BASE выдается ошибка.

}








