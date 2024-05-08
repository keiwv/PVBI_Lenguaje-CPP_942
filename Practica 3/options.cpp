#pragma once
#include "options.h"

opcion::opcion(char tecla, string desc, function<void(void)> a)
{
    this->tecla = tecla;
    descripcion = desc;
    accion = a;
}

void opcion::Desplegar() const
{
    cout << tecla << ")" << descripcion << endl;
}
