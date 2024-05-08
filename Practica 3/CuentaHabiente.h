#pragma once
#include <string>
#include <vector>

class cuentaCheques;
class CuentaHabiente;

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
    cuentaCheques* EncontrarCuentaCheques(int numero);
public:
    string GetName() const { return name; };
    string GetCURP() const { return CURP; };
    int GetNumber() const { return numero; };
};