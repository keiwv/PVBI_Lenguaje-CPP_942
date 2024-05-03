// Estudiante.h
#pragma once
#include <string>
#include "Persona.h"

using namespace std;

class Estudiante : public Persona
{
public:
    int matricula;
    int semestre = 1;
    string carrera = "Ing. Software";

public:
    Estudiante();
    Estudiante(int matricula, int semestre, string carrera, string nombre, int edad);
    void Estudiar() { cout << "Estoy estudiando bro" << endl; }
    void Saludar()  override {cout << "Estudiando duro y viendo a don posho" << endl;}
};

Estudiante::Estudiante(int matricula, int semestre, string carrera, string nombre, int edad) : Persona(nombre, edad)
{
    this->matricula = matricula;
    this->semestre = semestre;
    this->carrera = carrera;
};

Estudiante::Estudiante():Persona(nombre.c_str(), 10)
{
    matricula = 372781;
    semestre = 1;
    carrera = "Ing. Software";
}