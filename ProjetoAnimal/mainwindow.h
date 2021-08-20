#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <gato.h>
#include <humano.h>
#include <cachorro.h>
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
    void on_humano_clicked();

    void on_cachorro_clicked();

    void on_gato_clicked();

private:
    Ui::MainWindow *ui;
    tp2::Animal* vetor[10];
    int quantidade;
};

#endif // MAINWINDOW_H
