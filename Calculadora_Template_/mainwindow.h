#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <calculadora.h>
#include <QMainWindow>
#include <QMessageBox>

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
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_radioButton_Inteiro_clicked();

    void on_radioButton_Real_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
