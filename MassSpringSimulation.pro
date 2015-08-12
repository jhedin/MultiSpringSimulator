QT       += core gui opengl widgets declarative

TARGET   = MassSpringSimulation
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           glwidget.cpp \
    dynamics.cpp \
    models.cpp \
    point.cpp \
    simulation.cpp


HEADERS  += mainwindow.h \
            glwidget.h \
    dynamics.h \
    models.h \
    includes.h \
    point.h \
    simulation.h

FORMS    += mainwindow.ui
