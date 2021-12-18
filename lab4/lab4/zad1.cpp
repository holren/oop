#include <iostream>
#include <locale>
using namespace std;

int myfunc(int i); // Эти функции различаются типами параметров
double  myfunc(double i);
double side_length(double x1, double y1, double x2, double y2);
double side_length(double x1, double y1, double z1, double x2, double y2, double z2);

int main(){
	setlocale(LC_ALL, "RUS");
	cout << myfunc(10) << endl; // Вызов функции myfunc (int i)
	cout << myfunc(5.5) << endl;  // Вызов функции myfunc (double i)

	double x1 = 2.0, y1 = 2.0, z1 = 5.0;
	double x2 = 3.0, y2 = 4.0, z2 = 7.0;
	double x3 = 1.0, y3 = 2.0, z3 = 6.0;

	double perimeter = side_length(x1, y1, x2, y2) + 
		side_length(x2, y2, x3, y3) + 
		side_length(x3, y3, x1, y1);
	cout << "Периметр равен (двухмерное пр) = " << perimeter << endl;

	perimeter = side_length(x1, y1, z1, x2, y2, z2) +
		side_length(x2, y2, z2, x3, y3, z3) +
		side_length(x3, y3, z3, x1, y1, z1);

	cout << "Периметр равен (трехмерное пр) = " << perimeter << endl;
	return 0;
}

double myfunc(double i){
	return i;
}

int  myfunc(int i){
	return i;
}

double side_length(double x1, double y1, double x2, double y2) {
	return sqrt(pow(y1 - y2, 2) + pow(x1 - x2, 2));
}

double side_length(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow(y1 - y2, 2) + pow(x1 - x2, 2) + pow(z1 - z2, 2));
}