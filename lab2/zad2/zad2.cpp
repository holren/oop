#include <iostream>
using namespace std;

class Abonent {
    friend class Notebook;
private:
    int number;
    string fio;
    int phone_number;

public:
    Abonent(int number, string fio, int phone_number) {
        cout << "Вызов конструктора" << endl;
        this->number = number;
        this->fio = fio;
        this->phone_number = phone_number;
    }
    ~Abonent() {
        cout << "Вызов деструктора" << endl;
    }

};

class Notebook {
public:
    void change(Abonent& a, int new_phone_number) {
        a.phone_number = new_phone_number;
    }

    void show(Abonent& a) {
        cout << a.number << endl;
        cout << a.fio << endl;
        cout << a.phone_number << endl << endl;
    }
    int get_number(Abonent& a) {
        return a.number;
    }

};


int main()
{
    setlocale(LC_ALL, "Rus");
    Abonent Abonents[5]{
        Abonent(20,"Иванова Валерия Кактовна", 80732954),
        Abonent(21, "Тафт Александра Николаевна", 893858378),
        Abonent(22, "Вербицкий Михаил Дмитриевич", 8938238375),
        Abonent(23, "Беккер Ирэн Арчибальд", 893844448),
        Abonent(24, "Бэккер Джейк Филиппович", 890574839)
    };
    Notebook object;


    for (int i = 0; i < 4; i++)
    {
        object.show(Abonents[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        if (object.get_number(Abonents[i]) == 22)
        {
            object.change(Abonents[i], 909009090);
            object.show(Abonents[i]);
        }
    }
    return 0;
}


