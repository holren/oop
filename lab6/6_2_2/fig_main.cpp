#include <iostream>
#include <string>
//#include "figure.h"
#include "new_fig.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	Circle circle1(5.0);
	Rectangle rectangle1(10, 30);
	//Figure figure(); figure абстрактный класс, который не может иметь объектов

	cout << "Area circle1: " << circle1.Area() << endl;
	cout << "Adress radius: " << circle1.GetAdressRadius() << endl;

	cout << "Area rectangle1: " << rectangle1.Area() << endl;
	cout << "Adress A: " << rectangle1.GetAdressA() << endl;
	cout << "Adress B: " << rectangle1.GetAdressB() << endl;

	Triangle triangle(5, 5, 10);
	//cout << "Area triangle: " << triangle.Area() << endl;
}
