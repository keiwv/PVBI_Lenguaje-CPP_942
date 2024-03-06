#include <iostream>

using namespace std;
template<class T> 

/*
void Swap(float &a, float &b)
{
    float t;
    t = a;
    a = b;
    b = t;
}*/


void Swap(T& a, T& b)
{
    float t;
    t = a;
    a = b;
    b = t;
}



int main()
{
    int x = 10;
    int y = 666;
    cout << "X " << x << "  y: " << y << endl;
    Swap(x, y);
    cout << "X " << x << "  y: " << y << endl;

    float o = 10.0f;
    float p = 3.141569;

    cout << "o: " << o << "    p: " << p << endl;

    Swap(o, p);

    cout << "o: " << o << "    p: " << p << endl;
    
}