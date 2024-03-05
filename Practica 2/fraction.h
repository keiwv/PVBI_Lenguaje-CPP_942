#pragma once

#include <string>
#include <iostream>

using namespace std;

class Fraction
{
protected:
    int den;
    int num;

public:
    Fraction(const char *fraction_);
    Fraction operator+(Fraction frac);
    Fraction operator-(Fraction frac);
    Fraction operator/(Fraction frac);
    Fraction operator*(Fraction frac);
    Fraction operator+(int num);

    void display();
};
string remove_space(const string &str);

Fraction::Fraction(const char *fraction_)
{
    string result;
    result = remove_space(fraction_);
    sscanf(result.c_str(), "%d/%d", &this->num, &this->den);
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

void Fraction::display()
{
    cout << this->num;
    cout << "\\";
    cout << this->den << endl;
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
