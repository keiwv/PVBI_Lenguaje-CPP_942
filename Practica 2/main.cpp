#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    Fraction result("0/0");
    Fraction v1("1/0");
    Fraction v2("3/5");

    result = v1 - v2;
    result.display();


    result = v1 / v2;
    result.display();
}