#include <iostream>
#include <string>
using namespace std;
class date {
	int day, month, year;
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	date(int Day, int Month, int Year) {
		day = Day;
		month = Month;
		year = Year;
	}

	//Ïåðåãðóçêà << 
	friend std::ostream& operator<< (std::ostream& out, const date& obj);
	//Ïåðåãðóçêà date + date
	friend date operator+(const date& obj, const date& obj2);
	//Ïåðåãðóçêà date + int
	date operator+(int value);
	//Ïåðåãðóçêà int + date
	friend date operator+(int value, const date& obj);
	//Ïåðåãðóçêà date++ ïðåôèêñ
	date& operator++() {
		day += 1;
		if (day > days[month]) {
			day - days[month];
			month -= 1;
			if (month > 12) {
				month -= 12;
				year += 1;
			}
		}
		return *this;
	}
	//Ïåðåãðóçêà date++ ïîñòôèêñ
	date operator++(int) {
		date prev = *this;
		++* this;
		return prev;
	}
	//Ïåðåãðóçêà date-- ïðåôèêñ
	date& operator--() {
		day -= 1;
		if (day <= 0) {
			day + days[month];
			month -= 1;
			if (month <= 0) {
				month += 12;
				year -= 1;
			}
		}
		return *this;
	}
	//Ïåðåãðóçêà date-- ïîñòôèêñ
	date operator--(int) {
		date prev = *this;
		--* this;
		return prev;
	}
	//Ïåðåãðóçêà date - date
	friend date operator-(const date& obj1, const date& obj2);
	//Ïåðåãðóçêà date - int
	friend date operator-(const date& obj, int value);
};

std::ostream& operator<< (std::ostream& out, const date& obj) {
	out << obj.day << "." << obj.month << "." << obj.year << endl;
	return out;
}
//int + date
date operator+(int value, const date& obj) {
	int day1 = obj.day + value;
	int month1 = obj.month;
	int year1 = obj.year;
	if (day1 > obj.days[obj.month]) {
		day1 -= obj.days[obj.month];
		month1 = obj.month + 1;
		if (month1 > 12) {
			year1 = obj.year + 1;
			month1 = month1 - 12;
		}
	}
	return date(day1, month1, year1);
}
//date + int
date date::operator+(int value)
{
	int day1 = day + value;
	int month1 = month;
	int year1 = year;
	if (day1 > days[month]) {
		day1 -= days[month];
		month1 = month + 1;
		if (month1 > 12) {
			year1 = year + 1;
			month1 = month1 - 12;
		}
	}
	return date(day1, month1, year1);
};
//date + date
date operator+(const date& obj, const date& obj2) {
	int day1 = obj.day + obj2.day;
	int month1 = obj.month;
	int year1 = obj.year;
	if (day1 > obj.days[obj.month]) {
		day1 -= obj.days[obj.month];
		month1 = obj.month + 1;
		if (month1 > 12) {
			year1 = obj.year + 1;
			month1 = month1 - 12;
		}
	}
	return date(day1, month1, year1);
};
//date - date
date operator-(const date& obj1, const date& obj2) {
	int month1 = obj1.month;
	int year1 = obj1.year;
	int day1 = obj1.day - obj2.day;
	if (day1 <= 0) {
		month1--;
		day1 = obj1.day + day1;
		if (month1 <= 0) {
			year1--;
			month1 += 12;
		}
	}
	return date(day1, month1, year1);
}
//date - int
date operator-(const date& obj, int value) {
	int month1 = obj.month;
	int year1 = obj.year;
	int day1 = obj.day - value;
	if (day1 <= 0) {
		month1--;
		day1 = obj.day + day1;
		if (month1 <= 0) {
			year1--;
			month1 += 12;
		}
	}
	return date(day1, month1, year1);
};
void line() {
	cout << "________________________________" << endl;
	cout << "________________________________" << endl;
	cout << "________________________________" << endl;
};


void main() {

	date Me(29, 12, 1000);
	cout << "date + int (12)" << endl;
	cout << Me;
	Me = Me + 12;
	cout << Me;
	line();

	cout << "int (12) + date" << endl;
	Me = 12 + Me;
	cout << Me;
	line();

	date You(5, 1, 7);
	cout << "date + date (5)" << endl;
	Me = Me + You;
	cout << Me;
	line();

	cout << "date ++" << endl;
	Me++;
	cout << Me;
	line();

	cout << "date --" << endl;
	Me--;
	cout << Me;
	line();

	cout << "date - date (5)" << endl;
	Me = Me - You;
	cout << Me;
	line();

	cout << "date - int (2)" << endl;
	Me = Me - 2;
	cout << Me;
	line();
}