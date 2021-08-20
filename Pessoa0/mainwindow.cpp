#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->grau->setDisabled(true);
    ui->curso->setDisabled(true);
    ui->campus->setDisabled(true);
    ui->salario->setDisabled(true);
    ui->function->setDisabled(true);
    ui->textEdit->setReadOnly(true);
    ui->conclusao->setDisabled(true);
    ui->matricula->setDisabled(true);
    ui->departamento->setDisabled(true);
    ui->diploma->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_estudante_clicked()
{
    try {
        ui->departamento->clear();
        ui->salario->clear();
        ui->function->clear();

        ui->conclusao->clear();
        ui->diploma->clear();
        ui->grau->clear();

        ui->curso->setDisabled(false);
        ui->campus->setDisabled(false);
        ui->matricula->setDisabled(false);

        ui->departamento->setDisabled(true);
        ui->salario->setDisabled(true);
        ui->function->setDisabled(true);

        ui->conclusao->setDisabled(true);
        ui->diploma->setDisabled(true);
        ui->grau->setDisabled(true);

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_radioButton_trabalhador_clicked()
{
    try {
        ui->conclusao->clear();
        ui->diploma->clear();
        ui->grau->clear();

        ui->curso->clear();
        ui->campus->clear();
        ui->matricula->clear();

        ui->curso->setDisabled(true);
        ui->campus->setDisabled(true);
        ui->matricula->setDisabled(true);

        ui->departamento->setDisabled(false);
        ui->salario->setDisabled(false);
        ui->function->setDisabled(false);

        ui->conclusao->setDisabled(true);
        ui->diploma->setDisabled(true);
        ui->grau->setDisabled(true);

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_radioButton_graduado_clicked()
{
    try {
        ui->curso->clear();
        ui->campus->clear();
        ui->matricula->clear();

        ui->departamento->clear();
        ui->salario->clear();
        ui->function->clear();

        ui->curso->setDisabled(true);
        ui->campus->setDisabled(true);
        ui->matricula->setDisabled(true);

        ui->departamento->setDisabled(true);
        ui->salario->setDisabled(true);
        ui->function->setDisabled(true);

        ui->conclusao->setDisabled(false);
        ui->diploma->setDisabled(false);
        ui->grau->setDisabled(false);

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void MainWindow::on_Resultado_clicked()
{
    QString nome, moradia, email;
    int telefone;

    nome = ui->nome->text();

    moradia = ui->moradia->text();

    telefone = ui->telefone->text().toInt();

    email = ui->email->text();

    if(ui->radioButton_estudante->isChecked())
    {
        estudante.setNome(nome);

        estudante.setLocalDeMoradia(moradia);

        estudante.setTelefone(telefone);

        estudante.setEmail(email);

        int matricula = ui->matricula->text().toInt();
        estudante.setMatricula(matricula);

        QString curso = ui->curso->text();
        estudante.setCurso(curso);

        int campus = ui->campus->text().toInt();
        estudante.setCampus(campus);

        QString saida = "Nome: ";
        saida = estudante.getNome();
        saida +="\n";
        saida += "Telefone: ";
        saida += QString::number(estudante.getTelefone());
        saida +="\n";
        saida += "Endereço: ";
        saida += estudante.getLocalDeMoradia();
        saida +="\n";
        saida += "E-mail: ";
        saida += estudante.getEmail();
        saida +="\n";
        saida += "Curso: ";
        saida += estudante.getCurso();
        saida +="\n";
        saida += "Campus: ";
        saida += QString::number(estudante.getCampus());
        saida +="\n";
        saida += "Matricula: ";
        saida += QString::number(estudante.getMatricula());

        ui->textEdit->setText(saida);
    }

    if(ui->radioButton_trabalhador->isChecked())
    {
        QString nome, moradia, email;
        int telefone = 0;

        trabalhador.setNome(nome);

        trabalhador.setLocalDeMoradia(moradia);

        trabalhador.setTelefone(telefone);

        trabalhador.setEmail(email);

        double salario = ui->salario->text().toDouble();
        trabalhador.setSalario(salario);

        QString departamento = ui->departamento->text();
        trabalhador.setDepartamento(departamento);

        QString function = ui->function->text();
        trabalhador.setFunction(function);

        QString saida = "Nome: ";
        saida += trabalhador.getNome();
        saida +="\n";
        saida += "Telefone: ";
        saida += QString::number(trabalhador.getTelefone());
        saida +="\n";
        saida += "Endereço: ";
        saida += trabalhador.getLocalDeMoradia();
        saida +="\n";
        saida += "E-mail: ";
        saida += trabalhador.getEmail();
        saida +="\n";
        saida += "Departamento: ";
        saida += trabalhador.getDepartamento();
        saida +="\n";
        saida += "Função: ";
        saida += trabalhador.getFunction();
        saida +="\n";
        saida += "Salário: ";
        saida += QString::number(trabalhador.getSalario());

        ui->textEdit->setText(saida);
    }

    if(ui->radioButton_graduado->isChecked()){
        graduado.setNome(nome);

        graduado.setLocalDeMoradia(moradia);

        graduado.setTelefone(telefone);

        graduado.setEmail(email);

        int anoDeConclusao = ui->conclusao->text().toInt();
        graduado.setAnoDeConclusao(anoDeConclusao);

        int numeroDoDiploma = ui->diploma->text().toInt();
        graduado.setNumeroDoDiploma(numeroDoDiploma);

        int anoDaColacaoDeGrau = ui->grau->text().toInt();
        graduado.setAnoDaColacaoDeGrau(anoDaColacaoDeGrau);


        QString saida = graduado.getNome();
        saida +="\n";
        saida += QString::number(graduado.getTelefone());
        saida +="\n";
        saida += graduado.getLocalDeMoradia();
        saida +="\n";
        saida += graduado.getEmail();
        saida +="\n";
        saida += QString::number(graduado.getAnoDeConclusao());
        saida +="\n";
        saida += QString::number(graduado.getNumeroDoDiploma());
        saida +="\n";
        saida += QString::number(graduado.getAnoDaColacaoDeGrau());

        ui->textEdit->setText(saida);
    }
}

void MainWindow::on_Clear_clicked()
{
    ui->nome->clear();
    ui->telefone->clear();
    ui->email->clear();
    ui->moradia->clear();

    ui->conclusao->clear();
    ui->matricula->clear();
    ui->departamento->clear();
    ui->diploma->clear();

    ui->grau->clear();
    ui->curso->clear();
    ui->campus->clear();
    ui->salario->clear();
    ui->function->clear();

    ui->departamento->setDisabled(true);
    ui->salario->setDisabled(true);
    ui->function->setDisabled(true);

    ui->curso->setDisabled(true);
    ui->campus->setDisabled(true);
    ui->matricula->setDisabled(true);


    ui->conclusao->setDisabled(true);
    ui->diploma->setDisabled(true);
    ui->grau->setDisabled(true);
}




