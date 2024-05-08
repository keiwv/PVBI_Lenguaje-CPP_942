#include <iostream>
#include "Banco.h"
#include "menu.h"

using namespace std;

void crearCuentaHabiente();
void crearCuentaCheques();
void ImprimirReporte();
void ObtenerCuentaHabiente();
void Depositar();
void Retirar();
void Transferir();

Banco Azteca = Banco("Azteca");

int main()
{
    Menu menu("Menu");
   
    menu.Agregar({ '1',"Crear una cuenta habiente",crearCuentaHabiente });
    menu.Agregar({ '2',"Crear cuenta de cheques",crearCuentaCheques });
    menu.Agregar({ '3',"Imprimir reporte",ImprimirReporte });
    menu.Agregar({ '4',"Obtener cuenta habiente",ObtenerCuentaHabiente });
    menu.Agregar({ '5',"Depositar dinero a cuenta cheque",Depositar });
    menu.Agregar({ '6',"Retirar dinero a cuenta cheque",Retirar });
    menu.Agregar({ '7',"Transferir a una cuenta cheque",Transferir });

    menu.Agregar({ '8', "Salir", []() {cout << "Adios" << endl; } });

    do
    {
        system("CLS");
        menu.Desplegar();
    } while (menu.Seleccionar() != 8);

    return 0;
}

void crearCuentaHabiente()
{
    string nombre;
    string CURP;
    int numeroCuenta;

    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;

    cout << "Ingrese el CURP de la persona: ";
    cin >> CURP;

    numeroCuenta = Azteca.crearCuentaHabiente(nombre, CURP);
    cout << "Cuenta creada exitosamente\n El numero de cuenta es: " << numeroCuenta << endl;
    system("PAUSE");

}

void crearCuentaCheques()
{
    int numeroCuenta;
    float saldoInicial;
    CuentaHabiente* cuenta;

    cout << "Ingresa el numero de cuenta de la persona: ";
    cin >> numeroCuenta;

    cuenta = Azteca.ObtenerCuentaHabiente(numeroCuenta);

    if (cuenta != nullptr)
    {
        cout << "Ingresa el saldo inicial de la persona: ";
        cin >> saldoInicial;
        numeroCuenta = Azteca.crearCuentaCheques(saldoInicial, cuenta);
        cout << "Cuenta de cheque creada correctamente.\nTu numero de cuenta es: " << numeroCuenta <<endl;
    }
    else
    {
        cout << "La cuenta ingresada no existe.";
    }
    system("PAUSE");
    
}

void ImprimirReporte()
{
    try
    {
        Azteca.ImprimirReporte();
    }
    catch (int error)
    {
        cout << "No hay cuentas en el sistema actualmente..." <<  endl;
    }
    system("PAUSE");
}

void ObtenerCuentaHabiente()
{
    int numeroCuenta;
    CuentaHabiente* cuenta;

    cout << "Ingresa el numero de cuenta de la persona: ";
    cin >> numeroCuenta;

    cuenta = Azteca.ObtenerCuentaHabiente(numeroCuenta);

    if (cuenta != nullptr)
    {
        cout << "----------------------------------------------" << endl;
        cout << "Nombre: " << cuenta->GetName() << endl;
        cout << "Numero de cuenta: " << cuenta->GetNumber() << endl;
        cuenta->ImprimirReporte();
    }
    else
    {
        cout << "La cuenta ingresada no existe." << endl;
    }
    system("PAUSE");
}

void Depositar()
{
    int numeroCuenta;
    float saldoDepositar;
    cuentaCheques* cuenta;

    cout << "Ingresa el numero de cheque que desea depositar: ";
    cin >> numeroCuenta;

    cuenta = Azteca.ObtenerCuentaCheque(numeroCuenta);

    if (cuenta != nullptr)
    {
        cout << "Ingresa la cantidad a depositar: ";
        cin >> saldoDepositar;
        Azteca.Depositar(cuenta, saldoDepositar);
        cout << "Dinero depositado correctamente" << endl;
    }
    else
    {
        cout << "La cuenta ingresada no existe.";
    }
    system("PAUSE");
}

void Retirar()
{
    int numeroCuenta;
    float saldoRetirar;
    cuentaCheques* cuenta;

    cout << "Ingresa el numero de cheque que desea retirar: ";
    cin >> numeroCuenta;

    cuenta = Azteca.ObtenerCuentaCheque(numeroCuenta);

    if (cuenta != nullptr)
    {
        cout << "Ingresa la cantidad a depositar: ";
        cin >> saldoRetirar;
        try
        {
            Azteca.Retirar(cuenta, (float)saldoRetirar);
            cout << "Dinero retirado correctamente" << endl;
        }
        catch (int error)
        {
            cout << "No hay suciente dinero en la cuenta..." << endl;
        }

    }
    else
    {
        cout << "La cuenta ingresada no existe.";
    }
    system("PAUSE");
}

void Transferir()
{
    int numeroCuenta;
    float saldoTransferir;
    cuentaCheques* cuentaOrigen;
    cuentaCheques* cuentaDestino;

    cout << "Ingresa tu numero de cuenta de cheque: ";
    cin >> numeroCuenta;

    cuentaOrigen = Azteca.ObtenerCuentaCheque(numeroCuenta);

    if (cuentaOrigen != nullptr)
    {
        cout << "Ingresa la cuenta a la cual desea transferir: ";
        cin >> numeroCuenta;
        cuentaDestino = Azteca.ObtenerCuentaCheque(numeroCuenta);

        if (cuentaDestino != nullptr)
        {
            cout << "Ingrese por favor la cantidad a transferir: ";
            cin >> saldoTransferir;

            try
            {
                Azteca.Transferir(cuentaOrigen, cuentaDestino, saldoTransferir);
                cout << "La transferencia se realizó correctamente..." << endl;
            }
            catch (int error)
            {
                cout << "No hay suciente dinero en la cuenta de origen..." << endl;
                cout << "No se realizo la transferencia" << endl;
            }
        
        }

    }
    else
    {
        cout << "La cuenta ingresada no existe.";
    }
    system("PAUSE");

}
