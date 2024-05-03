#include <iostream>
#include "Persona.h"
#include <string>

using namespace std;

class Profesionista : public Persona
{
protected:
    string cedula;
    int experiencia;

public:
    Profesionista();
    Profesionista(string nombre, string cedula, int edad, int experiencia);
    virtual void Trabajar() { cout << "Mi primera chamba..." << endl; };
    virtual void Saludar() override  {
        cout << "Hola, soy el profesionista " << nombre << " tengo ";
        cout << experiencia << " años de experiencia y mi cedula es " << cedula << endl;
    }
};

Profesionista::Profesionista() : Persona("Nicolas", 25), cedula("De tepito"), experiencia(3) {}

Profesionista::Profesionista(string nombre, string cedula, int edad, int experiencia) : Persona(nombre, edad)
{
    this->cedula = cedula;
    this->experiencia = experiencia;
}