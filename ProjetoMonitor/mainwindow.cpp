#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nome->setDisabled(true);
    ui->matricula->setDisabled(true);
    ui->curso->setDisabled(true);
    ui->nome_2->setDisabled(true);
    ui->salario->setDisabled(true);
    ui->turno->setDisabled(true);
    ui->rg->setDisabled(true);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_Estudante_clicked()
{
    ui->nome->setEnabled(true);
    ui->matricula->setEnabled(true);
    ui->curso->setEnabled(true);

    ui->nome_2->setDisabled(true);
    ui->salario->setDisabled(true);
    ui->turno->setDisabled(true);
    ui->rg->setDisabled(true);
}

void MainWindow::on_radioButton_Funcionario_clicked()
{
    ui->nome->setEnabled(false);
    ui->matricula->setEnabled(false);
    ui->curso->setEnabled(false);

    ui->nome_2->setDisabled(false);
    ui->salario->setDisabled(false);
    ui->turno->setDisabled(false);
    ui->rg->setDisabled(false);
}

void MainWindow::on_pushButton_clicked()
{
    try {
            QString disciplina = ui->disciplina->text();
            int cargaHoraria = ui->cargaHorario->text().toInt();
            monitor.setDisciplina(disciplina);
            monitor.setCargaHoraria(cargaHoraria);

            if(ui->radioButton_Estudante->isChecked()){
                QString nome = ui->nome->text();
                int matricula = ui->matricula->text().toInt();
                QString curso = ui->curso->text();

                estudante.setNome(nome);
                estudante.setMatricula(matricula);
                estudante.setCurso(curso);

                QString saida;
                saida += monitor.printf();
                saida += estudante.printf();

                ui->textEdit->setText(saida);
            }
            if(ui->radioButton_Funcionario->isChecked()){
                QString nome = ui->nome_2->text();
                double salario = ui->salario->text().toDouble();
                int RG = ui->rg->text().toInt();
                QString turno = ui->turno->text();

                funcionario.setNome(nome);
                funcionario.setSalario(salario);
                funcionario.setRg(RG);
                funcionario.setTurno(turno);

                QString saida;
                saida += monitor.printf();
                saida += funcionario.printf();

                ui->textEdit->setText(saida);
            }

        } catch (QString erro){
            QMessageBox::information(this,"ERRO", erro);
        }
}
