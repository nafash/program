#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <monitor.h>
#include <estudante.h>
#include <funcionario.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_Estudante_clicked();

    void on_radioButton_Funcionario_clicked();

private:
    Ui::MainWindow *ui;
    tp2::Monitor monitor;
    tp2::Estudante estudante;
    tp2::Funcionario funcionario;
};

#endif // MAINWINDOW_H
