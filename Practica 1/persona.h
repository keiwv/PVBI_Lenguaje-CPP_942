#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using std::copy;
using std::cout;
using std::endl;

class Persona
{
protected:
    int edad;
    char *nombre;
};

class accountPaycheck : public Persona
{
private:
    char *numAccount;

protected:
    int balance;
    char *dateLastTransaction;
    void updateDateLastTransaction();
public:
    void depositBalance(int _balance);
    void showBalance();
    void withdrawBalance(int _balance);
    void showDateLastTransaction();
    void sendMoney(accountPaycheck &destiny, int _balance);
    void displayAccountInfo();
    accountPaycheck(const char *_name, int _age, const char *_numAccount, int _balance, const char *dateLastTransaction);
    ~accountPaycheck();
};

accountPaycheck::accountPaycheck(const char *_name, int _age, const char *_numAccount, int _balance, const char *_dateLastTransaction)
{
    nombre = new char[strlen(_name) + 1];
    strcpy(nombre, _name);

    edad = _age;

    numAccount = new char[strlen(_numAccount) + 1];
    strcpy(numAccount, _numAccount);

    balance = _balance;

    dateLastTransaction = new char[strlen(_dateLastTransaction) + 1];
    strcpy(dateLastTransaction, _dateLastTransaction);

}

accountPaycheck::~accountPaycheck()
{
    delete[] nombre;
    delete[] numAccount;
    delete[] dateLastTransaction;
}

void accountPaycheck::updateDateLastTransaction()
{
    time_t currentTime = time(0);
    char *date =  ctime(&currentTime);
    dateLastTransaction = new char[strlen(date) + 1];
    strcpy(dateLastTransaction, date);
}

void accountPaycheck::depositBalance(int _balance)
{
    balance += _balance;
}

void accountPaycheck::showBalance()
{
    cout << "El saldo de la cuenta es: " << balance << endl;
}

void accountPaycheck::withdrawBalance(int _balance)
{
    if (balance >= _balance)
    {
        balance -= _balance;
    }
    else
    {
        cout << "No tienes suficiente saldo" << endl;
    }
}

void accountPaycheck::showDateLastTransaction()
{
    if (dateLastTransaction != NULL)
    {
        cout << "La fecha de la ultima transaccion es: " << dateLastTransaction << endl;
    }
    else
    {
        cout << "No hay fecha de ultima transaccion" << endl;
    }
}

void accountPaycheck::displayAccountInfo()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Numero de cuenta: " << numAccount << endl;
    cout << "Saldo: " << balance << endl;
    cout << "Fecha de ultima transaccion: " << dateLastTransaction << endl;
}

void  accountPaycheck::sendMoney(accountPaycheck &destiny, int _balance)
{
    if (balance >= _balance)
    {
        balance -= _balance;
        destiny.balance += _balance;
        updateDateLastTransaction();
    }
    else
    {
        cout << "No tienes suficiente saldo" << endl;
    }
}
