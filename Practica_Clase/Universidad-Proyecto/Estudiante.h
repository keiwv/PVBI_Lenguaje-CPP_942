#pragma once
#include <string>
#include "Kardex.h"

class Estudiante
{
    protected:
    int matricula;
    string nombre;
    string carrera;
    Kardex kardex;
public:
    Estudiante(int matricula = 0, string nombre = "", string carrera = "");
};

Estudiante::Estudiante(int matricula = 0, string nombre = "", string carrera = "")
{
    this->matricula = matricula;
    this->nombre = nombre;
    this->carrera = carrera;
    kardex = Kardex(this);

}