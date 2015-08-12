#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "includes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void update_wn(double wn);
    
private slots:

    void on_t_valueChanged(double arg1);

    void on_m_valueChanged(double arg1);

    void on_k_valueChanged(double arg1);

    void on_c_valueChanged(double arg1);

    void on_d0_valueChanged(double arg1);

    void on_x0_valueChanged(double arg1);

    void on_v0_valueChanged(double arg1);

    void on_gamma_valueChanged(double arg1);

    void on_beta_valueChanged(double arg1);

    void on_fg_valueChanged(double arg1);

    void on_fa_valueChanged(double arg1);

    void on_omega_valueChanged(double arg1);

    void on_phi_valueChanged(double arg1);

    void on_width_valueChanged(double arg1);

    void on_windings_valueChanged(double arg1);

    void on_restart_clicked();

    void on_t_render_valueChanged(int arg1);

    void on_alpha_valueChanged(double arg1);

    void on_r_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

    // ADD YOUR CODE
};

#endif // MAINWINDOW_H
