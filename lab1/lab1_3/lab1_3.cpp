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
	Stock Companies[4] =
	{
	Stock("Apple", 20, 56.7),
	Stock("BMW", 20, 56.7),
	Stock("CD PROJECT RED", 20, 56.7),
	Stock("Dolche & Gabanna", 20, 56.7)
	};
	Companies[1].buy(5);
	Companies[1].showdata();
	return 0;
}