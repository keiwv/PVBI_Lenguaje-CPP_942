#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    Fraction result("0/0");
    Fraction v1("3/4");
    Fraction v2("1/3");

    result = v1 - v2;

    printf("\n");
    result.display();

}