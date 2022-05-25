#ifndef MYRATIONAL_H
#define MYRATIONAL_H

#include <iostream>
using namespace std;

class myRational
{
    long _num;
    long _den;

    long gcd(long m, long n);
    void reduce();
    //void reduce(myRational &s);
    friend ostream &operator<<(ostream &outStream, const myRational &r);
    friend istream &operator>>(istream &inStream, myRational &r);
public:
    myRational();
    myRational(int n);
    myRational(int n, int d);
    myRational(const myRational &rat);
    long getNumerator() const;
    long getDenominator() const;
    myRational reciprocal() const;
    myRational operator+(const myRational &op2) const;
    myRational operator+(int value) const;
    friend const myRational operator+(int value, const myRational &op2);
    myRational operator-(const myRational &op2) const;
    myRational operator-(int value) const;
    friend const myRational operator-(int value, const myRational &op2);
    myRational operator*(const myRational &op2) const;
    myRational operator*(int value) const;
    friend const myRational operator*(int value, const myRational &op2);
    myRational operator/(const myRational &op2) const;
    myRational operator/(int value) const;
    friend const myRational operator/(int value, const myRational &op2);
    myRational &operator++();
    myRational operator++(int value);
    myRational &operator--();
    myRational operator--(int value);
    myRational operator-();
    bool operator<(const myRational &op2) const;
    bool operator<(int value) const;
    bool operator<=(const myRational &op2) const;
    bool operator<=(int value) const;
    bool operator>(const myRational &op2) const;
    bool operator>(int value) const;
    bool operator>=(const myRational &op2) const;
    bool operator>=(int value) const;
    bool operator==(const myRational &op2) const;
    bool operator==(int value) const;
    bool operator!=(const myRational &op2) const;
    bool operator!=(int value) const;
    myRational operator=(const myRational &op2);
    myRational operator=(int value);
    myRational &operator+=(const myRational &op2);
    myRational &operator+=(int value);
    myRational &operator-=(const myRational &op2);
    myRational &operator-=(int value);
    myRational &operator*=(const myRational &op2);
    myRational &operator*=(int value);
    myRational &operator/=(const myRational &op2);
    myRational &operator/=(int value);
};

#endif