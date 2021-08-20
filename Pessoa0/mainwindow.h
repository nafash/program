#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <pessoa.h>
#include <estudante.h>
#include <trabalhador.h>
#include <graduado.h>
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
    void on_estudante_clicked();

    void on_trabalhador_clicked();

    void on_graduado_clicked();

    void on_Resultado_clicked();

    void on_Clear_clicked();

    void on_radioButton_estudante_clicked();

    void on_radioButton_trabalhador_clicked();

    void on_radioButton_graduado_clicked();

private:
    Ui::MainWindow *ui;
    tp2::Estudante estudante;
    tp2::Trabalhador trabalhador;
    tp2::Graduado graduado;

};

#endif // MAINWINDOW_H
