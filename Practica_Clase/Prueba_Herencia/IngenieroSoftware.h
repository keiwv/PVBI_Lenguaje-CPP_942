#pragma once
#include "Ingenierio.h"

class IngSoftware : public Ingeniero
{
public:
    IngSoftware(string nombre = "El metodo", string cedula = "De reddit", int edad = 25, int experiencia = 3);
    virtual void Programar();
    virtual void resolverProblemas() override;
};

IngSoftware::IngSoftware(string nombre = "William", string cedula = "De tepito", int edad = 25, int experiencia = 3) : Ingeniero(nombre, cedula, edad, experiencia) {}

void IngSoftware::Programar()
{
    cout << "Pidiendole un programa a ChatGPT " << endl;
}

void IngSoftware::resolverProblemas()
{
    cout << "Checkeando tiktok " << endl;
    Programar();
    cout << "Checkeando mi instagram " << endl;
}
