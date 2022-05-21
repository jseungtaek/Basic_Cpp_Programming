#include "MyComplex.h"

myComplex::myComplex()
{
    realPart = 0;
    imaginaryPart = 0;
}

myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}

myComplex::myComplex(int real)
{
    realPart = real;
    imaginaryPart = 0;
}

myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}

int myComplex::getRealPart() const
{
    return realPart;
}

int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}

void myComplex::setRealPart(int real)
{
    realPart = real;
}

void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}

void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}

myComplex myComplex::operator+(const myComplex& number) const
{
    int newR = realPart + number.realPart;
    int newI = imaginaryPart + number.imaginaryPart;
    return myComplex(newR, newI);
}

myComplex myComplex::operator+(int value) const
{
    return (*this) + myComplex(value);
}

const myComplex operator+(int value, const myComplex& number)
{
    myComplex tmp;
    tmp.realPart = value + number.getRealPart();
    tmp.imaginaryPart = number.getImaginaryPart();
    return tmp;
}

myComplex myComplex::operator-(const myComplex& number) const
{
    int newR = realPart - number.realPart;
    int newI = imaginaryPart - number.imaginaryPart;
    return myComplex(newR, newI);
}

myComplex myComplex::operator-(int value) const
{
    return (*this) - myComplex(value);
}

const myComplex operator-(int value, const myComplex& number)
{
    myComplex tmp;
    tmp.realPart = value - number.realPart;
    tmp.imaginaryPart = -number.imaginaryPart;
    return tmp;
}

myComplex myComplex::operator*(const myComplex& number) const
{
    int newR = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newI = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    return myComplex(newR, newI);
}

myComplex myComplex::operator*(int value) const
{
    int newR = realPart * value;
    int newI = imaginaryPart * value;
    return myComplex(newR, newI);
}

const myComplex operator*(int value, const myComplex& number)
{
    myComplex tmp;
    tmp.realPart = value * number.realPart;
    tmp.imaginaryPart = value * number.imaginaryPart;
    return tmp;
}

myComplex myComplex::operator=(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}

myComplex myComplex::operator=(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}

myComplex& myComplex::operator+=(const myComplex& number)
{
    // this->setRealPart(getRealPart() + number.realPart);
    // this->setImaginaryPart(getImaginaryPart() + number.imaginaryPart);
    realPart += number.realPart;
    imaginaryPart += number.imaginaryPart;
    return *this;
}

myComplex& myComplex::operator+=(int value)
{
    realPart += value;
    return *this;
}

myComplex& myComplex::operator-=(const myComplex& number)
{
    // this->realPart = this->realPart - number.realPart;
    // this->imaginaryPart = this->imaginaryPart - number.imaginaryPart;
    realPart -= number.realPart;
    imaginaryPart -= number.imaginaryPart;
    return *this;
}

myComplex& myComplex::operator-=(int value)
{
    realPart -= value;
    return *this;
}

myComplex& myComplex::operator*=(const myComplex& number)
{
    *this = *this * number;
    return *this;
}

myComplex& myComplex::operator*=(int value)
{
    *this = *this * value;
    return *this;
}

bool myComplex::operator==(const myComplex& number) const
{
    return ((realPart == number.realPart) && (imaginaryPart == number.imaginaryPart));
}

bool myComplex::operator!=(const myComplex& number) const
{
    return ((realPart != number.realPart) || (imaginaryPart != number.imaginaryPart));
}

int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}

bool myComplex::operator>(const myComplex& number) const
{
    return (norm() > number.norm());
}

bool myComplex::operator<(const myComplex& number) const
{
    return (norm() < number.norm());
}

bool myComplex::operator>=(const myComplex& number) const
{
    return (norm() >= number.norm());
}

bool myComplex::operator<=(const myComplex& number) const
{
    return (norm() <= number.norm());
}

myComplex myComplex::operator-()
{
    return myComplex(-realPart, -imaginaryPart);    
}

myComplex myComplex::operator~()
{
    return myComplex(realPart, -imaginaryPart);
}

myComplex& myComplex::operator++()
{
    realPart++;
    return *this;
}

myComplex myComplex::operator++(int value)
{
    myComplex tmp = *this;
    realPart++;
    return tmp;
}

myComplex& myComplex::operator--()
{
    realPart--;
    return *this;
}

myComplex myComplex::operator--(int value)
{
    myComplex tmp = *this;
    realPart--;
    return tmp;
}

ostream &operator<<(ostream &os, const myComplex& number)
{
    os << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return os;
}

istream &operator>>(istream &is, const myComplex& number)
{
    is >> number.realPart >> number.imaginaryPart;
    return is;
}