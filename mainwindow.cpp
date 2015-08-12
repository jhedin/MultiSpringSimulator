#include "mainwindow.h"
#include "includes.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    connect(ui->glwidget, SIGNAL(sizeChanged(double,double)), ui->glwidget->sim, SLOT(sizeChanged(double,double)));
    //emit(update_wn(sqrt(ui->glwidget->sim->dyn->k/ui->glwidget->sim->dyn->m)));

}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_t_valueChanged(double arg1)
{
    ui->glwidget->sim->t_sim = arg1;
    ui->glwidget->timer->setInterval(  ui->glwidget->sim->t_sim*  ui->glwidget->sim->t_render*1000.0);
}

void MainWindow::on_t_render_valueChanged(int arg1)
{
    ui->glwidget->sim->t_render = arg1;
    ui->glwidget->timer->setInterval(  ui->glwidget->sim->t_sim*  ui->glwidget->sim->t_render*1000.0);

}

void MainWindow::on_m_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->m = arg1;
    emit(update_wn(sqrt(ui->glwidget->sim->dyn->k/ui->glwidget->sim->dyn->m)));
}

void MainWindow::on_k_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->k = arg1;
    emit(update_wn(sqrt(ui->glwidget->sim->dyn->k/ui->glwidget->sim->dyn->m)));
}

void MainWindow::on_c_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->c = arg1;
}

void MainWindow::on_d0_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->d0 = arg1;
}

void MainWindow::on_x0_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->x0 = arg1;
    ui->glwidget->sim->dyn->init();
}

void MainWindow::on_v0_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->v0 = arg1;
    ui->glwidget->sim->dyn->init();
}

void MainWindow::on_gamma_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->gamma = arg1;
}

void MainWindow::on_beta_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->beta = arg1;
}

void MainWindow::on_fg_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->fg = arg1;
}

void MainWindow::on_fa_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->fa = arg1;
}

void MainWindow::on_omega_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->omega = arg1;
}

void MainWindow::on_phi_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->phase = arg1;
}

void MainWindow::on_width_valueChanged(double arg1)
{
    ui->glwidget->sim->m->width = arg1;
}

void MainWindow::on_windings_valueChanged(double arg1)
{
    ui->glwidget->sim->m->windings = arg1;
}

void MainWindow::on_restart_clicked()
{
    ui->glwidget->sim->dyn->init();
}

void MainWindow::on_alpha_valueChanged(double arg1)
{
    ui->glwidget->sim->dyn->alpha = arg1;
}

void MainWindow::on_r_valueChanged(double arg1)
{
     ui->glwidget->sim->dyn->r = arg1;
}
