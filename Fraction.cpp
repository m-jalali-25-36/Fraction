#include <iostream>
#include "GreatestCommonDivisor.cpp"
#include "LeastCommonMultiple.cpp"

using namespace std;

#pragma once
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    static bool autoSimplify;
    static bool getModeHelper;
    static bool printDecimal;

    Fraction()
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        if (denominator != 0)
            this->denominator = denominator;
        else
            this->denominator = 1;
    }
    ~Fraction() {}
    int Numerator()
    {
        return numerator;
    }
    void Numerator(int numerator)
    {
        this->numerator = numerator;
    }
    int Denominator()
    {
        return denominator;
    }
    void Denominator(int denominator)
    {
        if (denominator != 0)
            this->denominator = denominator;
        else
            this->denominator = 1;
    }

    Fraction Simplify(Fraction &fraction)
    {
        Fraction result;
        int gcd = GreatestCommonDivisor(fraction.numerator, fraction.denominator);
        result.numerator = fraction.numerator / gcd;
        result.denominator = fraction.denominator / gcd;
        return result;
    }
    void Simplify()
    {
        int gcd = GreatestCommonDivisor(this->numerator, this->denominator);
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    long double GetDecimal()
    {
        return (long double)((long double)this->numerator / (long double)this->denominator);
    }

    void operator=(Fraction fraction)
    {
        this->numerator = numerator;
        if (denominator != 0)
            this->denominator = denominator;
        else
            this->denominator = 1;
    }

    Fraction operator+(Fraction &fraction)
    {
        Fraction result;
        int lcm = LeastCommonMultiple(this->denominator, fraction.denominator);
        result.Numerator(this->numerator * (lcm / this->denominator) + fraction.numerator * (lcm / fraction.denominator));
        result.Denominator(lcm);
        if (autoSimplify)
            result.Simplify();
        return result;
    }
    Fraction operator+(int n)
    {
        Fraction result;
        result.Numerator((n * this->denominator) + this->numerator);
        result.Denominator(this->denominator);
        if (autoSimplify)
            result.Simplify();
        return result;
    }
    Fraction operator-(Fraction &fraction)
    {
        Fraction result;
        int lcm = LeastCommonMultiple(this->denominator, fraction.denominator);
        result.Numerator(this->numerator * (lcm / this->denominator) - fraction.numerator * (lcm / fraction.denominator));
        result.Denominator(lcm);
        if (autoSimplify)
            result.Simplify();
        return result;
    }
    Fraction operator-(int n)
    {
        Fraction result;
        result.Numerator(this->numerator - (n * this->denominator));
        result.Denominator(this->denominator);
        if (autoSimplify)
            result.Simplify();
        return result;
    }
    Fraction operator*(Fraction &fraction)
    {
        Fraction result;
        result.Numerator(this->numerator * fraction.numerator);
        result.Denominator(this->denominator * fraction.denominator);
        if (autoSimplify)
            result.Simplify();
        return result;
    }
    Fraction operator*(int n)
    {
        Fraction result;
        result.Numerator(this->numerator * n);
        result.Denominator(this->denominator);
        if (autoSimplify)
            result.Simplify();
        return result;
    }
    Fraction operator/(Fraction &fraction)
    {
        Fraction result;
        result.Numerator(this->numerator * fraction.denominator);
        result.Denominator(this->denominator * fraction.numerator);
        if (autoSimplify)
            result.Simplify();
        return result;
    }
    Fraction operator/(int n)
    {
        Fraction result;
        result.Numerator(this->numerator);
        result.Denominator(this->denominator * n);
        if (autoSimplify)
            result.Simplify();
        return result;
    }
    Fraction operator+=(Fraction &fraction)
    {
        int lcm = LeastCommonMultiple(this->denominator, fraction.denominator);
        Numerator(this->numerator * (lcm / this->denominator) + fraction.numerator * (lcm / fraction.denominator));
        Denominator(lcm);
        if (autoSimplify)
            Simplify();
        return *this;
    }
    Fraction operator+=(int n)
    {
        Numerator(this->numerator + (n * this->denominator));
        if (autoSimplify)
            Simplify();
        return *this;
    }
    Fraction operator-=(Fraction &fraction)
    {
        int lcm = LeastCommonMultiple(this->denominator, fraction.denominator);
        Numerator(this->numerator * (lcm / this->denominator) - fraction.numerator * (lcm / fraction.denominator));
        Denominator(lcm);
        if (autoSimplify)
            Simplify();
        return *this;
    }
    Fraction operator-=(int n)
    {
        Numerator(this->numerator - (n * this->denominator));
        if (autoSimplify)
            Simplify();
        return *this;
    }
    Fraction operator*=(Fraction &fraction)
    {
        Numerator(this->numerator * fraction.numerator);
        Denominator(this->denominator * fraction.denominator);
        if (autoSimplify)
            Simplify();
        return *this;
    }
    Fraction operator*=(int n)
    {
        Numerator(this->numerator * n);
        if (autoSimplify)
            Simplify();
        return *this;
    }
    Fraction operator/=(Fraction &fraction)
    {
        Numerator(this->numerator * fraction.denominator);
        Denominator(this->denominator * fraction.numerator);
        if (autoSimplify)
            Simplify();
        return *this;
    }
    Fraction operator/=(int n)
    {
        Denominator(this->denominator * n);
        if (autoSimplify)
            Simplify();
        return *this;
    }

    Fraction operator++()
    {
        this->numerator++;
        return *this;
    }
    Fraction operator++(int a)
    {
        this->numerator++;
        return *this;
    }
    Fraction operator--()
    {
        this->numerator--;
        return *this;
    }
    Fraction operator--(int a)
    {
        this->numerator--;
        return *this;
    }

    friend ostream &operator<<(ostream &output, Fraction &fraction)
    {
        if (!printDecimal)
            output << fraction.numerator << "/" << fraction.denominator;
        else
            output << fraction.GetDecimal();
        return output;
    }
    friend istream &operator>>(istream &input, Fraction &fraction)
    {
        if (getModeHelper)
            cout << "Numerator: ";
        input >> fraction.numerator;
        if (getModeHelper)
            cout << "Denominator: ";
        int d;
        input >> d;
        if (d != 0)
            fraction.denominator = d;
        else
            fraction.denominator = 1;
        return input;
    }

    bool operator==(Fraction &fraction)
    {
        Fraction f1 = Simplify(*this);
        Fraction f2 = Simplify(fraction);
        return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
    }
    bool operator!=(Fraction &fraction)
    {
        Fraction f1 = Simplify(*this);
        Fraction f2 = Simplify(fraction);
        return f1.numerator != f2.numerator || f1.denominator != f2.denominator;
    }
    bool operator>(Fraction &fraction)
    {
        return GetDecimal() > fraction.GetDecimal();
    }
    bool operator>=(Fraction &fraction)
    {
        return GetDecimal() >= fraction.GetDecimal();
    }
    bool operator<(Fraction &fraction)
    {
        return GetDecimal() < fraction.GetDecimal();
    }
    bool operator<=(Fraction &fraction)
    {
        return GetDecimal() <= fraction.GetDecimal();
    }
};

bool Fraction::getModeHelper = false;
bool Fraction::autoSimplify = false;
bool Fraction::printDecimal = false;
