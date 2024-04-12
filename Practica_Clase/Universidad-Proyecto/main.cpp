#include <iostream>
#include "Materia.h"
using namespace std;

int main()
{
    Materia m1(123123, "Programacion y metodos numeros", 7, true, Materia::Etapa::BASICA);

    Materia m2(23828, "Estadistica avanzada", 6, true, Materia::Etapa::BASICA);

    cout << "Clave ";
    cout << setw(50) << left << "Nombre";
    cout << "Creditos tipo etapa" << endl << endl;

    cout << m1.toString() << endl;
    cout << m2.toString() << endl;

    return 0;
}