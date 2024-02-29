#include <iostream>
#include <vector>
#include "persona.h"
#include <time.h>

using namespace std;

int main()
{
    accountPaycheck *account1 = new accountPaycheck("Juan", 20, "123456789", 1000, "Wed Feb 27 16:12:16 2024");
    accountPaycheck *account2 = new accountPaycheck("Pedro", 25, "987654321", 2000, "Wed Feb 28 16:15:16 2024");
    vector<accountPaycheck *> accounts;
    accounts.push_back(account1);
    accounts.push_back(account2);

    account1->depositBalance(1000); //Deposit 1000 to Juan's account.
    account1->showBalance();        //Show Juan's account balance.
    account1->withdrawBalance(500); //Withdraw 500 from Juan's account.
    account1->showBalance();        //Show Juan's account balance.
    account1->sendMoney(*account2, 500); //Send 500 from Juan's account to Pedro's account.
    cout << "Saldo final de Juan: " << endl;
    account1->showBalance();              //Show Juan's account balance.



    //Display accounts info in a vector
    for (vector<accountPaycheck *>::size_type i = 0; i < accounts.size(); i++)
    {
        accounts[i]->displayAccountInfo();
    }

    delete account1;
    delete account2;

    return 0;
}