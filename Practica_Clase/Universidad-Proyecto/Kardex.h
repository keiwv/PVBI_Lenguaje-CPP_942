#pragma once

#include "calificacion.h"

#include <sstream>
#include <vector>

using namespace std;

class Estudiante;

class Kardex
{
protected:
    double promedio = 0;
    int creditos = 0;
    vector<Calificacion> calificaciones;
    Estudiante *estudiante;

public:
    Kardex(Estudiante *est = nullptr) { estudiante = est; };
    double GetPromedio() const { return promedio; };
    int getCreditos() const { return creditos; };

    void RegistrarCalificacion(Calificacion calif);

    string toString();
};

void Kardex::RegistrarCalificacion(Calificacion calif)
{
    calificaciones.push_back(calif);
    if (calif.GetValor() >= 60)
    {
        creditos += calif.GetMateria()->getCreditos();
    }

    double sc = 0;
    sc = promedio * (calificaciones.size() - 1);
    sc += calif.GetValor();

    promedio = sc / calificaciones.size();
}

string Kardex::toString()
{
    ostringstream out;

    out << "--------------------------------------------------------";
    out << "Clave  ";
    out << setw(50) << "Nombre";
    out << "Valor creditos" << endl;
    out << "--------------------------------------------------------";

    for (Calificacion &cal : calificaciones)
    {
        out << cal.toString() << endl;
    }

    out << "--------------------------------------------------------";
    out << "Promedio: " << setprecision(2) << promedio;
    out << "Creditos: " << creditos << endl;
    return out.str();
}