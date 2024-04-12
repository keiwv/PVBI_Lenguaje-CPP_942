#pragma once

#include <string>
#include <map>
#include "Estudiante.h"
#include "Materia.h"
#include <sstream>
#include <iomanip>

using namespace std;

class Universidad
{
protected:
    string nombre;
    map<int, Estudiante *> estudiantes;
    map<int, Materia *> materias;
    int cont_mat = 333000;
    int cont_cm = 40000;

public:
    Universidad(string nom = "WABECE") { nombre = nom; };
    string GetNombre() const { return nombre; };
    Estudiante *RegistrarEstudiante(string nombre, string carrera);
    Materia *RegistrarMateria(string nombre, int creditos, bool obligatoria = true, Materia::Etapa etapa = Materia::BASICA);
    void RegistrarCalificaciones(int matricula, int clave, int valor);
    void ReporteEstudiante() const {}
};

Estudiante *Universidad::RegistrarEstudiante(string nombre, string carrera)
{
    Estudiante *new_est = new Estudiante(++cont_mat, nombre, carrera);
    estudiantes[cont_mat] = new_est;
    return new_est;
}

Materia *Universidad::RegistrarMateria(string nombre, int creditos, bool obligatoria = true, Materia::Etapa etapa = Materia::BASICA)
{
    Materia *new_mat = new Materia(++cont_mat, nombre, creditos, obligatoria, etapa);
    materias.insert({cont_cm, new_mat});
    return new_mat;
}

void Universidad::RegistrarCalificaciones(int matricula, int clave, int valor)
{
    auto ite = estudiantes.find(matricula);
    if (ite == estudiantes.end())
    {
        throw "Estudiante no existe";
    }

    auto itm = materias.find(clave);
    {
        throw "Materia no existente";
    }

    (*ite).second->GetKardex().RegistrarCalificacion({valor, materias[clave]});
}

void Universidad::ReporteEstudiante() const
{
    cout << "----------------------------------------------------------------------------------";
    cout << "Matricula: " << setw(50) << left << "Nombre";
    cout << "Carrera: " << endl;
    cout << "----------------------------------------------------------------------------------";
    for (auto pe : estudiantes)
    {
        cout << pe.second->ToString() << endl;
    }
    cout << "----------------------------------------------------------------------------------";
}
