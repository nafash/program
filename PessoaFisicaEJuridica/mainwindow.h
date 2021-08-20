#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <pessoafisica.h>
#include <pessoajuridica.h>
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
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_Executar_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    tp2::PessoaFisica fisica;
    tp2::PessoaJuridica juridica;
};

#endif // MAINWINDOW_H
