#include <cstdlib>
#include <cmath>
#include "MyPoint.h"
// constructors
MyPoint::MyPoint()
    : x(0), y(0) // set default to origin (0,0)
{
}
MyPoint::MyPoint(int coordX, int coordY)
    : x(coordX), y(coordY)
{
}
MyPoint::MyPoint(const MyPoint &p)
{
    this->x = p.x;
    this->y = p.y;
}
// accessor functions
int MyPoint::getX() const
{
    return x;
}
int MyPoint::getY() const
{
    return y;
}
// mutator functions
void MyPoint::setX(int coordX)
{
    x = coordX;
}
void MyPoint::setY(int coordY)
{
    y = coordY;
}
bool MyPoint::operator==(const MyPoint &p) const
{
    return ((this->x == p.x && this->y == p.y));
}
bool MyPoint::operator!=(const MyPoint &p) const
{
    return !operator==(p);
}
// 직선거리(Euclidean distance)의 제곱을 계산
int MyPoint::dist2sqr(const MyPoint &p) const
{
    return (pow(this->x - p.getX(), 2) + pow(this->y - p.getY(), 2));
}
// 직각거리(rectilinear distance)를 계산
int MyPoint::dist1(const MyPoint &p) const
{
    return abs(this->x - p.getX()) + abs(this->y - p.getY());
}