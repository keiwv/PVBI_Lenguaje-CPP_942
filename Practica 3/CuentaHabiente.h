#pragma once
#include <string>
#include <vector>
#include "CuentaDeCheques.h"

using namespace std;

class CuentaHabiente
{
private:
    int numero;
    string name;
    string CURP;
    vector<cuentaCheques> accounts;

public:
    CuentaHabiente(int numero = 0, string name = "Prueba", string CURP = "Prueba");
    CuentaHabiente ObtenerCuenta();
    void ImprimirReporte();
    void aniadirCuentaCheques(cuentaCheques cuenta);
public:
    string GetName() const { return name; };
    string GetCURP() const {return CURP;};
};