#pragma once
#include <string>
#include <iostream>
#include "CuentaHabiente.h"


using namespace std;

class cuentaCheques
{
private:
    int numero;
    float saldo;
    string fecha_um;
    CuentaHabiente *propietario;
public:
    cuentaCheques(int numero, float saldo, CuentaHabiente *propietario);
    void Depositar(int amount);
    void Retirar(int amount);
    void Transferir(int amount);
    void Imprimir();
};

