// Persona.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Persona
{
public:
    int edad = 10;
    std::string nombre;

    virtual void Reir() const;
    void Comer() const;

public:
    Persona();
    Persona(const std::string& el_nombre, int la_edad);
    virtual void Saludar(){std::cout << "Hola, yo soy " << nombre << " y tengo " << edad << " años" << std::endl;}
    virtual void HacerReir(int motivo) const;

    std::string GetNombre() const;
    void SetNombre(const std::string& nuevo_nombre);

    int GetEdad() const;
    void SetEdad(int nueva_edad);

    friend std::ostream& operator<<(std::ostream& out, const Persona& persona);
    
};

void Persona::Reir() const {
    std::cout << "Jajajaja" << std::endl;
}

void Persona::Comer() const {
    std::cout << "Nom, nom, nom...." << std::endl;
}

Persona::Persona() : edad(18), nombre("Sosimo") {}

Persona::Persona(const std::string& el_nombre, int la_edad) : edad(la_edad), nombre(el_nombre) {}

void Persona::HacerReir(int motivo) const {
    if (motivo % 3 == 0) {
        Reir();
    }
    else {
        std::cout << ":|" << std::endl;
    }
}

std::string Persona::GetNombre() const {
    return nombre;
}

void Persona::SetNombre(const std::string& nuevo_nombre) {
    nombre = nuevo_nombre;
}

int Persona::GetEdad() const {
    return edad;
}

void Persona::SetEdad(int nueva_edad) {
    edad = (nueva_edad > 0) ? nueva_edad : edad;
}

std::ostream& operator<<(std::ostream& out, const Persona& persona) {
    out << "Persona[" << persona.GetNombre() << "," << persona.GetEdad() << "]";
    return out;
}


