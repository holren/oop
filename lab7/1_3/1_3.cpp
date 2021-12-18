#include <iomanip>
#include <iostream>
using namespace std;

template <typename T>
T my_max(T a, T b)
{
    cout << "max T" << endl;
    return (a > b) ? a : b;
}
const char* my_max(const char* a, const char* b)
{
    cout << "max char" << endl;
    return (a > b) ? a : b;
}

int main()
{
    int i = my_max(0,1);
    string s = my_max("ka", "te");
    const char* ch = my_max("Hello","World");
    cout << "i = " << i << endl;
    cout << "s = " << s << endl;
    cout << "ch = " << ch << endl;

}