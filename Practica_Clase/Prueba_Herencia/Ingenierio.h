#pragma once
#include "Profesionista.h"
class Ingeniero : public Profesionista
{
    public:
    Ingeniero(string nombre = "William", string cedula = "De tepito", int edad = 25, int experiencia = 3);

    virtual void resolverProblemas();
    virtual void Trabajar() override;
};


Ingeniero::Ingeniero(string nombre = "William", string cedula = "De tepito", int edad = 25, int experiencia = 3):Profesionista(nombre, cedula, edad, experiencia)
{
}


void Ingeniero::resolverProblemas()
{
    cout << "Resolviendo problemas con creatividad e ingenieno" << endl;
}

void Ingeniero::Trabajar()
{
    // Utilizando el operador de resolución de ámbito para mandara llamar
    // la función trabajar de profesionalista
    Profesionista::Trabajar();
    resolverProblemas();
}