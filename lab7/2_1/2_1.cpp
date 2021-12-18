#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

class Complex {
private:
    // vehestvennay i mnimay
    double m_re, m_im;

public:

    Complex();
    Complex(double re, double im = 0) {
        this->m_re = re;
        this->m_im = im;
    }

    double GetRe()
    {
        return m_re;
    }
    double GetIm()
    {
        return m_im;
    }

    Complex operator+(const Complex& a)
    {
        return Complex(m_re + a.m_re, m_im + a.m_im);
    }
    Complex operator-(const Complex& a)
    {
        return Complex(m_re - a.m_re, m_im - a.m_im);
    }

    // вывод в поток
    friend ostream& operator<< (ostream& out, const Complex& x)
    {
        return (out << "(" << x.m_re << "," << x.m_im << ")");
    }
};
int main()
{
    Complex с1(2, 3);
    Complex c2(4, 6);
    Complex c3 = с1 + c2;
    cout << c3 << endl;
    Complex c4 = с1 - c2;
    cout << c4 << endl;
}