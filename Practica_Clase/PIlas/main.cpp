#include <iostream>
#include "stack.h"

using std::cout;
using std::endl;

int main()
{
    Stack pila;
    pila.push(9);
    pila.push(1);
    pila.push(3);
    pila.push(6);
    pila.push(5);
    pila.push(7);
    pila.push(8);
    pila.push(9);

    while(!pila.IsEmpty())
    {
        cout << " " << pila.pop();
    }
}