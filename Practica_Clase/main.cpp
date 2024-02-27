#include <iostream>
#include <string>
#include "vector.h"

using namespace std;

int main()
{
    Vector v1(10, 20, 5), v2 = {25, 11, 17};
    Vector result;

    result = v1.Multiplicar(v2);

    result = v1 * v2;
    cout << result.ToString();
    result = v1 * 2;
    cout << result.ToString();
    
}