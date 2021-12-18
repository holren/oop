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
			throw "Radius < 0";

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
	Rectangle(double a)
	{
		cout << "Вызов конструктора с 1 параметром Rectangle" << endl;
		if (a < 0)
			throw "A < 0";

		this->a = a;
		this->b = 0;
	}
	Rectangle(double a, double b)
	{
		cout << "Вызов конструктора с 2 параметрами Rectangle" << endl;
		if (a < 0)
			throw "A < 0";

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
		if (b == 0)
		{
			cout << "B is null";
			return;
		}
		return &b;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	Circle circle1(5.0);
	Rectangle rectangle1(10.0, 20);
	//Figure figure(); Class is abstract, therefore it's imposible to initialize

	cout << "Area circle1: " << circle1.Area() << endl;
	cout << "Adress radius: " << circle1.GetAdressRadius() << endl;

	cout << "Area rectangle1: " << rectangle1.Area() << endl;
	cout << "Adress A: " << rectangle1.GetAdressA() << "\nAdress B: " << rectangle1.GetAdressB() << endl;
}


