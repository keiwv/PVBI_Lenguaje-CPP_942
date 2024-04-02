#pragma once
#include <iostream>
#include <functional>
#include <string>

using namespace std;

class opcion
{
protected:
    string descripcion;
    char tecla;
    function<void(void)> accion;

public:
    opcion(char tecla = 0, string desc = "", function<void(void)> a = []() {});
    char getTecla() const { return tecla; };
    string getDescripcion() const{return descripcion;};
    void Desplegar() const;
    void ejectuar() const { accion();}
};

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