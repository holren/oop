#include <iostream> 
using namespace std;

class PRODUCT// определение класса 
{
private:
	string name;
	int quantity;
	float price;

public:

	void setdata(string n, int q, float p) // метод класса, изменяющий значение поля 
	{
		name = n;
		quantity = q;
		price = p;
	}
	void showdata() // метод класса, отображающий значение поля 
	{
		//cout << "Наименование продукта: " << name << " Количество: " <<quantity << " Цена: " << price << endl;
		cout << "Наименование продукта: " << name << endl;
		cout << "  Количество: " << quantity << endl;
		cout << "  Цена: " << price << "\n" << endl;
	}
	void showname() // метод класса, отображающий значение поля 
	{
		cout << "Наименование продукта: " << name << endl;
	}
	// По аналогии можно показывать количество и цену
};

int main() {
	setlocale(LC_ALL, "Russian");
	PRODUCT pr1, pr2;
	pr1.setdata("Кетчуп", 20, 56.7); // вызовы метода setdata() 
	pr2.setdata("Майонез", 100, 70.7);
	pr1.showdata(); // вызовы метода showdata() 
	pr2.showdata();
	pr1.showname();
	return 0;
}

