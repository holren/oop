#include <iostream> 
#include <string>
//#include <ctime>
using namespace std;


class Train// определение класса 
{
private:
	string destination;
	int number;
	string date; // как сделать дату
	int obh;
	int cupe;
	int placcart;
	float total;

	float set_tot(int c, int p, int o) {
		float tot = c + p + o;
		return tot;
	}

public:
	Train(string d, int n, string dat, int o, int c, int p)
	{
		destination = d;
		number = n;
		date = dat;
		obh = o;
		cupe = c;
		placcart = p;
		total = set_tot(cupe, placcart, obh);

		//show_data();
	}

	void show_data() {
		//cout << "  Информация о поезде: " << endl;
		cout << "    Пункт назначения: " << destination << endl;
		cout << "    Номер поезда: " << number << endl;
		cout << "    Время отправления " << date << endl;
		cout << "    Общие места: " << obh << endl;
		cout << "    Купе: " << cupe << endl;
		cout << "    Плацкарт: " << placcart << endl;
		cout << "    Всего мест: " << total << "\n" << endl;
	}
	string show_destination() {
		//cout << destination << endl;
		//string y = destination;
		return destination;
	}
	int show_obh() {
		return obh;
	}
};

void destination_train(Train Trains[], string destination) {
	for (int i = 0; i < 6; i++) {
		if (Trains[i].show_destination() == destination) {
			Trains[i].show_data();
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	Train Trains[6]{
		Train("Saint-Petesburg", 12769,"12.04.21 12:10", 10, 20, 40),
		Train("Moscow", 12769,"18.05.21 12:10", 0, 15, 40),
		Train("Sochi", 12769,"10.02.21 2:10", 20, 20, 40),
		Train("Rostov-on-Don", 12769,"09.04.21 01:10", 10, 20, 40),
		Train("Kiev", 12769,"05.08.21 12:41", 0, 20, 40),
		Train("Saint-Petesburg", 12769,"12.04.21 14:25", 0, 20, 40)
	};
	cout << "3 поезд \n" << endl;
	Trains[3].show_data();
	cout << "Cписок поездов, следующих до заданного пункта назначения: \n" << endl;
	for (int i = 0; i < 6; i++)
	{
		if (Trains[i].show_destination() == "Saint-Petesburg")
		{
			Trains[i].show_data();
		}
	}
	cout << "Cписок поездов, отправляющихся до заданного пункта назначения и имеющих общие места: \n" << endl;
	for (int i = 0; i < 6; i++) {
		string des = "Saint-Petesburg";
		if ((Trains[i].show_destination()) == des && (Trains[i].show_obh() > 0)) {
			Trains[i].show_data();
		}
	}
	destination_train(Trains, "Saint-Petesburg");
	return 0;

};