#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

class Date {
private:
    int day, month, year;
    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

public:
    Date() {
        cout << "Вызов конструктора по умолчанию" << endl;
    }
    Date(int day, int month, int year) {
        cout << "Вызов конструктора" << endl;
        this->day = day;
        this->month = month;
        this->year = year;
        //this->days[13] = days[13];
    }
    ~Date() {
        cout << "Вызов деструктора" << endl;
    }

    Date& operator + (const Date& other) {
        cout << "Перегрузка оператора сложения " << this << endl;
        Date temp = *this;
        
        if (temp.month + other.month > 12) {
            temp.year++;
            temp.month -= 12;
        }
        temp.month = temp.month + other.month;
        if (temp.day + other.day > days[temp.month-1]) {
            temp.month++;
            temp.day -= days[temp.month - 1];
        }
        temp.day = temp.day + other.day;
        temp.year += other.year;

        return temp;
    }

    Date& operator - (const Date& other) {
        cout << "Перегрузка оператора вычитания " << this << endl;
        Date temp = *this;

        temp.year -= other.year;

        if (temp.month - other.month < 0) {
            temp.year--;
            temp.month += 12;
        }
        temp.month = temp.month - other.month;
        
        if (temp.day - other.day < 0) {
            temp.month--;
            temp.day += days[temp.month+1];
        }
        temp.day = temp.day - other.day;


        return temp;
    }

    Date& operator + (const int& other) {
        Date temp = *this;
        int dayCount = other;
        int year = dayCount / 365;
        dayCount -= year * 365;
        int month = 0;
        int day = 0;
        for (int i = 1; i < 13; i++) {
            if (dayCount > days[i])
            {
                dayCount -= days[i];
                month++;
            }
            else {
                day = dayCount;
                break;
            }
        }
        Date newDate(day, month, year);
        temp = temp + newDate;
        return temp;
    }


    Date& operator++() {
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
    Date operator++(int) {
        Date prev = *this;
        ++* this;
        return prev;
    }
    Date& operator--() {
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

    Date operator--(int) {
        Date prev = *this;
        --* this;
        return prev;
    }
    friend Date operator+(int value, const Date& obj);

    Date& operator - (const int& other) {
        Date temp = *this;
        int dayCount = other;
        int year = dayCount / 365;
        dayCount -= year * 365;
        int month = 0;
        int day = 0;
        for (int i = 1; i < 13; i++) {
            if (dayCount > days[i])
            {
                dayCount -= days[i];
                month++;
            }
            else {
                day = dayCount;
                break;
            }
        }
        Date newDate(day, month, year);
        temp = temp - newDate;
        return temp;
    }

    
    friend ostream& operator << (ostream& os, const Date& object);
};

Date operator+(int other, const Date& obj) {
    Date temp = obj;
    int dayCount = other;
    int year = dayCount / 365;
    dayCount -= year * 365;
    int month = 0;
    int day = 0;
    for (int i = 1; i < 13; i++) {
        if (dayCount > obj.days[i])
        {
            dayCount -= obj.days[i];
            month++;
        }
        else {
            day = dayCount;
            break;
        }
    }
    Date newDate(day, month, year);
    temp = temp + newDate;
    return temp;
}


ostream& operator << (ostream& os, const Date& object) {
    cout << "Перегрузка оператора вывода " << endl;
    os << object.day << " " << object.month << " " << object.year << endl;

    return os;
}

/*Date AddDay(const int dayCount, const Date& other) {
    Date temp;
    return temp;
}*/

//int& operator + (const Date& other) {
//    int temp = *this;
//    return AddDay(this, other);
//}

int main() {
    setlocale(LC_ALL, "RUS");
    Date start_date(1, 4, 2010);
    Date interval(31, 3, 2);
    Date work_date;
    cout << start_date;
    work_date = start_date + interval;
    cout << work_date;
    work_date = work_date - interval;
    cout << work_date;
    work_date = start_date + 400;
    cout << work_date;
    work_date = work_date - 400;
    cout << work_date;
    work_date++;
    cout << work_date;
    work_date--;
    cout << work_date;
    return 0;
}