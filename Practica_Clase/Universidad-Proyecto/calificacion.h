#pragma once

#include "Materia.h"
#include <sstream>
#include <iomanip>

using namespace std;

class Calificacion
{
protected:
    int valor;
    Materia *materia;

public:
    Calificacion(int valor, Materia *materia);
    int GetValor() const { return valor; };
    Materia *GetMateria() const { return materia; };
    string toString();
};

Calificacion::Calificacion(int valor, Materia *materia)
{
    this->valor = valor;
    this->materia = materia;
}

string Calificacion::toString()
{
    ostringstream out;

    out << setw(6) << materia->getClave() << " ";
    out << setw(50) << left << materia->getNombre() << " ";
    out << setw(5) << right << valor << " ";
    out << setw(5) << right << materia->getCreditos();
    return out.str();
}