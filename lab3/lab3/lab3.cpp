#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Goods {
private:
    string name;
    string date;
    int price;
    int quantity;
    int number;

    float total_price(int quantity, float price) {
        return quantity * price;
    }

public:
    /*Goods() {
        cout << "Вызов конструктора по умолчанию" << endl;
    };*/
    Goods(string name, string date, int price, int quantity, int number) {
        cout << "Вызов конструктора " << this << endl;
        this->name = name;
        this->date = date;
        this->price = price;
        this->quantity = quantity;
        this->number = number;
    }
    ~Goods() {
        cout << "Вызов деструктора " << this << endl;
    }

    void get_data() {
        cout << name << endl;
        cout << date << endl;
        cout << price << endl;
        cout << quantity << endl;
        cout << number << endl;
        cout << total_price(quantity, price) << endl;
    }

    void set_name(string name) {
        this->name = name;
        cout << "Вы поменяли имя на" << endl;
    }
    void set_date(string date) {
        this->date = date;
        cout << "Вы поменяли дату на " << endl;
    }
    void set_price(int price) {
        this->price = price;
        cout << "Вы поменяли цену на " << endl;
    }
    void set_quantity(int quantity) {
        this->quantity = quantity;
        cout << "Вы поменяли количество на " << endl;
    }
    void set_number(int number) {
        this->number = number;
        cout << "Вы поменяли номер на: " << endl;
    }

    Goods(const Goods& object)
    {
        cout << "Вызов конструктора копирования объекта " << this << endl;
        name = object.name;
        date = object.date;
        price = object.price;
        quantity = object.quantity;
        number = object.number;
    }

    Goods& operator = (const Goods& object) {
        cout << "Перегрузка оператора присваивания " << this << endl;
        name = object.name;
        date = object.date;
        price = object.price;
        quantity = object.quantity;
        number = object.number;

        return *this;
    }
};

Goods tovar(Goods& s);

Goods tovar(Goods& s) {
    cout << "Вызов функции tovar" << endl;
    return s;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Вход в функцию main" << endl;
    Goods test("Видеокарта", "19.04.21", 90000, 150, 7904);


    //Goods test;
    Goods products(test);
    tovar(products);
    //tovar(test);
    test = products;

    test.get_data();
    cout << "Выход из функции main" << endl;

}