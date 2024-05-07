#include "CuentaDeCheques.h"

/*
        int numero;
    float saldo;
    string fecha_um;
    CuentaHabiente *propietario;
*/

cuentaCheques::cuentaCheques(int numero, float saldo, CuentaHabiente *propietario)
{
    this->numero = numero;
    this->saldo = saldo;
    this->propietario = propietario;
}

void cuentaCheques::Depositar(int amount)
{
    this->saldo += amount;
}

void cuentaCheques::Retirar(int amount)
{
    if (this->saldo < amount)
    {
        throw 10;
    }
    else
    {
        this->saldo -= amount;
    }
}

void cuentaCheques::Transferir(int amount)
{
    try
    {
        this->Retirar(amount);
    }
    catch (int error)
    {
        throw 10;
    }
}

void cuentaCheques::Imprimir()
{
    cout << "Numero de cuenta: " << this->numero << endl;
    cout << "Saldo de la cuenta: " << this->saldo << endl;
    cout << "Última fecha de modificación: " << fecha_um << endl;
    cout << "Propietario: " << propietario->GetName() << endl;
}