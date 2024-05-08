#pragma once

#include <string>
#include <map>
#include "CuentaHabiente.h"
#include "CuentaDeCheques.h"
#include <ctime>
#include <cstdlib>

using namespace std;

class Banco
{
protected:
    string nombre;
    int ch_count;
    int cuenta_count;
    map<int, CuentaHabiente> accounts;

public:
    Banco(string nombre);
    int crearCuentaHabiente(string nombre, string CURP);
    int crearCuentaCheques(float saldo, CuentaHabiente* propietario);
    CuentaHabiente* ObtenerCuentaHabiente(int numero);
    cuentaCheques* ObtenerCuentaCheque(int numero);
    void ImprimirReporte();
    void Depositar(cuentaCheques *cuenta, float cantidad);
    void Retirar(cuentaCheques *cuenta, int cantidad);
    void Transferir(cuentaCheques *cuentaOrig, cuentaCheques *cuentaDest, int cantidad);


public:
    int GetNumberCH();
    int GetNumberCC();
};

