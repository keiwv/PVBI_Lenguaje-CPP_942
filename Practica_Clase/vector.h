#pragma once
#include <sstream> // streams basados en cadena
#include <cmath>
using std::string;


class Vector
{
public:
    double x;
    double y;
    double z;
    Vector(double x = 0, double y = 0, double z = 0);
    string ToString();

public:
    Vector Sumar(Vector v2);
    Vector Multiplicar(Vector v2);
    Vector Multiplicar(double s);
    Vector operator*(Vector v2);
    Vector operator*(double s);
    double GetMagnitud();
    Vector GetUnitVector();
};


Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector Vector::Sumar(Vector v2)
{
    Vector result;

    result.x = this->x + v2.x;
    result.y = this->y + v2.y;
    result.z = this->z + v2.z;

    return result;
}

string Vector::ToString()
{
    /*char cad[128];
    sprintf(cad, "(%.2lf),(%.2lf),(%.2lf)", x, y, z);*/
    std::ostringstream out;
    out << "(" << x
        << "," << y << ","
        << z << ")";
    return out.str();
}

Vector Vector::Multiplicar(Vector v2)
{
    Vector r;
    r.x = this->y * v2.z - this->z * v2.y;
    r.y = this->z * v2.x - this->x * v2.z;
    r.z = this->x * v2.y - this->y * v2.x;
    return r;
}

Vector Vector::Multiplicar(double s)
{
    Vector r;
    r.x = this->x * s;
    r.y = this->y * s;
    r.z = this->z * s;
    return r;
}

Vector Vector::operator*(Vector v2)
{

    Vector r;
    r.x = this->y * v2.z - this->z * v2.y;
    r.y = this->z * v2.x - this->x * v2.z;
    r.z = this->x * v2.y - this->y * v2.x;
    return r;
}

Vector Vector::operator*(double s)
{
    Vector r;
    r.x = this->x * s;
    r.y = this->y * s;
    r.z = this->z * s;
    return r;
}

Vector operator*(double s, Vector v)
{
    return v * s;
}

double Vector::GetMagnitud()
{
    return sqrt(x*x+y*y+z*z);
}

Vector Vector::GetUnitVector()
{
    double m = GetMagnitud();
    Vector r;
    r.x = x/m;
    r.y = y/m;
    r.z = z/m;
    return r;
}