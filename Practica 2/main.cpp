#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    Fraction result("0/0");
    Fraction v1(3, 4);
    Fraction v2("2/4");

    result = v1 + v2;
    cout << v1 << " + " << v2 << " = " << result << endl;
    v1 = "1/2";

    result = v1 * v2;
    cout << v1 << " * " << v2 << " = " << result << endl;

    result = v1 * 5;
    cout << v1 << " * " << "5" << " = " << result << endl;
}