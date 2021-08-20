#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <agenda.h>
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
    void limparBusca()const;
    void mostrarAgenda();
    void limparCampos()const;

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_adicionar_clicked();

    void on_pushButton_buscar_clicked();

    void on_pushButton_remover_clicked();

    void on_showList_clicked();

private:
    Ui::MainWindow *ui;
    tp2::PessoaFisica PessoaFisica;
    tp2::PessoaJuridica PessoaJuridica;
    tp2::Agenda agenda;
};

#endif // MAINWINDOW_H
