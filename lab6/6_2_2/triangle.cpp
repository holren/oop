#include <iostream>
#include "new_fig.h"
#include <math.h>
using namespace std;

Triangle::Triangle(double a, double b, double c) {
	if (a < 0 || b < 0 || c < 0 || a + b < c || a + c < b || b + c < a) {
		throw "Check the sides of your triangle";
	}

	this->a = a;
	this->b = b;
	this->c = c;
}

double Triangle::Area() {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::Show() {
	cout << "class Triangle:" << endl;
	cout << "A = " << a << endl;
	cout << "B = " << b << endl;
	cout << "C = " << c << endl;
	cout << "Area = " << Area() << endl;
}