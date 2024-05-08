#include <iostream>
#include "Banco.h"

using namespace std;

int main()
{
    Banco Azteca = Banco("Azteca");

    Azteca.crearCuentaHabiente("PEDRO", "ASKJDNASJDNASJND");
    cout << "HOLA\n" << endl;
    return 0;
}