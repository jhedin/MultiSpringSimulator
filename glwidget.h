#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <GL/glu.h>
#include <QTimer>
#include "simulation.h"

class GLWidget : public QGLWidget {
    Q_OBJECT

public:
    /// CONSTRUCTOR
    GLWidget(QWidget *parent = 0);

    /// DESTRUCTOR
    ~GLWidget();

    QTimer* timer;
    Simulation* sim;
    // ADD YOUR CODE

private:
    int h,w;


protected:
    /// OPENGL
    void initializeGL();
    void paintGL();
    void resizeGL( int width, int height );

signals:
    void sizeChanged(double width, double height);

public slots:
    // ADD YOUR CODE

private slots:


protected slots:


};

#endif // GLWIDGET_H
