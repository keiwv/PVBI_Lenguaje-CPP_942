#include <iostream>
#include <vector>
#include "persona.h"

using namespace std;

int main()
{
    accountPaycheck *account1 = new accountPaycheck("Juan", 20, "123456789", 1000, "01/01/2021");
    accountPaycheck *account2 = new accountPaycheck("Pedro", 25, "987654321", 2000, "01/01/2021");

    vector<accountPaycheck *> accounts;
    
    accounts.push_back(account1);
    accounts.push_back(account2);


    for (std::vector<accountPaycheck *>::size_type i = 0; i < accounts.size(); i++)
    {
        accounts[i]->displayAccountInfo();
    }

    delete account1;
    delete account2;

    return 0;
}