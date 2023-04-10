#include "PhanSo.h"

int GCD(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
{
    simplify();
}
int Fraction::getDenominator() const { return denominator; }

int Fraction::getNumerator() const { return numerator; }

void Fraction::setDenominator(int denominator)
{
    this->denominator = denominator;
    simplify();
}

void Fraction::setNumerator(int numerator)
{
    this->numerator = numerator;
    simplify();
}

void Fraction::simplify()
{
    int gcd = GCD(abs(numerator), abs(denominator));
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
}

istream &operator>>(istream &is, Fraction &f)
{
    cout << "Nhap tu so: ";
    is >> f.numerator;
    cout << "Nhap mau so: ";
    is >> f.denominator;

    while (f.denominator == 0) {
        cout << "Mau so khong duoc bang 0. Vui long nhap lai.\n";
        cout << "Nhap mau so: ";
        is >> f.denominator;
    }

    f.simplify();
    return is;
}


ostream &operator<<(ostream &os, const Fraction &f)
{
    if (f.denominator == 0)
        os << "NaN";
    else if (f.denominator == 1)
        os << f.numerator;
    else
        os << f.numerator << "/" << f.denominator;
    return os;
}

Fraction& Fraction::operator=(const Fraction& f)
{
    this->numerator = f.numerator;
    this->denominator = f.denominator;
    this->simplify();
    return *this;
}

Fraction Fraction::operator=(const int i)
{
    return Fraction(i);
}

Fraction Fraction::operator+(const Fraction &other) const
{
    int newNumerator = numerator * other.denominator + other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction &other) const
{
    int newNumerator = numerator * other.denominator - other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(const Fraction &other) const
{
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator/(const Fraction &other) const
{
    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    return Fraction(newNumerator, newDenominator);
}

bool Fraction::operator>(const Fraction &other) const
{
    return (numerator * other.denominator > denominator * other.numerator);
}

bool Fraction::operator<(const Fraction &other) const
{
    return (numerator * other.denominator < denominator * other.numerator);
}

Fraction Fraction::operator+(const int &other) const
{
    int newNumerator = numerator + other * denominator;
    return Fraction(newNumerator, denominator);
}

Fraction Fraction::operator-(const int &other) const
{
    int newNumerator = numerator - other * denominator;
    return Fraction(newNumerator, denominator);
}

Fraction Fraction::operator*(const int &other) const
{
    int newNumerator = numerator * other;
    return Fraction(newNumerator, denominator);
}

Fraction Fraction::operator/(const int &other) const
{
    int newDenominator = denominator * other;
    return Fraction(numerator, newDenominator);
}

bool Fraction::operator>(const int &other) const
{
    return (numerator > denominator * other);
}

bool Fraction::operator<(const int &other) const
{
    return (numerator < denominator * other);
}

// void Fraction::display() const
// {
//     if (denominator == 0)
//         cout << "NaN";
//     else if (denominator == 1)
//         cout << numerator;
//     else
//         cout << numerator << "/" << denominator;
// }