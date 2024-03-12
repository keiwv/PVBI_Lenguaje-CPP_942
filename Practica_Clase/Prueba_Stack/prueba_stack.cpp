#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

void stackTest();
void stackTest2();
void stackTest3();

int main()
{
    stackTest3();
    return 0;
}

void stackTest()
{
    stack<int> pila;
    int n;

    while (true)
    {
        cout << "Give me a number (-1 para terminar): ";
        cin >> n;

        if (n == -1)
        {
            break;
        }
        pila.push(n);
    }

    cout << "Cantidad de elementos agregados a la pila: " << pila.size() << endl;
    cout << "Elemento en el tope de la fila: " << pila.top() << endl;
    cout << "Todos los elementos de la pila: ";

    while (!pila.empty())
    {
        cout << " " << pila.top();
        pila.pop();
    }
    cout << endl;
}

void stackTest2()
{
    string frase;
    bool palindromo = true;
    stack<char> pila;

    cout << "Dime una frase: ";
    getline(cin, frase);

    int fraseSize = frase.size();
    for (int i = 0; i < fraseSize; i++)
    {
        if (frase[i] != ' ')
        {
            pila.push(frase[i]);
        }
    }

    for (char c : frase)
    {
        if (c != ' ')
        {
            if (tolower(c) != pila.top())
            {
                palindromo = false;
                break;
            }
            pila.pop();
        }
    }
    if (palindromo)
    {
        cout << "\"" << frase << "\""
             << " es palindromo" << endl;
    }
    else
    {
        cout << "\"" << frase << "\""
             << " no es palindromo" << endl;
    }
}

void stackTest3()
{

    queue<int> cola;
    int n;
    while (true)
    {
        cout << "Give me a number (-1 para terminar): ";
        cin >> n;

        if (n == -1)
        {
            break;
        }
        cola.push(n);
    }

    cout << "Numero de elementos en cola: " << cola.size() << endl;
    cout << "Ultimo elemento de la cola: " << cola.back() << endl;
    cout << "Primer elemento de la cola: " << cola.front() << endl;
    cout << "Elementos de la cola: ";
    while (!cola.empty())
    {
        cout << " "<< cola.front();
        cola.pop();
    }
    cout << endl;
}