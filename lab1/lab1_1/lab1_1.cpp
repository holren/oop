#include <iostream> 
#include <string>
using namespace std;

class Stock// определение класса 
{
private:
	string name;
	int quantity;
	float price;
	float total;

	float set_tot(int quantity, float price) {
		float tot = quantity * price;
		return tot;
	}

public:
	void acquire(string n, int q, float p) // метод класса, изменяющий значение поля 
	{
		name = n;
		quantity = q;
		price = p;
		total = set_tot(quantity, price);
	}
	void buy(int amount) {
		if (amount < 0) return;
		else {
			quantity = quantity + amount;
		}
		total = set_tot(quantity, price);
	}
	void sell(int amount) {
		if (amount > quantity || amount < 0) return;
		else {
			quantity = quantity - amount;
		}
		total = set_tot(quantity, price);
	}
	void update(float new_price) {
		price = new_price;
		total = set_tot(quantity, price);
	}
	void showdata() // метод класса, отображающий значение поля 
	{
		//cout << "Наименование продукта: " << name << " Количество: " <<quantity << " Цена: " << price << endl;
		cout << "Наименование компании: " << name << endl;
		cout << "  Количество: " << quantity << endl;
		cout << "  Цена: " << price << endl;
		cout << "  Общая стоимость: " << total << "\n" << endl;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	Stock pr1, pr2;
	pr1.acquire("Apple", 20, 56.7); // вызовы метода setdata() 
	pr2.acquire("Facebook", 105, 70.7);
	pr1.showdata(); // вызовы метода showdata() 
	pr2.showdata();
	pr1.buy(3);
	pr1.showdata();
	pr1.sell(5);
	pr1.showdata();
	pr1.update(60.8);
	pr1.showdata();
	return 0;
}