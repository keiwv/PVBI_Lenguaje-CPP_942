#include <iostream>
#include "Materia.h"
#include "Universidad.h"
using namespace std;

int main()
{
    Universidad uni;
    uni.RegistrarEstudiante("Sisimo matriz", "Tronco comun");
    uni.RegistrarEstudiante("nose ", "aksdnaskd");
    uni.RegistrarEstudiante("Hola", "nose");

    uni.ReporteEstudiantes();
}