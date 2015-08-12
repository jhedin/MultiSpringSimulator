#include "includes.h"

GLWidget::GLWidget( QWidget *parent ) : QGLWidget( parent ) {
    // ADD YOUR CODE
    sim = new Simulation();
    connect(sim, SIGNAL(render()), this, SLOT(updateGL()));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), sim, SLOT(step()));
    timer->start(sim->t_sim * sim->t_render * 1000.0);
}

GLWidget::~GLWidget() {

}

void GLWidget::initializeGL() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glShadeModel( GL_FLAT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

}

//copied from http://slabode.exofire.net/circle_draw.shtml
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 2 * 3.1415926 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor

    float radial_factor = cosf(theta);//calculate the radial factor

    float x = r;//we start at angle = 0

    float y = 0;

    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex

        //calculate the tangential vector
        //remember, the radial vector is (x, y)
        //to get the tangential vector we flip those coordinates and negate one of them

        float tx = -y;
        float ty = x;

        //add the tangential vector

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}


void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef( w/2.0, h/2.0, 0.0);
    glRotatef(-sim->dyn->alpha, 0.0, 0.0, 1.0);


   models* m = sim->m;
    double x, y;
    double x_offset = 0;
    double y_offset = 0;

    glLineWidth(2);
    glColor3f(0.0, 0.0, 0.0);
    glEnable(GL_LINE_SMOOTH);

    glBegin(GL_LINE_STRIP);
    glVertex2f(-3.0*w/8.0, h/2);
    glVertex2f(-3.0*w/8.0, 0);
    glVertex2f(0, 0);
    glVertex2f(w/2.0, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (std::vector<point*>::iterator it = m->points.begin() ; it != m->points.end(); ++it)
    {
        x = (*it)->x + x_offset;
        y = (*it)->y + y_offset;
        glVertex2f(x, y);
    }
    glEnd();
    DrawCircle(x, y, sim->dyn->r, 360);
    DrawCircle(x + sim->dyn->r / 2.0  * cos(sim->dyn->theta), y + sim->dyn->r / 2.0 * sin(sim->dyn->theta), 3 , 30);

}

void GLWidget::resizeGL( int width, int height ) {
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0.0,GLdouble(width),0,GLdouble(height),-10.0,10.0);
    glFlush();
    glMatrixMode(GL_MODELVIEW);
    glViewport( 0, 0, (GLint)width, (GLint)height );
    h = height;
    w = width;
    sizeChanged(width, height);
}

// ADD YOUR CODE
