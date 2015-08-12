#ifndef POINT_H
#define POINT_H

class point
{
public:
    double x;
    double y;
    point(double x0, double y0);
    point(point*p);
    void add(point* p);
    void subtract(point* p);
    void multiply(double p);
    void divide(double p);
    void tangent();
    void normal();
    void normalize();
    double length();
};

#endif // POINT_H
