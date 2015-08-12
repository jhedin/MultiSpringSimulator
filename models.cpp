#include "includes.h"

models::models()
{
    width = 10;
    windings = 5;
    x = 100;
}

void models::calc_points(double new_x)
{
    x = -new_x;
    points.clear();

    points.push_back(new point(0,0));
    points.push_back(new point(0,x*0.05));
    for(int i = 0; i < windings * 2; i++)
        points.push_back(new point((2*(i%2)-1)*width/2, x*0.05 + x*0.9*(1+2*i)/(4*windings)));
    points.push_back(new point(0,x*0.95));
    points.push_back(new point(0,x));

}

void models::calc_points(point* start, point* end)
{
    // calc tanget and normal vectors

    point* temp = new point(end);
    temp->subtract(start);
    point * tan = new point(temp);
    tan->tangent();
    point * norm = new point(temp);
    norm->normal();

    x = temp->length();
    points.clear();

    temp->x = start->x;
    temp->y = start->y;

    points.push_back(new point(start));

    point * s_tan = new point(tan);
    point * s_norm = new point(norm);

    s_tan->multiply(0.05 * x);
    temp->add(s_tan);
    points.push_back(new point(temp));

    s_tan->x = tan->x;
    s_tan->y = tan->y;
    s_tan->multiply(x*0.9/(4*windings));
    temp->add(s_tan);
    s_norm->multiply(-width/2);
    temp->add(s_norm);
    points.push_back(new point(temp));

    s_tan->x = tan->x;
    s_tan->y = tan->y;
    s_tan->multiply(x*0.9/(2*windings));
    s_norm->x = norm->x;
    s_norm->y = norm->y;
    s_norm->multiply(-width);

    for(int i = 1; i < (windings * 2) - 1; i++)
    {
        s_norm->multiply(-1);
        temp->add(s_tan);
        temp->add(s_norm);

        points.push_back(new point(temp));
    }

    /*temp->x = start->x;
    temp->y = start->y;
    s_tan->x = tan->x;
    s_tan->y = tan->y;
    s_tan->multiply(x*0.9);
    temp->add(s_tan);
    s_norm->x = norm->x;
    s_norm->y = norm->y;
    s_norm->multiply(width/2);
    temp->add(s_norm);
    points.push_back(new point(temp));*/

    temp->x = start->x;
    temp->y = start->y;
    s_tan->x = tan->x;
    s_tan->y = tan->y;
    s_tan->multiply(0.95 * x);
    temp->add(s_tan);
    points.push_back(new point(temp));
    points.push_back(new point(end));


}

void models::print_points()
{
    for (std::vector<point*>::iterator it = points.begin() ; it != points.end(); ++it)
        std::cout << ' ' << (*it)->x << ' ' << (*it)->y << '\n';
      std::cout << '\n';

}


