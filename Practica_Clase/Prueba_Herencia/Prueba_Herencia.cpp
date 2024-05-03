#include <iostream>
#include "Estudiante.h"
#include "Profesionista.h"
#include "Persona.h"
#include "IngenieroCivil.h"
#include "IngenieroSoftware.h"

using namespace std;


void usarProfesionalista(Profesionista *prof)
{
    cout << "Usando profesionista (" << prof->GetNombre() << ")" << endl;
    prof->Saludar();
    prof->Trabajar();
    cout << " ------------------------------------------------------ "<< endl;
}

int main()
{
    Estudiante student;
    Estudiante student2(278321, 2, "Ing. SOftwareee", "Guillermo", 20);
    student2.Saludar();
    Profesionista profe;
    profe.Saludar();


    cout << "------ POLIMORFISMO ---------------- "<< endl;
    Persona *persona;
    persona = new Estudiante(99932, 2, "Ing, SOftwareeeee", "Brayan", 20);

    Persona &ref_persona = student2;

    persona->Saludar();
    ref_persona.Saludar();


    IngSoftware is;
    Ingcivil ic;

    usarProfesionalista(&is);
    usarProfesionalista(&ic);


    return 0;
}