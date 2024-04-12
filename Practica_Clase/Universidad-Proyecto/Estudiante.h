#pragma once
#include <string>
#include "Kardex.h"
#include <sstream>
#include <iomanip>

using namespace std;

class Estudiante
{
protected:
    int matricula;
    string nombre;
    string carrera;
    Kardex kardex;

public:
    Estudiante(int matricula = 0, string nombre = "", string carrera = "");

    // Getters
    int getMatricula() const { return matricula; };
    string GetNombre() const { return nombre; };
    string GetCarrera() const { return carrera; };
    Kardex GetKardex() const { return kardex; };

    string ToString() const;
};

Estudiante::Estudiante(int matricula = 0, string nombre = "", string carrera = "")
{
    this->matricula = matricula;
    this->nombre = nombre;
    this->carrera = carrera;
    kardex = Kardex(this);
}

string Estudiante::ToString() const
{
    ostringstream out;
    out << setw(8) << left << matricula << " ";
    out << setw(50) << left << nombre << " ";
    out << carrera;
    return out.str();
}