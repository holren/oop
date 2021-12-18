#include <iostream>
#include <iomanip>

using namespace std;
char s[255] = "adadad\n";

ostream& endp(ostream& out, int n, string s) {

    char ss[255];
    static int k = 0;
    int i, j, c = n;
    for (i = 0, j = 0; s[j] != '\0'; i++, j++)
    {
        ss[i] = s[j];
        if (ss[i] == '\n')
        {
            k++;
            if (k == c)
            {
                ss[i + 1] = '\n';
                out << "\n-------------\n";
                i = -1;
            }
        }
    }
    if (i < 0)
    {
        ss[i + 1] = '\0';
        out << ss;
    }
    out << s;
    return out;
}

ostream& endp(ostream& out, int n) {

    char ss[255];
    static int k = 0;
    int i, j, c = n;
    for (i = 0, j = 0; s[j] != '\0'; i++, j++)
    {
        ss[i] = s[j];
        if (ss[i] == '\n')
        {
            k++;
            if (k == c)
            {
                ss[i + 1] = '\n';
                out << "\n--\n";
                i = -1;
            }
        }
    }
    if (i < 0)
    {
        ss[i + 1] = '\0';
        out << ss;
    }
    return out;
}

ostream& endp(ostream& out) {

    char ss[255];
    static int k = 0;
    int i, j, c = 5;
    for (i = 0, j = 0; s[j] != '\0'; i++, j++)
    {
        ss[i] = s[j];
        if (ss[i] == '\n')
        {
            k++;
            if (k == c)
            {
                ss[i + 1] = '\n';
                out << "\n-------------\n";
                i = -1;
            }
        }
    }
    if (i < 0)
    {
        ss[i + 1] = '\0';
        out << ss;
    }
    return out;
}


int main()
{
    //ex2
    cout << endl << endl << setfill('*') << setw(50) << "ex2" << endl;
    string s = "KAte";
    bool b = -1;
    int i = 30;

    cout << boolalpha << b << endl; // True/False
    cout << noboolalpha << b << endl; //0,1

    int value = 64;
    cout << oct << i << endl; // 8
    cout << dec << i << endl; // 10
    cout << hex << i << endl; // 16


    value = 255;
    cout << uppercase << i << endl; // Upper

    cout << nouppercase << i << endl; // another
    cout.unsetf(ios::hex);


    cout << showpos << i << endl; // if int >0 then +

    cout << noshowpos << i << endl; // another

    double value1 = 1024.165;
    cout << scientific << value1 << endl; // exponental

    cout << fixed << value1 << endl; // another

    cout << setw(50) << s << endl; // shirina

    cout << setw(50) << right << s << endl; // right - vyravnivaet

    cout << setw(50) << left << s << endl; // left - vyravnivaet
    cout.unsetf(ios::left);


    cout << fixed << setprecision(3) << 34.34456789 << endl; // colvo znakov posle zapatou

    cout << setfill('-') << setw(50) << "123456789" << endl; // zapolnyet


    //ex3
    cout << endl << endl << setfill('*') << setw(50) << "ex3" << endl;
    //boolalpha, oct, dec, hex, showbase, uppercase, showpos, scientific, fixed, right, left , fill

    cout.setf(ios::hex);
    cout << 12 << endl;
    cout.unsetf(ios::hex);


    //4.1
    cout << endl << endl << setfill('*') << setw(50) << "ex4" << endl;
    for (i = 0; i < 7; i++)
        cout << s << endp;

    //4.2
    /*
    cout << endl << endl << setfill('*') << setw(50) << "ex4.2" << endl;
    for (i = 0; i < 7; i++)
        cout << s << endp(2);
    */

    //4.3
    /*
    cout << endl << endl << setfill('*') << setw(50) << "ex4.3" << endl;
    int f = 2;
    for (i = 0; i < 7; i++)
        cout << s << endp(f,s);
    */

}