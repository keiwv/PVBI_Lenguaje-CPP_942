#include <functional>
#include <iostream>
#include <vector>
#include <ostream>
#include <algorithm>

using namespace std;
using std::function;

void Saludo();
void Saludar(function<void(void)> fs);
void Saludo2();
vector<int> contarPares(vector<int> v);
ostream &operator<<(ostream &out, vector<int> v);

int contar(vector<int> v, function<bool(int)> p)
{
    int conteo = 0;
    for (int n : v)
    {
        if (p(n) == true)
        {
            conteo++;
        }
    }
    return conteo;
}
vector<int> extraer(vector<int> v, function<bool(int)> p)

{
    vector<int> elem;
    for (int n : v)
    {
        if (p(n) == true)
        {
            elem.push_back(n);
        }
    }
    return elem;
}

bool isPair(int x)
{
    return ((x % 2) == 0);
}

bool isPrime(int x)
{
    if (x == 2 || x == 3)
    {
        return true;
    }

    if (x == 1 || (x % 2) == 0 || (x % 3) == 0)
    {
        return false;
    }

    for (int d = 5; d <= x / 2; x = x + 2)
    {
        if ((x % d) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    system("clear");
    Saludo();
    function<void(void)> f = Saludo;

    f();

    cout << endl;

    Saludar(f);

    cout << endl;

    Saludar(Saludo2);

    vector<int> numeros = {12, 31, 23, 23, 23, 123, 213, 2, 13, 123, 123};

    cout << "Vector: " << numeros << endl;

    cout << "Hay " << contarPares(numeros) << "numeros par en el vector" << endl;

    vector<int> n2 = extraer(numeros, isPair);

    cout << "Hay: " << n2.size() << " numeros par en el vector" << endl;
    cout << "Numeros par: " << n2 << endl;

    n2 = extraer(numeros, isPrime);

    cout << "Hay: " << n2.size() << " numeros primos en el vector" << endl;
    cout << "Numeros primos: " << n2 << endl;

    // EXPRESIÓN ALFA
    auto m5 = [](int x) -> bool
    { return (x % 5) == 0; };
    n2 = extraer(numeros, m5);
    cout << "Hay: " << n2.size() << " numeros multiplos de 5 en el vector" << endl;
    cout << "Numeros multiplos de 5: " << n2 << endl;

    cout << std::count_if(numeros.begin(), numeros.end(), [](int x){return((x % 3) == 0);});
    cout << "Multplo de 3 en el vector..." << endl;
}

void Saludo()
{
    cout << "Hola mundo" << endl;
}

void Saludar(function<void(void)> fs)
{
    cout << "Te voy a saludar..." << endl;
    cout << "... preparate ..." << endl;
    fs();
    cout << "... listo!" << endl;
}
void Saludo2()
{
    srand(time(0));

    if ((rand() % 100) > 50)
    {
        cout << "que transa..." << endl;
    }
    else
    {
        cout << "Hola, buenos días..." << endl;
    }
}

vector<int> contarPares(vector<int> v)
{
    vector<int> pares;
    for (int n : v)
    {
        if ((n % 2) == 0)
        {
            pares.push_back(n);
        }
    }

    return pares;
}

ostream &operator<<(ostream &out, vector<int> v)
{
    out << "[ ";
    for (int n : v)
    {
        cout << n << " ";
    };
    out << "]";

    return out;
}
