#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cilindro.h>
#include <cone.h>
#include <esfera.h>
#include <figurageometrica.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->SaidaEsfera->setReadOnly(true);
    ui->SaidaCone->setReadOnly(true);
    ui->SaidaCilindro->setReadOnly(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonExecutar_clicked()
{
    try {
        double raio = ui->Raio->text().toDouble();
        double altura = ui->Altura->text().toDouble();

        tp2::Esfera esfera;
        esfera.setRaio(raio);

        double volumeEsfera = esfera.calcularVolume();
        double areaTotalEsfera = esfera.calcularAreaTotal();

        QString saida = "Volume: ";
        saida += QString::number(volumeEsfera);
        saida += "\n";
        saida += "Área total: ";
        saida += QString::number(areaTotalEsfera);
        saida += "\n";
        ui->SaidaEsfera->setText(saida);

        tp2::Cilindro cilindro;
        cilindro.setRaio(raio);
        cilindro.setAltura(altura);

        QString saidaCilindro;
        double volumeCilindro = cilindro.calcularVolume();
        double areaTotalCilindro = cilindro.calcularAreaTotal();
        double areaLateralCilindro = cilindro.calcularAreaLateral();

        saidaCilindro = "Volume: ";
        saidaCilindro += QString::number(volumeCilindro);
        saidaCilindro += "\n";
        saidaCilindro += "Área lateral: ";
        saidaCilindro += QString::number(areaLateralCilindro);
        saidaCilindro += "\n";
        saidaCilindro += "Área total: ";
        saidaCilindro += QString::number(areaTotalCilindro);
        saidaCilindro += "\n";
        ui->SaidaCilindro->setText(saidaCilindro);


        tp2::Cone cone;
        cone.setRaio(raio);
        cone.setAltura(altura);

        double geratrizCone = cone.calcularGeratriz();
        double areaLateralCone = cone.calcularAreaLateral();
        double areaTotalCone = cone.calcularAreaTotal();
        double volumeCone = cone.calcularVolume();

        QString saidaCone = "Geratriz: ";
        saidaCone += QString::number(geratrizCone);
        saidaCone += "\n";
        saidaCone += "Área lateral: ";
        saidaCone += QString::number(areaLateralCone);
        saidaCone += "\n";
        saidaCone += "Área total: ";
        saidaCone += QString::number(areaTotalCone);
        saidaCone += "\n";
        saidaCone = "Volume: ";
        saidaCone += QString::number(volumeCone);
        saidaCone += "\n";
        ui->SaidaCone->setText(saidaCone);
    } catch (QString &erro) {
       QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->Raio->clear();
    ui->Altura->clear();
    ui->SaidaEsfera->clear();
    ui->SaidaCone->clear();
    ui->SaidaCilindro->clear();
}
