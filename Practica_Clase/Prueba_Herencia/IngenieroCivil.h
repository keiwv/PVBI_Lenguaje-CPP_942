#pragma once

#include "Ingenierio.h"

class Ingcivil : public Ingeniero
{

    public:
    Ingcivil(string nombre = "William", string cedula = "De tepito", int edad = 25, int experiencia = 3);
    virtual void Construir();
    virtual void resolverProblemas() override;
}  ;


Ingcivil::Ingcivil(string nombre = "William", string cedula = "De tepito", int edad = 25, int experiencia = 3) : Ingeniero(nombre, cedula, edad, experiencia){}

void Ingcivil::Construir()

{
    cout << "Construyendo... meneando la cuchara con estilo" << endl;
}

void Ingcivil::resolverProblemas()
{
    this->Construir();
}