#include <iostream>
#include <algorithm>
#include "stack.h"

using std::cout;
using std::endl;

int main()
{
    cout << "Elementos de primera pila: ";
    Stack<int> pila;
    pila.push(9);
    pila.push(1);
    pila.push(3);
    pila.push(6);
    pila.push(5);
    pila.push(7);
    pila.push(8);
    pila.push(9);
    while (!pila.IsEmpty())
    {
        cout << " " << pila.pop();
    }
    cout << endl;
    cout << "Elementos de segunda pila: ";
    Stack<double> pila2;
    pila2.push(1.5);
    pila2.push(2.2);
    pila2.push(5.2);

    while(!pila2.IsEmpty())
    {
        cout << " " << pila2.pop();
    }

}