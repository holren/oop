#include <iostream>
using namespace std;

class Test {
    friend void fun(Test& w);
private:
    int W;
public:
    Test(int param = 1) {
        W = param;
    }
    void Z() {
        cout << "Это закрытая функция класса Test" << endl;
    }
};

void fun(Test& w) {
    cout << "Объявили функцию другом класса. Ура" << endl;
    cout << "W = " << w.W << endl;
    w.Z();
}

int main()
{
    setlocale(LC_ALL, "Rus");
    Test a;
    fun(a);
    return 0;
}