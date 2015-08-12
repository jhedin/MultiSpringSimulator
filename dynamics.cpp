#include "includes.h"

dynamics::dynamics(QObject *parent) :
    QObject(parent)
{

    // system
    k = 15;
    c = 2;
    m = 10;
    t = 0.01;
    gamma = .5;
    beta = 0.12;
    alpha = 15;
    r = 30;

    // initial values
    d0 = 100;
    x0 = 500;
    v0 = 0;

    // @i
    x = 0;
    v = 0;
    a = 0;

    // @i+1
    xp = 0;
    vp = 0;
    ap = 0;

    // estimates
    xe = 0;
    ve = 0;

    fa = 3;
    omega = 0.5;
    phase = 0.5;

    fg = 9.81;

}

void dynamics::init() {

    x = x0;
    v = v0;
    t_curr = 0;

    double f = fg * sin(alpha);
    //double f = 2000.0;

    a = (f - c*v - k*(x-d0))/(m + gamma*t*c + beta*t*t*k);
    //printf("%1.3lf %6.1lf %1.4lf %6.3lf %4.3lf %4.3lf %4.4lf\n", t_curr, f, xe, k*xe, a, v, x);


}

void dynamics::step(){

    double f = fg * sin(alpha);

    t_curr += t;

    // estimate the next step
    xe = x + t*v + t*t/2*(1 - 2*beta)*a;
    ve = v + t*(1-gamma)*a;
    ap = (f - c * ve - k * (xe-d0))/(m + gamma*t*c + beta*t*t*k);

    // correct the estimates by linear interpolation between the accelerations.
    xp = xe + t*t*beta*ap;
    vp = ve + t*gamma*ap;

    x = xp;
    v = vp;
    a = ap;
    theta =  - x / r;


    //printf("%1.3lf %6.1lf %1.4lf %6.3lf %4.3lf %4.3lf %4.4lf\n", t_curr, f, xe, k*xe, a, v, x);

}


