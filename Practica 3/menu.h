#pragma once

#include <string>
#include "options.h"
#include <map>
#include <iostream>

using namespace std;

class Menu
{
protected:
    string titulo;
    map<char, opcion> opciones;
    char exit_key;

public:
    Menu(string titulo);
    void Agregar(opcion la_opcion);
    void Eliminar(char tecla);
    void Desplegar();
    char Seleccionar();
    void Ejecutar();
};



