#include <iostream>
#include "figure.h"
using namespace std;

class Triangle : public Figure {

	double a;
	double b;
	double c;

public:

	Triangle(double a, double b, double c);

	double Area();
	void Show();
	double* GetAddressA();
	double* GetAddressB();
	double* GetAddressC();

};