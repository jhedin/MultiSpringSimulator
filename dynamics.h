#ifndef DYNAMICS_H
#define DYNAMICS_H

#include <QObject>

class dynamics : public QObject
{
    Q_OBJECT
public:
    explicit dynamics(QObject *parent = 0);

    void init();
    void step();

    // system
    double k;
    double c;
    double m;

    double alpha;
    double r;

    double t;
    double t_curr;
    double gamma;
    double beta;

    double d0;
    double x0;
    double v0;

    // @i
    double x;
    double v;
    double a;
    double theta;
    double theta_dot;
    double theta_dot_dot;

    // @i+1
    double xp;
    double vp;
    double ap;

    // @i-1
    double xm;
    double vm;

    // estimates
    double xe;
    double ve;

    // force f = fa*sin(omega*t_curr)
    // is error prone and should use a better integrator
    double fa;
    double omega;
    double phase;

    double fg;

signals:

public slots:

};

#endif // DYNAMICS_H
