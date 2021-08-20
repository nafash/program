#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    quantidade(0)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->elementos->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_humano_clicked()
{
    tp2::Humano* aux;
    aux = new tp2::Humano;
    vetor[quantidade] = aux;
    QString saida("");
    quantidade++;
    if(quantidade==10){
        for(int j=0;j<10;j++){
            saida += vetor[j]->fala();
            saida += "\n";
        }
        quantidade = 0;
    }
    ui->textEdit->setText(saida);
    QString elementos = QString::number(quantidade);
    elementos += " elementos no vetor";
    ui->elementos->setText(elementos);
}

void MainWindow::on_cachorro_clicked()
{
    tp2::Cachorro* aux;
    aux = new tp2::Cachorro;
    vetor[quantidade] = aux;
    QString saida("");
    quantidade++;
    if(quantidade==10){
        for(int j=0;j<10;j++){
            saida += vetor[j]->fala();
            saida += "\n";
        }
        quantidade = 0;
    }
    ui->textEdit->setText(saida);
    QString elementos = QString::number(quantidade);
    elementos += " elementos no vetor";
    ui->elementos->setText(elementos);
}

void MainWindow::on_gato_clicked()
{
    tp2::Gato* aux;
    aux = new tp2::Gato;
    vetor[quantidade] = aux;
    QString saida("");
    quantidade++;
    if(quantidade==10){
        for(int j=0;j<10;j++){
            saida += vetor[j]->fala();
            saida += "\n";
        }
        quantidade = 0;
    }
    ui->textEdit->setText(saida);
    QString elementos = QString::number(quantidade);
    elementos += " elementos no vetor";
    ui->elementos->setText(elementos);
}
