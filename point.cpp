#include "includes.h"

point::point(double x0, double y0)
{
    x = x0;
    y = y0;
}

point::point(point * p)
{
    x = p->x;
    y = p->y;
}

void point::add(point* p)
{
    x += p->x;
    y += p->y;
}

void point::subtract(point* p)
{
    x -= p->x;
    y -= p->y;
}

void point::multiply(double p)
{
    x *= p;
    y *= p;
}

void point::divide(double p)
{
    x /= p;
    y /= p;
}

void point::tangent()
{
    normalize();
}

void point::normal()
{
    tangent();
    double temp = x;
    x = -y;
    y = temp;
}

void point::normalize()
{
    divide(length());
}

double point::length()
{
    return sqrt(x*x + y*y);
}
