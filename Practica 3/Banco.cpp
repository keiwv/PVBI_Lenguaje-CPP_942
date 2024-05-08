#include "Banco.h"
#include <ctime> 
#include <cstdlib>

Banco::Banco(string nombre)
{
    this->nombre = nombre;
    this->ch_count = 0;
    this->cuenta_count = 0;
    srand(static_cast<unsigned int>(time(NULL)));
}

int Banco::crearCuentaHabiente(string nombre, string CURP)
{
    int number = this->GetNumberCH();
    CuentaHabiente account = CuentaHabiente(number, nombre, CURP);
    this->accounts.insert({ number, account });
    ch_count++;
    return number;
}

int Banco::crearCuentaCheques(float saldo, CuentaHabiente* propietario)
{
    int number = this->GetNumberCC();
    cuentaCheques account = cuentaCheques(number, saldo, propietario);
    propietario->aniadirCuentaCheques(account);
    this->cuenta_count++;
    return number;
}

CuentaHabiente* Banco::ObtenerCuentaHabiente(int numero)
{
    auto it = accounts.find(numero);
    if (it != accounts.end())
    {
        return &it->second;
    }
    else
    {
        return nullptr;
    }
}


cuentaCheques* Banco::ObtenerCuentaCheque(int numero)
{
    for (auto& pair : this->accounts)
    {
        CuentaHabiente &temp = pair.second;
        cuentaCheques* cuenta = temp.EncontrarCuentaCheques(numero);

        if (cuenta)
        {
            return cuenta;
        }
    }

    return nullptr;
}

void Banco::ImprimirReporte()
{
    if (!this->accounts.empty())
    {
        cout << "Reporte del Banco " << this->nombre << endl;
        cout << "----------------------------------------------" << endl;
        for (auto& cuenta : this->accounts)
        {
            CuentaHabiente Cuentatemp = cuenta.second;

            cout << "Cuenta Habiente: " << Cuentatemp.GetName() << endl;
            cout << "Numero de Cuenta Habiente: " << Cuentatemp.GetNumber() << endl;

            Cuentatemp.ImprimirReporte();
            cout << endl;
            cout << endl;

        }

        cout << "Fin del Reporte" << endl;
    }
    else
    {
        throw 1;
    }
}

void Banco::Depositar(cuentaCheques* cuenta, float cantidad)
{
    cuenta->Depositar(cantidad);
}

void Banco::Retirar(cuentaCheques* cuenta, int cantidad)
{
    try
    {
        cuenta->Retirar(cantidad);
    }
    catch (int error)
    {
        throw 1;
    }
    
}

void Banco::Transferir(cuentaCheques* cuentaOrig, cuentaCheques* cuentaDest, int cantidad)
{
    try
    {
        cuentaOrig->Retirar(cantidad);
        cuentaDest->Depositar(cantidad);
    }
    catch (int error)
    {
        throw 1;
    }

}


int Banco::GetNumberCC()
{
    return (rand() % 10000) + 10000;
}

int Banco::GetNumberCH()
{
    return (rand() % 10000) + 9999999;
}
