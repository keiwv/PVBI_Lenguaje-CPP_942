#include "CuentaHabiente.h"
/*
    CuentaHabiente(int numero, string name, string CURP);
    CuentaHabiente ObtenerCuenta();
    void ImprimirReporte();
*/

CuentaHabiente::CuentaHabiente(int numero, string name, string CURP)
{
    this->numero = numero;
    this->name = name;
    this->CURP = CURP;
}

CuentaHabiente CuentaHabiente::ObtenerCuenta()
{
    CuentaHabiente temp;
    temp.accounts = this->accounts;
    temp.CURP = this->CURP;
    temp.name = this->name;
    temp.numero = this->numero;
    return temp;
}

void CuentaHabiente::ImprimirReporte()
{
    cout << "TO BE ADDED " << endl;
}

 void CuentaHabiente::aniadirCuentaCheques(cuentaCheques cuenta)
 {
    this->accounts.push_back(cuenta);
 }
