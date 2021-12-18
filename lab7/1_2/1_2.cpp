#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;


template <typename T>
void my_swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}
int main()
{
    int x = 2, y = 3;
    my_swap<int>(x, y);
    cout << x << " " << y << endl;

    string x1 = "ka", y1 = "te";
    my_swap<string>(x1, y1);
    cout << x1 << " " << y1 << endl;
    
}
