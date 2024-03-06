#include <iostream>
using namespace std;

int dividir(int n, int d)
{
    int r;
    if (d == 0)
    {
        throw "Error: Division entre cero...";
    }

    r = n / d;
    return r;
}

int main()
{
    int x, y;
    cout << "Dame el diviendo: ";
    cin >> x;
    cout << "Dame el divisor: ";
    cin >> y;

    try
    {
        int d = dividir(x, y);
        cout << "El resultado es: " << d << endl;
    }
    catch(const char *e)
    {
        cout << e << endl;
    }

    return 0;
}