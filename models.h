#ifndef MODELS_H
#define MODELS_H

#include <vector>
#include <iostream>
#include <math.h>
#include "point.h"

class models
{
public:
    models();
    double width;
    int windings;
    double x;
    std::vector<point*> points;

    void calc_points(double new_x);
    void print_points();
    void calc_points(point* start, point* end);
};

#endif // MODELS_H
