#include <iostream>;
#include <string>;
#define _USE_MATH_DEFINES 
#include <math.h>
using namespace std;

class Figure
{
	virtual double Area() = 0;
	virtual void Show() = 0;
};

class Circle : public Figure
{
	double radius;
public:
	Circle(double radius) {
		cout << "Вызов конструктора Circle" << endl;
		if (radius < 0)
			cout << "Radius < 0" << endl;

		this->radius = radius;
	}

	double Area()
	{
		return M_PI * pow(radius, 2);
	}

	void Show()
	{
		cout << "class Circle" << endl;
		cout << "A = " << radius << endl;
	}

	double* GetAdressRadius()
	{
		return &radius;
	}
};
class Rectangle : public Figure {
	double a;
	double b;
public:
	Rectangle(double a)
	{
		cout << "Вызов конструктора с 1 параметром Rectangle" << endl;
		if (a < 0)
			cout << "A < 0" << endl;

		this->a = a;
		this->b = 0;
	}
	Rectangle(double a, double b)
	{
		cout << "Вызов конструктора с 2 параметрами Rectangle" << endl;
		if (a < 0)
			cout << "A < 0" << endl;

		this->a = a;
		this->b = b;
	}

	double Area()
	{
		if (b == 0)
			return a * a;

		return a * b;
	}

	void Show()
	{
		cout << "class Rectangle" << endl;

		if (b == 0)
		{
			cout << "A = " << a << endl;

			return;
		}

		cout << "A = " << a << endl;
		cout << "B: " << b << endl;
	}

	double* GetAdressA()
	{
		return &a;
	}

	double* GetAdressB()
	{
		if (b != 0)
		{
			return &b;
		}
		cout << "B is null";
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	Circle circle1(5.0);
	Rectangle rectangle1(10,20);
	//Figure figure(); figure абстрактный класс, который не может иметь объектов

	cout << "Area circle1: " << circle1.Area() << endl;
	cout << "Adress radius: " << circle1.GetAdressRadius() << endl;

	cout << "Area rectangle1: " << rectangle1.Area() << endl;
	cout << "Adress A: " << rectangle1.GetAdressA() << endl;
	cout << "Adress B: " << rectangle1.GetAdressB() << endl;
}


