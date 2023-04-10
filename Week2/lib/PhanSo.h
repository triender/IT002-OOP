#include <iostream>

using namespace std;

int GCD(int a, int b);
class Fraction
{
private:
    int denominator, numerator;

public:
    Fraction(int numerator = 0, int denominator = 1);

    int getDenominator() const;
    int getNumerator() const;
    void setDenominator(int denominator);
    void setNumerator(int numerator);
    void simplify();

    friend istream& operator>>(istream&, Fraction&);
    friend ostream& operator<<(ostream&, const Fraction&);

    Fraction& operator=(const Fraction&);
    Fraction operator=(const int);

    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;

    Fraction operator+(const int &other) const;
    Fraction operator-(const int &other) const;
    Fraction operator*(const int &other) const;
    Fraction operator/(const int &other) const;

    bool operator>(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    
    bool operator>(const int &other) const;
    bool operator<(const int &other) const;

    // void display() const;
};