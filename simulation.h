#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include "models.h"
#include "dynamics.h"

class Simulation : public QObject
{
    Q_OBJECT
public:
    explicit Simulation(QObject *parent = 0);
    double t_sim;
    // todo: change to double, have a sim loop and a render loop
    int t_render;
    models* m;
    dynamics* dyn;
    double h;
    double w;

signals:
    void render();

public slots:
    void step();
    void sizeChanged(double width, double height);

};

#endif // SIMULATION_H
