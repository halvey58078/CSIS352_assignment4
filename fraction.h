// File:     fraction.h
// Author:   Michael Halverson
// Date:     02.06.20

// Description
// This file contains the specification for a fraction class


#ifndef _FRACTION_H_
#define _FRACTION_H_
#include <iostream>

using namespace std;
enum outputFormat {improper,decimal,mixed};

class fraction
{
public:
    fraction();
    fraction(int, int);
    fraction(double);
    void setFraction(int, int);
    void setFraction(double);
    int getNumerator() const;
    void setDenominator(int);
    int getDenominator() const;
    static void setFormat(outputFormat);
    double decimalValue();
    void improper();
    void mixedNum();
    void reduce();
    int gcd(int,int);
    fraction operator + (const fraction&) const;
    fraction operator - (const fraction&) const;
    fraction operator * (const fraction&) const;
    fraction operator / (const fraction&) const;
    bool operator < (const fraction&) const;
    bool operator > (const fraction&) const;
    bool operator == (const fraction&) const;
    friend istream& operator >> (istream&, fraction&);
    friend ostream& operator << (ostream&, fraction&);

private:
    int numer;
    int denom;
    static outputFormat formatType;    

};

#endif