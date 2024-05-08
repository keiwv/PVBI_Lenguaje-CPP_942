#include "CuentaHabiente.h"
#include "CuentaDeCheques.h"

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
    for (auto& cuenta : this->accounts)
    {
        cout << "----------------------------------------------" << endl;
        cout << "Número de Cuenta de Cheques: " << cuenta.GetNumber() << endl;
        cout << "Saldo: " <<  cuenta.GetSaldo() << endl;
        cout << "Fecha de ultima modificacion: " << cuenta.GetFechaUM() << endl;
        cout << "Propietario: " << this->name << endl;
    }
    cout << "----------------------------------------------" << endl;
}

void CuentaHabiente::aniadirCuentaCheques(cuentaCheques cuenta)
{
    this->accounts.push_back(cuenta);
}

cuentaCheques* CuentaHabiente::EncontrarCuentaCheques(int numero)
{
    for (auto& cuenta : this->accounts)
    {
        if (cuenta.GetNumber() == numero)
        {
            return &cuenta;
        }
    }
    return nullptr;
}
