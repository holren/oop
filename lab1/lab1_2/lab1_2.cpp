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
	/*Stock() {
		cout << "Содержимое конструктора\n";
	}*/

	Stock(string n, int q, float p)
	{
		name = n;
		quantity = q;
		price = p;
		total = set_tot(quantity, price);

		showdata();
	}
	/*~Stock()
	{
		cout << "Удаление... \n";
	}*/

	void showdata() {
		cout << "Наименование компании: " << name << endl;
		cout << "  Количество: " << quantity << endl;
		cout << "  Цена: " << price << endl;
		cout << "  Общая стоимость: " << total << "\n" << endl;
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
};

int main() {
	setlocale(LC_ALL, "Russian");
	Stock a("Apple", 20, 56.7);
	Stock b("BMW", 20, 56.7);
	Stock c("CD PROJECT RED", 20, 56.7);
	Stock d("Dolche & Gabanna", 20, 56.7);
	return 0;
}