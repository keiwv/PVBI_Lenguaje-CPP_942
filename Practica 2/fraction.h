#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction
{
public:
    int den;
    int num;

public:
    Fraction(const char *fraction_);
    Fraction(int num, int deno);
    Fraction operator+(Fraction frac);
    Fraction operator-(Fraction frac);
    Fraction operator/(Fraction frac);
    Fraction operator*(Fraction frac);
    Fraction operator+(int num);
    Fraction operator-(int num);
    Fraction operator/(int num);
    Fraction operator*(int num);

    friend ostream &operator<<(ostream &os, const Fraction &frac);
};
string remove_space(const string &str);

Fraction::Fraction(const char *fraction_)
{
    string result;
    result = remove_space(fraction_);
    sscanf(result.c_str(), "%d/%d", &this->num, &this->den);
}

Fraction::Fraction(int num, int deno)
{
    this->num = num;
    this->den = deno;
}

Fraction Fraction::operator+(Fraction frac)
{
    Fraction result("0/0");
    if (this->den == frac.den)
    {
        result.num = this->num + frac.num;
        result.den = this->den;
    }
    else
    {
        result.num = (this->num * frac.den) + (this->den * frac.num);
        result.den = this->den * frac.den;
    }
    return result;
}

Fraction Fraction::operator-(Fraction frac)
{
    Fraction result("0/0");
    if (this->den == frac.den)
    {
        result.num = this->num - frac.num;
        result.den = this->den;
    }
    else
    {
        result.num = (this->num * frac.den) - (this->den * frac.num);
        result.den = this->den * frac.den;
    }
    return result;
}

Fraction Fraction::operator/(Fraction frac)
{
    Fraction result("0/0");
    if (this->den == 0 || frac.den == 0)
    {
        cout << "Division entre 0" << endl;
        return 0;
    }
    else
    {
        if (this->num == 0 || frac.num == 0)
        {
            cout << "No se puede dividir un 0" << endl;
        }
        else
        {
            result.num = this->num * frac.den;
            result.den = this->den * frac.num;
        }
    }
    return result;
}

Fraction Fraction::operator*(Fraction frac)
{
    Fraction result("0/0");
    if (this->den == 0 || frac.den == 0)
    {
        cout << "No se puede multiplicar por 0" << endl;
    }
    else
    {
        if (this->num == 0 || frac.num == 0)
        {
            cout << "No se puede multiplicar por 0";
        }
        else
        {
            if (this->den == frac.den)
            {
                result.den = this->den;
                result.num = this->num * frac.num;
            }
            else
            {
                result.num = this->num * frac.num;
                result.den = this->den * frac.den;
            }
        }
    }
    return result;
}

Fraction Fraction::operator+(int num)
{
    Fraction result("0/0");
    if (num == 1)
    {
        num = this->den;
        result.num = num + this->num;
        result.den = num;
    }
    else
    {
        num = num * this->den;
        result.den = this->den;
        result.num = num + this->num;
    }

    return result;
}

Fraction Fraction::operator-(int num)
{
    Fraction result("0/0");
    if (num == 1)
    {
        num = this->den;
        result.num = num - this->num;
        result.den = num;
    }
    else
    {
        num = num * this->den;
        result.den = this->den;
        result.num = num - this->num;
    }

    return result;
}

Fraction Fraction::operator/(int num)
{
    Fraction result("0/0");

    if (num == 1)
    {
        result.den = this->den;
        result.num = this->num;
    }
    else
    {
        result.num = this->num;
        result.den = this->den * num;
    }
    return result;
}

Fraction Fraction::operator*(int num)
{
    Fraction result("0/0");
    result.num = num * this->num;
    result.den = this->den;
    return result;
}

Fraction operator/(int num, Fraction frac)
{
    Fraction result("0/0");
    result.num = num * frac.den;
    result.den = frac.num;
    return result;
}

Fraction operator-(int num, Fraction frac)
{
    Fraction result("0/0");
    result.num = num * frac.den - frac.num;
    result.den = frac.den;
    return result;
}

Fraction operator*(int num, Fraction frac)
{
    Fraction result("0/0");
    result.num = num * frac.num;
    result.den = frac.den;
    return result;
}

ostream &operator<<(ostream &os, const Fraction &frac)
{
    int whole_part = frac.num / frac.den;
    int remainder = frac.num % frac.den;

    if (whole_part != 0)
        os << whole_part << " ";

    if (remainder != 0)
        os << remainder << "/" << frac.den;

    if (whole_part == 0 && remainder == 0)
        os << "0";

    return os;
}

string remove_space(const string &str)
{
    string result;
    for (char c : str)
    {
        if (c != ' ')
        {
            result.push_back(c);
        }
    }
    return result;
}
