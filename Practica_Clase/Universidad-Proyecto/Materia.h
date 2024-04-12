#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Materia
{
public:
    enum Etapa
    {
        BASICA,
        DISCIPLINARIA,
        TERMINAL
    };

protected:
    int clave;
    string nombre;
    int creditos;
    bool esObligatorio;
    Etapa etapa;

public:
    Materia(int clave = 0, string name = " ", int creditos = 0, bool esObligatoria = false, Etapa etapa_ = BASICA);
    // Getters
    int getClave() { return clave; };
    string getNombre() const { return nombre; };
    int getCreditos() const
    {
        return creditos;
    };

    bool getObligatoria() const { return esObligatorio; };
    Etapa getEtapa() const
    {
        return etapa;
    };

    string toString() const;
};

Materia::Materia(int clave, string name, int creditos, bool esObligatoria, Etapa etapa_)
{
    this->clave = clave;
    this->nombre = name;
    this->creditos = creditos;
    this->esObligatorio = esObligatoria;
    this->etapa = etapa_;
}

string Materia::toString() const
{
    std::ostringstream out;

    out << setw(6) << clave << " ";
    out << setw(50) << left << nombre << " ";
    out << setw(8) << left << creditos << " ";
    out << setw(4) << left;

    if (esObligatorio)
    {
        out << "Obl ";
    }
    else
    {
        out << "Opt ";
    }

    switch (etapa)
    {
    case BASICA:
        out << "Basica\t";
        break;
    case DISCIPLINARIA:
        out << "Disciplinaria\t";
        break;
    case TERMINAL:
        out << "Terminal\t";
        break;
    }

    return out.str();
}