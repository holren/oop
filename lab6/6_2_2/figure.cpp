#include <iostream>
#include "figure.h"
#include <string>
#define _USE_MATH_DEFINES 
#include <math.h>
using namespace std;

Circle::Circle(double radius)
{
	cout << "Вызов конструктора Circle" << endl;
	if (radius < 0)
		cout << "Radius < 0" << endl;

	this->radius = radius;
}

double Circle::Area()
{
	return M_PI * pow(radius, 2);
}

void Circle::Show()
{
	cout << "class Circle" << endl;
	cout << "A = " << radius << endl;
}

double* Circle::GetAdressRadius()
{
	return &radius;
}

Rectangle::Rectangle(double a)
{
	cout << "Вызов конструктора с 1 параметром Rectangle" << endl;
	if (a < 0)
		cout << "A < 0" << endl;

	this->a = a;
	this->b = 0;
}

Rectangle::Rectangle(double a, double b)
{
	cout << "Вызов конструктора с 2 параметрами Rectangle" << endl;
	if (a < 0 && b < 0)
		cout << "A or B < 0" << endl;

	this->a = a;
	this->b = b;
}

double Rectangle::Area()
{
	if (b == 0)
		return a * a;

	return a * b;
}

void Rectangle::Show()
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

double* Rectangle::GetAdressA()
{
	return &a;
}

double* Rectangle::GetAdressB()
{
	if (b != 0)
	{
		return &b;
	}

	cout << "B is null";
}