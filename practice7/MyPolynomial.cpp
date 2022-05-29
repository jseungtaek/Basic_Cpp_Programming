#include "MyPolynomial.h"
/********************* add your code here ********************************/
// output operator
ostream &operator<<(ostream &outStream, const myPolynomial &poly)
{
    if (poly == myPolynomial::ZERO)
        return outStream << 0;
    /********************* add your code here ********************************/
    if (poly == myPolynomial::ONE)
        return outStream << 1;
    for (int i = 0; i < poly.cnt_poly; i++)
    {
        if (poly._poly[i].getCoeff() < 0 || i == 0)
        {
            if (poly._poly[i].getCoeff() == -1 && poly._poly[i].getExp() != 0)
                outStream << "-";
            else if (poly._poly[i].getCoeff() != 1 || poly._poly[i].getExp() == 0)
                outStream << poly._poly[i].getCoeff();
        }
        else if (poly._poly[i].getCoeff() > 0 && i != 0)
        {
            outStream << "+";
            if (poly._poly[i].getCoeff() > 1 || (poly._poly[i].getCoeff() == 1 && poly._poly[i].getExp() == 0))
                outStream << poly._poly[i].getCoeff();
        }
        if (poly._poly[i].getCoeff() != 0 && poly._poly[i].getExp() >= 1)
            outStream << "x";
        if (poly._poly[i].getCoeff() != 0 && poly._poly[i].getExp() > 1)
            outStream << "^" << poly._poly[i].getExp();
    }
    return outStream;
}
bool compare(myTerm a, myTerm b)
{
    return a.getExp() > b.getExp();
}
myPolynomial::myPolynomial(int c, unsigned e)
{
    myTerm tmp(c, e);
    _poly.push_back(tmp);
    cnt_poly = 1;
    // if (e == 0)
    //     degree = -1;
    // else
    degree = (int)e;
}
myPolynomial::myPolynomial(int nTerms, int mono[])
{
    cnt_poly = nTerms;
    for (int i = 0; i < nTerms; i++)
    {
        myTerm tmp(mono[i * 2], (unsigned)mono[i * 2 + 1]);
        _poly.push_back(tmp);
    }
    sort(_poly.begin(), _poly.end(), compare);
    // if (nTerms == 1 && mono[0] == 0 && mono[1] == 0)
    //     degree = -1;
    // else
    degree = (int)_poly[0].getExp();
}
// copy constructor
myPolynomial::myPolynomial(const myPolynomial &poly)
{
    cnt_poly = poly.cnt_poly;
    for (int i = 0; i < poly.cnt_poly; i++)
    {
        _poly.push_back(poly._poly[i]);
    }
    sort(_poly.begin(), _poly.end(), compare);
    degree = poly.degree;
}
// overloaded operators
bool myPolynomial::operator==(const myPolynomial &poly) const
{
    for (int i = 0; i < cnt_poly; i++)
    {
        if (_poly[i] != poly._poly[i])
            return 0;
    }
    return 1;
}
bool myPolynomial::operator!=(const myPolynomial &poly) const
{
    for (int i = 0; i < cnt_poly; i++)
    {
        if (_poly[i] == poly._poly[i])
            return 0;
    }
    return 1;
}
myPolynomial& myPolynomial::operator+=(const myPolynomial &poly)
{
    *this = *this + poly;
    return *this;
}
myPolynomial& myPolynomial::operator-=(const myPolynomial &poly)
{
    *this = *this - poly;
    return *this;
}
myPolynomial& myPolynomial::operator*=(const myPolynomial &poly)
{
    *this = *this * poly;
    return *this;
}
myPolynomial& myPolynomial::operator*=(int k)
{
    *this = *this * k;
    return *this;
}
myPolynomial myPolynomial::operator-() const
{
    myPolynomial tmp(*this);
    tmp._poly.clear();
    return tmp * -1;
}
myPolynomial myPolynomial::operator+(const myPolynomial &poly) const
{
    myPolynomial tmp(*this);
    tmp._poly.clear();
    int t_term = 0, p_term = 0;
    while ((t_term < cnt_poly) && (p_term < poly.cnt_poly))
    {
        if (_poly[t_term].getExp() == poly._poly[p_term].getExp())
        {
            myTerm t(_poly[t_term].getCoeff() + poly._poly[p_term].getCoeff(), _poly[t_term].getExp());
            tmp._poly.push_back(t);
            t_term++;
            p_term++;
        }
        else if (_poly[t_term].getExp() > poly._poly[p_term].getExp())
        {
            myTerm t(_poly[t_term].getCoeff(), _poly[t_term].getExp());
            tmp._poly.push_back(t);
            t_term++;
        }
        else
        {
            myTerm p(poly._poly[p_term].getCoeff(), poly._poly[p_term].getExp());
            tmp._poly.push_back(p);
            p_term++;
        }
    }
    for (; t_term < cnt_poly; t_term++)
    {
        myTerm t(_poly[t_term].getCoeff(), _poly[t_term].getExp());
        tmp._poly.push_back(t);
    }
    for (; p_term < poly.cnt_poly; p_term++)
    {
        myTerm p(poly._poly[p_term].getCoeff(), poly._poly[p_term].getExp());
        tmp._poly.push_back(p);
    }
    sort(tmp._poly.begin(), tmp._poly.end(), compare);
    tmp.degree = tmp._poly[0].getExp();
    tmp.cnt_poly = t_term > p_term ? t_term : p_term;
    return tmp;
}
myPolynomial myPolynomial::operator-(const myPolynomial &poly) const
{
    myPolynomial tmp(*this);
    tmp._poly.clear();
    int t_term = 0, p_term = 0;
    while ((t_term < cnt_poly) && (p_term < poly.cnt_poly))
    {
        if (_poly[t_term].getExp() == poly._poly[p_term].getExp())
        {
            myTerm t(_poly[t_term].getCoeff() - poly._poly[p_term].getCoeff(), _poly[t_term].getExp());
            tmp._poly.push_back(t);
            t_term++;
            p_term++;
        }
        else if (_poly[t_term].getExp() > poly._poly[p_term].getExp())
        {
            myTerm t(_poly[t_term].getCoeff(), _poly[t_term].getExp());
            tmp._poly.push_back(t);
            t_term++;
        }
        else
        {
            myTerm p(-poly._poly[p_term].getCoeff(), poly._poly[p_term].getExp());
            tmp._poly.push_back(p);
            p_term++;
        }
    }
    for (; t_term < cnt_poly; t_term++)
    {
        myTerm t(_poly[t_term].getCoeff(), _poly[t_term].getExp());
        tmp._poly.push_back(t);
    }
    for (; p_term < poly.cnt_poly; p_term++)
    {
        myTerm p(-poly._poly[p_term].getCoeff(), poly._poly[p_term].getExp());
        tmp._poly.push_back(p);
    }
    sort(tmp._poly.begin(), tmp._poly.end(), compare);
    tmp.degree = tmp._poly[0].getExp();
    tmp.cnt_poly = tmp._poly.size();
    return tmp;
}
myPolynomial myPolynomial::operator*(const myPolynomial &poly) const
{
    myPolynomial tmp;
    tmp._poly.clear();
    for(int i=0;i<cnt_poly;i++)
    {
        for(int j=0;j<poly.cnt_poly;j++)
        {
            myTerm t(_poly[i].getCoeff() * poly._poly[j].getCoeff(), _poly[i].getExp() + poly._poly[j].getExp());
            tmp._poly.push_back(t);
        }
    }
    sort(tmp._poly.begin(), tmp._poly.end(), compare);
    tmp.cnt_poly = tmp._poly.size();
    int flag = 0;
    myPolynomial tmp1;
    tmp1._poly.clear();
    for(int i=0;i<tmp.cnt_poly;i++)
    {
        int coeff = tmp._poly[i].getCoeff();
        flag = 0;
        for(int j=i+1;j<tmp.cnt_poly;j++)
        {
            if (tmp._poly[i].getExp() == tmp._poly[j].getExp())
            {
                coeff += tmp._poly[j].getCoeff();
            }
            else 
            {
                myTerm t(coeff, tmp._poly[i].getExp());
                tmp1._poly.push_back(t);
                flag = 1;
                i = j - 1;
                break;
            }
        }
        if (flag == 0 && i == tmp.cnt_poly - 1) //마지막 항 처리
        {
            myTerm t(coeff, tmp._poly[i].getExp());
            tmp1._poly.push_back(t);
        }
    }
    sort(tmp1._poly.begin(), tmp1._poly.end(), compare);
    tmp1.cnt_poly = tmp1._poly.size();
    tmp1.degree = tmp1._poly[0].getExp();
    return tmp1;
}
myPolynomial myPolynomial::operator*(int k) const
{
    myPolynomial tmp(*this);
    tmp._poly.clear();
    for (int i = 0; i < cnt_poly; i++)
    {
        myTerm t(_poly[i].getCoeff() * k, _poly[i].getExp());
        tmp._poly.push_back(t);
    }
    return tmp;
}
myPolynomial operator*(int k, const myPolynomial &poly)
{
    myPolynomial tmp(poly);
    tmp._poly.clear();
    for (int i = 0; i < poly.cnt_poly; i++)
    {
        myTerm t(poly._poly[i].getCoeff() * k, poly._poly[i].getExp());
        tmp._poly.push_back(t);
    }
    return tmp;
}
long myPolynomial::operator()(int x) const
{
    long res = 0;

    for (int i = 0; i < cnt_poly; i++)
    {
        res += (long)_poly[i].getCoeff() * pow(x, _poly[i].getExp());
    }
    return res;
} // evaluate the polynomial
int myPolynomial::getDegree() const
{
    return degree;
} // get a degree of the polynomial
unsigned myPolynomial::getNumTerms() const
{
    return (unsigned)cnt_poly;
} // number of terms in the polynomial
myPolynomial myPolynomial::ddx() const
{
    myPolynomial tmp;
    int c = 0;
    tmp._poly.clear();
    for (int i = 0; i < cnt_poly; i++)
    {
        if (_poly[i].getExp() != 0)
        {
            myTerm t(_poly[i].getExp() * _poly[i].getCoeff(), _poly[i].getExp() - 1);
            tmp._poly.push_back(t);
        }
        else
            c++;
    }
    tmp.cnt_poly = cnt_poly - c;
    tmp.degree = tmp._poly[0].getExp();
    return tmp;
} // derivative of a polynomial
  // friend operators and functions
const myPolynomial myPolynomial::ZERO(0);             // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1);             // the monomial P(x) = x