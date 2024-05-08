#include "menu.h"

Menu::Menu(string titulo)
{
    this->titulo = titulo;
}

void Menu::Agregar(opcion la_opcion)
{
    if (opciones.find(la_opcion.getTecla()) == opciones.end())
    {
        opciones.insert({ la_opcion.getTecla(), la_opcion });
    }
    else
    {
        throw "La opcion ya existe en el menu....";
    }
}

void Menu::Eliminar(char tecla)
{
    auto it = opciones.find(tecla);

    if (it != opciones.end())
    {
        opciones.erase(it);
    }
}

void Menu::Desplegar()
{
    cout << titulo << endl;
    for (auto& par : opciones)
    {
        par.second.Desplegar();
    }
}

char Menu::Seleccionar()
{
    char select;

    while (true)
    {

        cout << "Selecciona tu opcion: ";
        cin >> select;

        auto it = opciones.find(select);
        if (it != opciones.end())
        {
            (*it).second.ejectuar();
            return select;
        }
        else
        {
            cout << "Opcion no valida." << endl;
        }
    }
    return select;
}

void Menu::Ejecutar()
{
    do
    {
        system("clear");
        Desplegar();
    } while (Seleccionar() != exit_key);
}