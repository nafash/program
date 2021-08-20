#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_cpf->setVisible(false);
    ui->label_estadocivil->setVisible(false);
    ui->cpf->setVisible(false);
    ui->estadocivil->setVisible(false);

    ui->label_cnpj->setVisible(false);
    ui->label_razaosocial->setVisible(false);
    ui->label_inscricaosocial->setVisible(false);
    ui->cnpj->setVisible(false);
    ui->razaosocial->setVisible(false);
    ui->inscricaosocial->setVisible(false);

    ui->label_dia->setVisible(false);
    ui->label_mes->setVisible(false);
    ui->label_ano->setVisible(false);
    ui->dia->setVisible(false);
    ui->mes->setVisible(false);
    ui->ano->setVisible(false);

    ui->textEdit_saida->setReadOnly(true);
    ui->textEdit_saida_2->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked()
{
    ui->label_cpf->setVisible(true);
    ui->label_estadocivil->setVisible(true);
    ui->cpf->setVisible(true);
    ui->estadocivil->setVisible(true);
    ui->label_dia->setVisible(true);
    ui->label_mes->setVisible(true);
    ui->label_ano->setVisible(true);
    ui->dia->setVisible(true);
    ui->mes->setVisible(true);
    ui->ano->setVisible(true);

    ui->label_cnpj->setVisible(false);
    ui->label_razaosocial->setVisible(false);
    ui->label_inscricaosocial->setVisible(false);
    ui->cnpj->setVisible(false);
    ui->razaosocial->setVisible(false);
    ui->inscricaosocial->setVisible(false);
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->label_cpf->setVisible(false);
    ui->label_estadocivil->setVisible(false);
    ui->cpf->setVisible(false);
    ui->estadocivil->setVisible(false);
    ui->label_dia->setVisible(false);
    ui->label_mes->setVisible(false);
    ui->label_ano->setVisible(false);
    ui->dia->setVisible(false);
    ui->mes->setVisible(false);
    ui->ano->setVisible(false);

    ui->label_cnpj->setVisible(true);
    ui->label_razaosocial->setVisible(true);
    ui->label_inscricaosocial->setVisible(true);
    ui->cnpj->setVisible(true);
    ui->razaosocial->setVisible(true);
    ui->inscricaosocial->setVisible(true);
}

void MainWindow::on_pushButton_adicionar_clicked()
{
    try {
           tp2::pessoa *contato = nullptr;
           QString nome = ui->nome->text();
           QString endereco = ui->localdemoradia->text();
           QString email = ui->email->text();
           QString documento = ui->cpf->text();
           if(ui->radioButton->isChecked()) {
               int dia = ui->dia->text().toInt();
               int mes = ui->mes->text().toInt();
               int ano = ui->ano->text().toInt();
               QString estado = ui->estadocivil->text();
               contato = new tp2::PessoaFisica(nome, endereco, email, documento,  dia, mes, ano, estado);
           }
           if(ui->radioButton_2->isChecked()) {
               QString cnpj = ui->cnpj->text();
               int inscricao = ui->inscricaosocial->text().toInt();
               QString razao = ui->razaosocial->text();
               contato = new tp2::PessoaJuridica(nome, endereco, email, cnpj, inscricao, razao);
           }
           agenda.pushPriority(contato);
           mostrarAgenda();
           limparCampos();
           QMessageBox::information(this,"Adicionado",contato->printf());
       } catch (QString erro) {
           QMessageBox::information(this,"ERRO",erro);
       }
}

void MainWindow::limparCampos() const
{
    ui->nome->clear();
    ui->localdemoradia->clear();
    ui->email->clear();
    ui->cpf->clear();
    ui->ano->clear();
    ui->mes->clear();
    ui->dia->clear();
    ui->inscricaosocial->clear();
    ui->razaosocial->clear();
    ui->estadocivil->clear();
}

void MainWindow::limparBusca() const
{
    ui->cpf->clear();
    ui->cnpj->clear();
    ui->nome->clear();
}

void MainWindow::mostrarAgenda()
{
    try {
        if(agenda.getSize() == 0) throw QString("Agenda Vazia");
        QString saida("");
        for(int i = 0; i < agenda.getSize(); i++) {
            saida += agenda[i]->printf() + ((i == agenda.getSize() - 1) ? "" : "\n--------------------------------------------------------------\n");
        }
        ui->textEdit_saida->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}


void MainWindow::on_pushButton_buscar_clicked()
{
    try {
            QString nome = ui->bNome->text();
            QString documento  = ui->bDocumento->text();
            QString saida("");
            if(!nome.isEmpty()) {
                if(!documento.isEmpty()) saida = agenda.buscarDuplo(nome, documento);
                else saida = agenda.buscarNome(nome);
            } else if(!documento.isEmpty()) {
                saida = agenda.buscarDocumento(documento);
            } else throw QString("Preencha o campo de busca");
            ui->textEdit_saida_2->setText(saida);
            QMessageBox::information(this,"Resultado da Busca:",saida);
            limparBusca();
        } catch (QString erro) {
            QMessageBox::information(this,"ERRO",erro);
        }
}

void MainWindow::on_pushButton_remover_clicked()
{
    try {
            QString nome = ui->bNome->text();
            QString documento  = ui->bDocumento->text();
            QString saida("");
            if(!nome.isEmpty()) {
                if(!documento.isEmpty()) saida = agenda.removerDuplo(nome, documento);
                else saida = agenda.removerNome(nome);
            } else if(!documento.isEmpty()) {
                saida = agenda.removerDocumento(documento);
            } else throw QString("Preencha pelo menos um campo de busca");
            ui->textEdit_saida->setText(saida);
            QMessageBox::information(this,"Removido:",saida);
            limparBusca();
            mostrarAgenda();
        } catch (QString erro) {
            QMessageBox::information(this,"ERRO",erro);
        }
}

void MainWindow::on_showList_clicked()
{
    try {
        if(agenda.getSize() == 0) throw QString("Agenda Vazia");
        QString saida("");
        for(int i = 0; i < agenda.getSize(); i++) {
            saida += agenda[i]->printf() + ((i == agenda.getSize() - 1) ? "" : "\n--------------------------------------------------------------\n");
        }
        ui->textEdit_saida->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
