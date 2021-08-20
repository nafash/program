#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Resultado->setReadOnly(true);
    ui->radioButton_4->setDisabled(true);
    ui->radioButton_3->setDisabled(true);
    ui->cpf->setDisabled(true);
    ui->razaoSocial->setDisabled(true);
    ui->cnpj->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked()
{
    try {
        ui->radioButton_4->setDisabled(false);
        ui->radioButton_3->setDisabled(false);
        ui->cpf->setDisabled(false);

        ui->razaoSocial->setDisabled(true);
        ui->cnpj->setDisabled(true);

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_radioButton_2_clicked()
{
    try {
        ui->radioButton_4->setDisabled(true);
        ui->radioButton_3->setDisabled(true);
        ui->cpf->setDisabled(true);

        ui->razaoSocial->setDisabled(false);
        ui->cnpj->setDisabled(false);

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_Executar_clicked()
{
    try {
            QString saida = "";

            QString nome = ui->nome->text();

            QString moradia = ui->moradia->text();

            int telefone  = ui->telefone->text().toInt();

            float rendaBruta = ui->rendaBruta->text().toInt();

        if(ui->radioButton->isChecked())
        {
            fisica.setNome(nome);

            fisica.setMoradia(moradia);

            fisica.setTelefone(telefone);

            fisica.setRendaBruta(rendaBruta);

            int CPF = ui->cpf->text().toInt();
            fisica.setCPF(CPF);

            saida = "Nome: ";
            saida += fisica.getNome();
            saida += "\n";
            saida += "Endereço: ";
            saida += fisica.getMoradia();
            saida += "\n";
            saida += "Telefone: ";
            saida += QString::number(fisica.getTelefone());
            saida += "\n";
            saida += "Renda Bruta: ";
            saida += QString::number(fisica.getRendaBruta());
            saida += "\n";
            saida += "CPF: ";
            saida += QString::number(fisica.getCPF());
            saida += "\n";
            saida += "Sexo: ";
            if(ui->radioButton->isChecked())
                saida += "Masculino";
            if(ui->radioButton_2->isChecked())
                saida += "Feminino";
            saida += "\n";
            saida += "Imposto: ";
            saida += QString::number(fisica.calcularImposto());
        }

        if(ui->radioButton_2->isChecked())
        {
            juridica.setNome(nome);

            juridica.setMoradia(moradia);

            juridica.setTelefone(telefone);

            juridica.setRendaBruta(rendaBruta);

            int CNPJ = ui->cnpj->text().toInt();
            juridica.setCNPJ(CNPJ);

            QString razaoSocial = ui->razaoSocial->text();
            juridica.setRazaoSocial(razaoSocial);

            saida = "Nome: ";
            saida += fisica.getNome();
            saida += "\n";
            saida += "Endereço: ";
            saida += juridica.getMoradia();
            saida += "\n";
            saida += "Telefone: ";
            saida += QString::number(juridica.getTelefone());
            saida += "\n";
            saida += "Renda Bruta: ";
            saida += QString::number(juridica.getRendaBruta());
            saida += "\n";
            saida += "CNPJ: ";
            saida += QString::number(juridica.getCNPJ());
            saida += "\n";
            saida += "Razão Social: ";
            saida += juridica.getRazaoSocial();
            saida += "\n";
            saida += "Imposto: ";
            saida += QString::number(juridica.calcularImposto());
        }

        ui->Resultado->setText(saida);

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->nome->clear();
    ui->email->clear();
    ui->telefone->clear();
    ui->moradia->clear();
    ui->rendaBruta->clear();
    ui->cpf->clear();
    ui->razaoSocial->clear();
    ui->cnpj->clear();

    ui->radioButton_4->setDisabled(true);
    ui->radioButton_3->setDisabled(true);
    ui->cpf->setDisabled(true);
    ui->razaoSocial->setDisabled(true);
    ui->cnpj->setDisabled(true);
}
