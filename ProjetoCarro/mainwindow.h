#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <caminhao.h>
#include <carrodepasseio.h>
#include <motor.h>
#include <veiculo.h>

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
    void on_CarroDePasseio_clicked();

    void on_Caminhao_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    tp2::Caminhao caminhao;
    tp2::CarroDePasseio carro;
};

#endif // MAINWINDOW_H
