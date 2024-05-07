#pragma once
#include <string>
#include <map>
#include "CuentaDeCheques.h"
#include "CuentaHabiente.h"
#include <ctime>
#include <cstdlib>

using namespace std;

class Banco
{
protected:
    string nombre;
    int ch_count;     // Cantidad de cheques?
    int cuenta_count; // Cantidad de cuentas
    map<int, CuentaHabiente> accounts;

public:
    Banco(string nombre);
    void crearCuentaHabiente(string nombre, string CURP);  
    void crearCuentaCheques(float saldo, CuentaHabiente *propietario);
    CuentaHabiente ObtenerCuentaHabiente(int numero);
    cuentaCheques ObtenerCuentaCheques(int numero);
    void ImprimirReporte();
    void Depositar(cuentaCheques *cuenta, int cantidad);
    void Retirar(cuentaCheques *cuenta, int cantidad);
    void Transferir(cuentaCheques *cuentaOrig, cuentaCheques *cuentaDest, int cantidad);
    
public:
    int GetNumberCH();
    int GetNumberCC();
};

