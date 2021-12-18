#include <iostream>
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
	Circle(double radius);

	double Area();

	void Show();

	double* GetAdressRadius();
};

class Rectangle : public Figure
{
	double a;
	double b;

public:
	Rectangle(double a);

	Rectangle(double a, double b);

	double Area();

	void Show();

	double* GetAdressA();

	double* GetAdressB();
};