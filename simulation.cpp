#include "includes.h"

Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
    m = new models();
    dyn = new dynamics();
    dyn->init();
    t_sim = 0.01;
    t_render = 5;
}

void Simulation::step()
{
    dyn->t = t_sim;
    for(int i = 0; i < t_render; i++)
        dyn->step();
    m->calc_points(new point(-3.0*w/8.0, dyn->r), new point(-3.0*w/8.0 +dyn->x,dyn->r));
    emit(render());
}

void Simulation::sizeChanged(double width, double height)
{
    w = width;
    h = height;
}
