#include "MyRational.h"
ostream &operator<<(ostream &outStream, const myRational &r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den;
    return outStream;
}
istream &operator>>(istream &inStream, myRational &r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}
long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n - m);
    else
        return gcd(m - n, n);
}
void myRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
}
// void myRational::reduce(myRational &s)
// {
//     if (s._num == 0 || s._den == 0)
//     {
//         s._num = 0;
//         s._den = 1;
//         return;
//     }
//     if (s._den < 0)
//     {
//         s._den *= -1;
//         s._num *= -1;
//     }
//     if (s._num == 1)
//         return;
//     int sgn = (s._num < 0 ? -1 : 1);
//     long g = gcd(sgn * s._num, s._den);
//     s._num /= g;
//     s._den /= g;
// }
myRational::myRational()
{
    _num = 0;
    _den = 1;
}
myRational::myRational(int n)
{
    _num = (long)n;
    _den = 1;
}
myRational::myRational(int n, int d)
{
    _num = (long)n;
    _den = (long)d;
    reduce();
}
myRational::myRational(const myRational &rat)
{
    _num = rat._num;
    _den = rat._den;
    reduce();
}
long myRational::getNumerator() const
{
    return _num;
}
long myRational::getDenominator() const
{
    return _den;
}
myRational myRational::reciprocal() const
{
    return myRational(_den, _num); 
}
myRational myRational::operator+(const myRational& op2) const
{
    myRational tmp(_num * op2._den + op2._num * _den, _den * op2._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator+(int value) const
{
    myRational tmp(_num + (long)value * _den, _den);
    tmp.reduce();
    return tmp;
}
const myRational operator+(int value, const myRational& op2)
{
    myRational tmp((long)value * op2._den + op2._num, op2._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator-(const myRational& op2) const
{
    //long tmp_gcd = gcd(_den, op2.getDenominator());
    myRational tmp(_num * op2._den - op2._num * _den, _den * op2._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator-(int value) const
{
    myRational tmp(_num - (long)value * _den, _den);
    tmp.reduce();
    return tmp;
}
const myRational operator-(int value, const myRational& op2)
{
    
    myRational tmp((long)value * op2._den - op2._num, op2._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator*(const myRational& op2) const
{
    myRational tmp(_num * op2._num, _den * op2._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator*(int value) const
{
    myRational tmp(_num * (long)value, _den);
    tmp.reduce();
    return tmp;
}
const myRational operator*(int value, const myRational& op2)
{
    myRational tmp(value * op2._num, op2._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator/(const myRational& op2) const
{
    myRational tmp;
    tmp = *this * op2.reciprocal();
    tmp.reduce();
    return tmp;
}
myRational myRational::operator/(int value) const
{
    myRational tmp(_num, _den * (long)value);
    tmp.reduce();
    return tmp;
}
const myRational operator/(int value, const myRational& op2)
{
    myRational tmp(value * op2._den, op2._num);
    tmp.reduce();
    return tmp;
}
myRational& myRational::operator++()
{
    *this = 1 + *this;
    return *this;
}
myRational myRational::operator++(int value)
{
    myRational tmp(_num, _den);
    *this = *this + 1;
    return tmp;
}
myRational& myRational::operator--()
{
    *this = *this - 1;
    return *this;
}
myRational myRational::operator--(int value)
{
    myRational tmp(_num, _den);
    *this = *this - 1;
    return tmp;
}
myRational myRational::operator-()
{
    return *this * (-1);
}
bool myRational::operator<(const myRational& op2) const
{
    myRational tmp1, tmp2;
    tmp1._num = _num * op2._den;
    tmp2._num = op2._num * _den;
    if (tmp1.getNumerator() < tmp2.getNumerator())
        return 1;
    return 0;
}
bool myRational::operator<(int value) const
{
    myRational tmp;
    tmp._num = (long)value * _den, _den;
    if(_num < tmp.getNumerator())
        return 1;
    return 0;
}
bool myRational::operator<=(const myRational& op2) const
{
    myRational tmp1, tmp2;
    tmp1._num = _num * op2._den;
    tmp2._num = op2._num * _den;
    if (tmp1.getNumerator() <= tmp2.getNumerator())
        return 1;
    return 0;
}
bool myRational::operator<=(int value) const
{
    myRational tmp;
    tmp._num = (long)value * _den, _den;
    if(_num <= tmp.getNumerator())
        return 1;
    return 0;
}
bool myRational::operator>(const myRational& op2) const
{
    return !(*this <= op2);
}
bool myRational::operator>(int value) const
{
    return !(*this <= value);
}
bool myRational::operator>=(const myRational& op2) const
{
    return !(*this < op2);
}
bool myRational::operator>=(int value) const
{
    return !(*this < value);
}
bool myRational::operator==(const myRational& op2) const
{
    return !(*this > op2 || *this < op2);
}
bool myRational::operator==(int value) const
{
    return !(*this > value || *this < value);
}
bool myRational::operator!=(const myRational& op2) const
{
    return (*this > op2 || *this < op2);
}
bool myRational::operator!=(int value) const
{
    return (*this > value || *this < value);
}
myRational myRational::operator=(const myRational& op2)
{
    _num = op2._num;
    _den = op2._den;
    return *this;
}
myRational myRational::operator=(int value)
{
    _num = (long)value;
    _den = 1;
    return *this;
}
myRational& myRational::operator+=(const myRational& op2)
{
    *this = *this + op2;
    return *this;
}
myRational& myRational::operator+=(int value)
{
    *this = *this + value;
    return *this;
}
myRational& myRational::operator-=(const myRational& op2)
{
    *this = *this - op2;
    return *this;
}
myRational& myRational::operator-=(int value)
{
    *this = *this - value;
    return *this;
}
myRational& myRational::operator*=(const myRational& op2)
{
    *this = *this * op2;
    return *this;
}
myRational& myRational::operator*=(int value)
{
    *this = *this * value;
    return *this;
}
myRational& myRational::operator/=(const myRational& op2)
{
    *this = *this / op2;
    return *this;
}
myRational& myRational::operator/=(int value)
{
    *this = *this / value;
    return *this;
}