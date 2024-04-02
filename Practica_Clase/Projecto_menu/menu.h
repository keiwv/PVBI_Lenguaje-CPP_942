#pragma once

#include <string>
#include "options.h"
#include <map>
using namespace std;

class Menu
{
protected:
    string titulo;
    map<char, opcion> opciones;
    public:
    Menu(string  titulo = "Menu");
};


Menu::Menu(string titulo = "Menu")
{
    this->titulo = titulo;
}