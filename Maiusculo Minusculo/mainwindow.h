#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <converter.h>
#include <QMainWindow>
#include <QFileDialog>
#include <converter.h>
#include <QMessageBox>
#include <fstream>

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
    void on_OpenArchive_clicked();

    void on_CreateArchive_clicked();

    void on_CoverterMaiusculo_clicked();

    void on_CoverterMinusculo_clicked();

    void on_CoverterMinusculoMaiusculo_clicked();

    void on_Clear_clicked();

private:
    Ui::MainWindow *ui;
    tp2::Converter *texto;
};

#endif // MAINWINDOW_H
