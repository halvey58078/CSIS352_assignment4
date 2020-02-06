/*
Michael Halverson
fraction.cpp
02.06.20
CSIS 352
Assignment #4

precondition: 
postcondition: 
Description: 
*/

#include <iostream>
#include <cmath>
#include <sstream>
#include "fraction.h"

fraction::fraction()
{
    numer = 0;
    denom = 1;
}


fraction::fraction(int top, int bottom)
{
    setFraction(top,bottom);
}


fraction::fraction(double num)
{
    setFraction(num);
}


void fraction::setFraction(int top, int bottom)
{
    numer = top;
    denom = bottom; 
}


void fraction::setFraction(double frac)
{
    string tempStr;  stringstream ss;
    ss<<frac;
    ss>>tempStr;
    int cat = tempStr.length() - 1 - tempStr.find('.');
    
    int tenPower=1;
    for (int i=0; i<cat; i++)
    {
        tenPower = tenPower*10;
    }

    numer = frac*tenPower;
    denom = tenPower;
    reduce();
}


//This function finds the greatest common denominator of a fraction
int fraction::gcd(int numer,int denom)
{
    int gcd;
    numer = abs(numer);
    denom = abs(denom);
    
    if (numer == 0)
        {return denom;}
        
    else if (denom==0)
        {return numer;}

    else if (while (numer != denom))
        {
            if (numer < denom)
                {denom -= numer;}
            else
                {numer -= denom;}

            gcd = numer; 
        }           
        return gcd;
}


void fraction::setFormat(outputFormat userSelect)
{
    formatType = userSelect;
}

outputFormat fraction::formatType = mixed;

double fraction::decimalValue()
{
    return (double)numer / (double)denom;
}


void fraction::improper()
{
    cout<<numer<<"/"<<denom<<endl;
}


void fraction::mixedNum()
{
    if (numer > denom)
    {
        int whole = numer/denom;
        numer = numer - (whole*denom);
        cout<<whole<<" "<<numer<<"/"<<denom<<endl;
    }

    else 
    {cout<<numer<<"/"<<denom<<endl;}  
}


void fraction::reduce()
{
    int greatest = gcd(numer,denom);
    numer = numer/greatest;
    denom = denom/greatest;
}


int fraction::getNumerator() const
{
    return numer;
}


void fraction::setDenominator(int a)
{
    double n = numer;
    if (n/denom * a != numer/denom * a)
    {cout << "Error"<<n<<" is not a whole number"<<endl;}

    else
    {
        numer = n/denom * a;
        denom = a;
    }       
}
 

int fraction::getDenominator() const
{
    return denom;
}


fraction fraction::operator + (const fraction& fracTwo) const
{
    int sumN = numer*fracTwo.getDenominator() + denom*fracTwo.getNumerator();
    int sumD = denom*fracTwo.getDenominator();
    fraction fracSum(sumN,sumD);
    fracSum.reduce();
    return fracSum;
}


fraction fraction::operator - (const fraction& fracTwo) const
{
    int diffN = numer*fracTwo.getDenominator() - denom*fracTwo.getNumerator();
    int diffD = denom*fracTwo.getDenominator();
    fraction fracDiff(diffN,diffD);
    fracDiff.reduce();
    return fracDiff;
}


fraction fraction::operator * (const fraction& fracTwo) const
{
    int prodN = numer * fracTwo.getNumerator();
    int prodD = denom * fracTwo.getDenominator();
    fraction fracProd(prodN,prodD);
    fracProd.reduce();
    return fracProd;
}

fraction fraction::operator / (const fraction& fracTwo) const
{
    int quoN = numer * fracTwo.getDenominator();
    int quoD = denom * fracTwo.getNumerator();
    fraction fracQuo(quoN,quoD);
    fracQuo.reduce(); 
    return fracQuo;
}


// bool fraction::operator < (const fraction& fracTwo) const
// {
//     return decimalValue() < fracTwo.decimalValue();
// }


// bool fraction::operator > (const fraction& fracTwo) const
// {
//     return decimalValue() > fracTwo.decimalValue();
// }


// bool fraction::operator == (const fraction& fracTwo) const
// {
//     return decimalValue() == fracTwo.decimalValue();
// }


istream& operator >> (istream& i, fraction& fracTwo)
{
    int temp;
    char s;
    i >> temp;
    fracTwo.numer = temp;
    i >> s;
    i >> temp;
    fracTwo.denom = temp;
    
    return i;
}


ostream& operator << (ostream& o, fraction& fracTwo)
{
    switch (fracTwo.formatType)
   {
      case mixed: fracTwo.mixedNum(); break;
      case improper: fracTwo.improper(); break;
      case decimal: o << fracTwo.decimalValue(); break;
   }
   return o;
}

// template class fraction<int>;
// template class fraction<double>;
