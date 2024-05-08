#include "CuentaDeCheques.h"
#include "CuentaHabiente.h"
#include <chrono>
#include <ctime>
#include <iomanip>


string obtenerFechaActual() {
    time_t now;
    time(&now);
    tm timeinfo;
    char fechaActual[80];
    if (localtime_s(&timeinfo, &now) == 0) {
        strftime(fechaActual, sizeof(fechaActual), "%d/%m/%Y", &timeinfo);
        return string(fechaActual);
    }
    else {
        return "Error al obtener la fecha actual";
    }
}

cuentaCheques::cuentaCheques(int numero, float saldo, CuentaHabiente* propietario)
{
    this->numero = numero;
    this->saldo = saldo;
    this->propietario = propietario;
    this->fecha_um = obtenerFechaActual();
}

void cuentaCheques::Depositar(float amount)
{
    this->saldo += amount;
    this->fecha_um = obtenerFechaActual();
    
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
        this->fecha_um = obtenerFechaActual();
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


