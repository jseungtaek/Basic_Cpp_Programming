#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include<iostream>
using namespace std;

class myComplex {
    int realPart;
    int imaginaryPart;
    int norm() const;
    friend ostream &operator<<(ostream &os, const myComplex& number);
    friend istream &operator>>(istream &is, const myComplex& number);
public:
    myComplex();
    myComplex(int real);
    myComplex(int real, int imag);
    myComplex(const myComplex& number);
    int getRealPart() const;
    int getImaginaryPart() const;
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);
    myComplex operator+(const myComplex& number) const;
    myComplex operator+(int value) const;
    friend const myComplex operator+(int value, const myComplex& number);
    myComplex operator-(const myComplex& number) const;
    myComplex operator-(int value) const;
    friend const myComplex operator-(int value, const myComplex& number);
    myComplex operator*(const myComplex& number) const;
    myComplex operator*(int value) const;
    friend const myComplex operator*(int value, const myComplex& number);
    myComplex operator=(const myComplex& number);
    myComplex operator=(int value);
    myComplex& operator+=(const myComplex& number);
    myComplex& operator+=(int value);
    myComplex& operator-=(const myComplex& number);
    myComplex& operator-=(int value);
    myComplex& operator*=(const myComplex& number);
    myComplex& operator*=(int value);
    bool operator==(const myComplex& number) const;
    bool operator!=(const myComplex& number) const;
    bool operator>(const myComplex& number) const;
    bool operator<(const myComplex& number) const;
    bool operator>=(const myComplex& number) const;
    bool operator<=(const myComplex& number) const;
    myComplex operator-();
    myComplex operator~();
    myComplex& operator++();
    myComplex operator++(int value);
    myComplex& operator--();
    myComplex operator--(int value);
};

void testSimpleCase();
void testDataFromFile();
#endif