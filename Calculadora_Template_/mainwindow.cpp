#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->lineEdit->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    try {
        if(ui->radioButton_Inteiro->isChecked()){
            int num1=ui->lineEdit->text().toInt();
            int num2=ui->lineEdit_2->text().toInt();
            tp2::Calculadora<int> calculadoraInt(num1,num2);
            int soma = calculadoraInt.adicionar();
            QString saida("");
            saida+="Soma: ";
            saida+=QString::number(soma);
            ui->textEdit->setText(saida);
        }
        if(ui->radioButton_Real->isChecked()){
            double num1=ui->lineEdit->text().toDouble();
            double num2=ui->lineEdit_2->text().toDouble();
            tp2::Calculadora<double> calculadoraInt(num1,num2);
            double soma = calculadoraInt.adicionar();
            QString saida("");
            saida+="Soma: ";
            saida+=QString::number(soma);
            ui->textEdit->setText(saida);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    try {
        if(ui->radioButton_Inteiro->isChecked()){
            int num1=ui->lineEdit->text().toInt();
            int num2=ui->lineEdit_2->text().toInt();
            tp2::Calculadora<int> calculadoraInt(num1,num2);
            int soma = calculadoraInt.subtrair();
            QString saida("");
            saida+="Subtração: ";
            saida+=QString::number(soma);
            ui->textEdit->setText(saida);
        }
        if(ui->radioButton_Real->isChecked()){
            double num1=ui->lineEdit->text().toDouble();
            double num2=ui->lineEdit_2->text().toDouble();
            tp2::Calculadora<double> calculadoraInt(num1,num2);
            double soma = calculadoraInt.subtrair();
            QString saida("");
            saida+="Subtração: ";
            saida+=QString::number(soma);
            ui->textEdit->setText(saida);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    try {
        if(ui->radioButton_Inteiro->isChecked()){
            int num1=ui->lineEdit->text().toInt();
            int num2=ui->lineEdit_2->text().toInt();
            tp2::Calculadora<int> calculadoraInt(num1,num2);
            int soma = calculadoraInt.multiplicar();
            QString saida("");
            saida+="Multiplicação: ";
            saida+=QString::number(soma);
            ui->textEdit->setText(saida);
        }
        if(ui->radioButton_Real->isChecked()){
            double num1=ui->lineEdit->text().toDouble();
            double num2=ui->lineEdit_2->text().toDouble();
            tp2::Calculadora<double> calculadoraInt(num1,num2);
            double soma = calculadoraInt.multiplicar();
            QString saida("");
            saida+="Multiplicação: ";
            saida+=QString::number(soma);
            ui->textEdit->setText(saida);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    try {
        if(ui->radioButton_Inteiro->isChecked()){
            int num1=ui->lineEdit->text().toInt();
            int num2=ui->lineEdit_2->text().toInt();
            tp2::Calculadora<int> calculadoraInt(num1,num2);
            int soma = calculadoraInt.dividir();
            QString saida("");
            saida+="Divisão: ";
            saida+=QString::number(soma);
            ui->textEdit->setText(saida);
        }
        if(ui->radioButton_Real->isChecked()){
            double num1=ui->lineEdit->text().toDouble();
            double num2=ui->lineEdit_2->text().toDouble();
            tp2::Calculadora<double> calculadoraInt(num1,num2);
            double soma = calculadoraInt.dividir();
            QString saida("");
            saida+="Divisão: ";
            saida+=QString::number(soma);
            ui->textEdit->setText(saida);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_radioButton_Inteiro_clicked()
{
    ui->lineEdit->setVisible(true);
    ui->lineEdit_2->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(true);
    ui->pushButton_6->setVisible(true);
}

void MainWindow::on_radioButton_Real_clicked()
{
    ui->lineEdit->setVisible(true);
    ui->lineEdit_2->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(true);
    ui->pushButton_6->setVisible(true);
}
