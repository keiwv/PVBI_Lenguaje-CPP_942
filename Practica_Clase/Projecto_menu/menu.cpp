#include <iostream>
#include "menu.h"
#include "conio.h"

using namespace std;
void Listado()
{
    cout << "Archivos en el folder: " << endl;
    system("dir");
    getchar();
}

void ConfiguracionIP()
{
    cout << "COnfiguracion ip:" << endl;
    system("ipconfig");
    getchar();
}

void ConexionesActivas()
{
    cout << "Conexiones activas:" << endl;
    system("netstat");
    getchar();
}

void Configuracion()
{
    Menu submenu("Menu de configuracion");

    submenu.Agregar({'1', "Subopcion 1", []()
                     {cout <<  "Ejecutando subopcion 1..." << endl; getchar(); }});
    submenu.Agregar({'2', "Subopcion 2", []()
                     {cout <<  "Ejecutando subopcion 2..." << endl; getchar(); }});
    submenu.Agregar({'1', "Subopcion 3", []()
                     {cout <<  "Ejecutando subopcion 3..." << endl; getchar(); }});
    submenu.Agregar({'1', "Subopcion 4", []()
                     {cout <<  "Ejecutando subopcion 4..." << endl; getchar(); }});
    submenu.Agregar({'5', "Regresar", []() {
                     }});
    
}

int main()
{
    Menu el_menu("Menu de prueba");
    el_menu.Agregar({'1', "Ver listado de archivos", Listado});

    el_menu.Agregar({'2', "Ver configuración IP", ConfiguracionIP});
    el_menu.Agregar({'3', "Ver conexiones activas", ConexionesActivas});
    el_menu.Agregar({'4', "Configuracion", Configuracion});
    el_menu.Agregar({'5', "Salir", []()
                     { cout << "Adios" << endl; }});
    do
    {
        system("clear");
        el_menu.Desplegar();
    } while (el_menu.Seleccionar() != '4');
}
