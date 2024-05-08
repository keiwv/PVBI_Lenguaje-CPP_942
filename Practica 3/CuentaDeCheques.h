#pragma once
#include <string>
#include <iostream>

class cuentaCheques;
class CuentaHabiente;

using namespace std;

class cuentaCheques
{
protected:
    int numero;
    float saldo;
    string fecha_um;
    CuentaHabiente* propietario;
public:
    cuentaCheques(int numero, float saldo, CuentaHabiente* propietario);
    void Depositar(float amount);
    void Retirar(int amount);
    void Transferir(int amount);
    void Imprimir();
public:
    int GetNumber() const { return this->numero; };
    float GetSaldo() const { return this->saldo; };
    string GetFechaUM() const { return this->fecha_um; };
};

