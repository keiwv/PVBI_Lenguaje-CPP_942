#include "Banco.h"
/*
Banco(string nombre);
    void crearCuentaHabiente(string nombre, string CURP);
    void crearCuentaCheques(float saldo, CuentaHabiente *propietario);
    CuentaHabiente ObtenerCuentaHabiente(int numero);
    cuentaCheques ObtenerCuentaCheques(int numero);
    void ImprimirReporte();
    void Depositar(cuentaCheques *cuenta, int cantidad);
    void Retirar(cuentaCheques *cuenta, int cantidad);
    void Transferir(cuentaCheques *cuentaOrig, cuentaCheques *cuentaDest, int cantidad);

*/

Banco::Banco(string nombre)
{
    this->nombre = nombre;
    this->ch_count = 0;
    this->cuenta_count = 0;
}

void Banco::crearCuentaCheques(float saldo, CuentaHabiente *propietario)
{
    cuentaCheques account = cuentaCheques(this->GetNumberCC(), saldo, propietario);
    propietario->aniadirCuentaCheques(account);
}

int Banco::GetNumberCC()
{
    srand(time(NULL));

    return (rand() % 10000) + 10000;
}

int Banco::GetNumberCH()
{
    srand(time(NULL));

    return (rand() % 10000) + 9999999;
}
