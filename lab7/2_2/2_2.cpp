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

template <class T>
class Matrix {

private:
    T** M; // Matrix
    int m; // строки
    int n; // столбцы

public:

    Matrix()
    {
        n = m = 0;
    }

    Matrix(int m, int n)
    {
        this->m = m;
        this->n = n;

        M = (T**) new T * [m];


        for (int i = 0; i < m; i++)
            M[i] = (T*)new T[n];

        //Matrix full 0
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
    }

    void SetMij(int i, int j, T value)
    {
        if ((i < 0) || (i >= m))
            return;
        if ((j < 0) || (j >= n))
            return;
        M[i][j] = value;
    }

    void Print()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "---------------------" << endl << endl;
    }

    Matrix operator=(const Matrix& _M)
    {
        if (n > 0)
        {

            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
        {
            delete[] M;
        }

        // coppy data M <= _M
        m = _M.m;
        n = _M.n;

        // memory clean
        M = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];

        // copy
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
        return *this;
    }

    // destructor
    ~Matrix()
    {
        if (n > 0)
        {
            // освободить выделенную память для каждой строки
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
    }
};
int main()
{
    float f = 1.2;
    Matrix <int>matrix(3, 3); 
    matrix.SetMij(1, 1, f);
    matrix.SetMij(1, 2, 3);
    matrix.SetMij(2, 1, 'a');
    matrix.Print();


    Complex сomplex(2.1);
    Matrix <int>matrix1(3, 3);
    matrix1.SetMij(1, 1, 4.1);
    matrix1.SetMij(1, 2, 3);
    //matrix1.SetMij(2, 1, complex);
    matrix1.Print();

    // записала сюда класс complex для того чтобы записать в матрицу.
    // могла это сделать в одном проекте и подключить файл с комплексом
    // но мне хотелось разные main'ы
}