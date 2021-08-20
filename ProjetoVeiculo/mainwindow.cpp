#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<motor.h>
#include<veiculo.h>
#include<carropasseio.h>
#include<caminhao.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditCor->setDisabled(true);
    ui->lineEditModelo->setDisabled(true);

    ui->lineEditAltura->setDisabled(true);
    ui->lineEditTonelada->setDisabled(true);
    ui->lineEditComprimento->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButtonCarro_clicked()
{
    ui->labelCor->setDisabled(false);
    ui->labelModelo->setDisabled(false);
    ui->lineEditCor->setDisabled(false);
    ui->lineEditModelo->setDisabled(false);

    ui->labelaltura->setDisabled(true);
    ui->labeltonelada->setDisabled(true);
    ui->labelcomprimento->setDisabled(true);
    ui->lineEditAltura->setDisabled(true);
    ui->lineEditTonelada->setDisabled(true);
    ui->lineEditComprimento->setDisabled(true);

}

void MainWindow::on_radioButtonCaminhao_clicked()
{
    ui->lineEditCor->setDisabled(true);
    ui->lineEditModelo->setDisabled(true);

    ui->lineEditAltura->setDisabled(false);
    ui->lineEditTonelada->setDisabled(false);
    ui->lineEditComprimento->setDisabled(false);
}

void MainWindow::on_pushButtoLimpar_clicked()
{

    ui->lineEditCor->setDisabled(true);
    ui->lineEditModelo->setDisabled(true);

    ui->lineEditAltura->setDisabled(true);
    ui->lineEditTonelada->setDisabled(true);
    ui->lineEditComprimento->setDisabled(true);


    ui->lineEditCor->clear();
    ui->lineEditModelo->clear();
    ui->lineEditAltura->clear();
    ui->lineEditTonelada->clear();
    ui->lineEditComprimento->clear();
    ui->lineEditPotencia->clear();
    ui->lineEditPreco->clear();
    ui->lineEditCilindro->clear();
    ui->lineEditVelocidade->clear();
    ui->lineEditPeso->clear();

    ui->textEditDados->clear();

}

void MainWindow::on_pushButtonExecutar_clicked()
{
    try {
        double Tonelada=ui->lineEditTonelada->text().toDouble();
        double AlturaMaxima=ui->lineEditAltura->text().toDouble();
        double Comprimento=ui->lineEditComprimento->text().toDouble();
        QString Modelo=ui->lineEditModelo->text();
        QString Cor=ui->lineEditCor->text();
        int NumeroCilindros=ui->lineEditCilindro->text().toInt();
        QString Potencia=ui->lineEditPotencia->text();
        double Peso=ui->lineEditPeso->text().toDouble();
        double VelocidadeMaxima=ui->lineEditVelocidade->text().toDouble();
        double Preco=ui->lineEditPreco->text().toDouble();

        if(ui->radioButtonCarro->isChecked())
        {
            tp2::CarroPasseio Aux( Peso, VelocidadeMaxima, Preco, NumeroCilindros, Potencia, Modelo, Cor);

            ui->textEditDados->setText(Aux.print());
        }

        if(ui->radioButtonCaminhao->isChecked())
        {
            tp2::Caminhao Aux( Peso, VelocidadeMaxima, Preco, NumeroCilindros, Potencia, Tonelada,  AlturaMaxima, Comprimento);

            ui->textEditDados->setText(Aux.print());
        }

    } catch(QString &erro) {
        QMessageBox::information(this,"Erro",erro);
    }
}
