#include <iostream>;
#include <string>;
using namespace std;

class Base1 {

private:
	int i;

public:
	Base1() {
		cout << "Вызов конструктора по умолчанию Base1" << endl;
		this->i = 0;
	}
	Base1(int i) {
		cout << "Вызов конструктора Base1" << endl;
		this->i = i;
	}

	void putI(int i) {
		this->i = i;
	}
	int getI() {
		return i;
	}

};

class Base2 {
private:
	string name;

public:
	Base2() {
		cout << "Вызов конструктора по умолчанию Base2" << endl;
		this->name = "Empty";
	}

	Base2(string _name) {
		cout << "Вызов конструктора Base2" << endl;
		this->name = name;
	}

	void PutName(string names)
	{
		name = names;
	}

	string getName()
	{
		return name;
	}
};

class Derived : public Base1, public Base2 {
private:
	char ch;
public:
	Derived() {
		cout << "Вызов конструктора по умолчанию Derived" << endl;
		ch = 'V';
	}
	Derived(char ch, string name, int i) : Base2(name), Base1(i)
	{
		cout << "Вызов конструктора Derived" << endl;
		this->ch = ch;
	}

	void putCh(char ch)
	{
		this->ch = ch;
	}

	char getCh()
	{
		return ch;
	}

	friend ostream& operator<<(ostream& out, Derived& ob);//дружественная операция вставки в поток  вывода
};
ostream& operator<<(ostream& out, Derived& ob) {
	return out << (Base1(ob)).getI() << "\n" << (Base2(ob)).getName() << "\n" << (Derived(ob)).getCh() << "\n";//выводит значения i,name, ch
}

class DomesticAnimal {
protected:
	int weight;
	int price;
	string color;

public:
	DomesticAnimal() {
		cout << "Вызов конструктора по умолчанию DomesticAnimal" << endl;
	}
	DomesticAnimal(double weight, double price, string color)
	{
		cout << "Вызов конструктора DomesticAnimal" << endl;
		this->weight = weight;
		this->price = price;
		this->color = color;
	}

	void print()
	{
		cout << "Class DomesticAnimal" << endl;
		cout << "Weight: " << weight << endl;
		cout << "Price: " << price << endl;
		cout << "Color: " << color << endl;
	}
};

class Cow : public DomesticAnimal { //virtual
public:
	void print()
	{
		cout << "Class Cow" << endl;
		//cout << "Weight: " << weight << endl;
		//cout << "Price: " << price << endl;
		//cout << "Color: " << color << endl;
		DomesticAnimal::print();
	}
};

class Buffalo : public DomesticAnimal { //virtual
public:
	Buffalo() {
		cout << "Вызов конструктора по умолчанию Buffalo" << endl;
	}

	Buffalo(double weight, double price, string color) : DomesticAnimal(weight, price, color)
	{

	}

	void print()
	{
		cout << "Class Buffalo" << endl;
		//cout << "Weight: " << weight << endl;
		//cout << "Price: " << price << endl;
		//cout << "Color: " << color << endl;
		DomesticAnimal::print();
	}
};

class Beefalo : public Cow, public Buffalo {
public:
	Beefalo() {
		cout << "Вызов конструктора по умолчанию Beefalo" << endl;
	}
	Beefalo(double weight, double price, string color)
	{
		DomesticAnimal::weight = weight;
		DomesticAnimal::price = price;
		DomesticAnimal::color = color;
	}

	void print()
	{
		cout << "Class Beefalo" << endl;
		DomesticAnimal::print();
	}
};
int main() {
	setlocale(LC_ALL, "rus");
	Derived ob;
	cout << ob << endl;
	Derived ob2('h', "qwerty", 26);
	cout << ob << endl;

	Cow cow;
	cow.print();
	Beefalo beefalo(11.0, 1000.0, "white");
	beefalo.print();
}