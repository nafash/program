#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->modelo->setEnabled(false);
    ui->cor->setEnabled(false);
    ui->toneladas->setEnabled(false);
    ui->altura->setEnabled(false);
    ui->comprimento->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CarroDePasseio_clicked()
{
    ui->modelo->setEnabled(true);
    ui->cor->setEnabled(true);

    ui->toneladas->setEnabled(false);
    ui->altura->setEnabled(false);
    ui->comprimento->setEnabled(false);
}

void MainWindow::on_Caminhao_clicked()
{
    ui->modelo->setEnabled(false);
    ui->cor->setEnabled(false);

    ui->toneladas->setEnabled(true);
    ui->altura->setEnabled(true);
    ui->comprimento->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    float peso = ui->peso->text().toFloat();
    float velocidade = ui->velocidade->text().toFloat();
    int cilindros = ui->cilindros->text().toInt();
    int potencia = ui->potencia->text().toInt();

    if(ui->CarroDePasseio->isChecked()){
        QString modelo = ui->modelo->text();
        QString cor = ui->cor->text();

        carro.setCor(cor);
        carro.setModelo(modelo);
        carro.setPeso(peso);
        carro.setVelocidade(velocidade);
        carro.setNDeCilindros(cilindros);
        carro.setPotencia(potencia);

        ui->textEdit->setText(carro.printf());
    }

    if(ui->Caminhao->isChecked()){
        float toneladas = ui->toneladas->text().toFloat();
        float altura = ui->altura->text().toFloat();
        float comprimento = ui->comprimento->text().toFloat();

        caminhao.setPeso(peso);
        caminhao.setVelocidade(velocidade);
        caminhao.setNDeCilindros(cilindros);
        caminhao.setPotencia(potencia);
        caminhao.setToneladas(toneladas);
        caminhao.setAltura(altura);
        caminhao.setComprimento(comprimento);

        ui->textEdit->setText(caminhao.printf());
    }
}
