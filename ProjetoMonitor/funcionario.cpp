#include "funcionario.h"

namespace tp2 {

    Funcionario::Funcionario():
        nome(""),
        turno(""),
        rg(0),
        salario(0)
    {

    }

    Funcionario::Funcionario(QString nome, QString turno, int rg, double salario):
        nome(nome),
        turno(turno),
        rg(rg),
        salario(salario)
    {

    }

    QString Funcionario::printf()
    {
        QString saida;
        saida += "Nome: ";
        saida += getNome();
        saida += "\n";
        saida += "Turno: ";
        saida += getTurno();
        saida += "\n";
        saida += "RG: ";
        saida += QString::number(getRg());
        saida += "\n";
        saida += "Salário: ";
        saida += QString::number(getSalario());
        saida += "\n";

        return saida;
    }
}


