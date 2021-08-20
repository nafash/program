#include "monitor.h"

namespace tp2 {

    Monitor::Monitor():
        disciplina(""),
        cargaHoraria(0)
    {

    }

    Monitor::Monitor(QString nome, int matricula, QString curso, double salario, QString turno, QString disciplina, int rg, int cargaHoraria):
        Estudante(nome, curso, matricula),
        Funcionario(nome, turno, rg, salario),
        disciplina(disciplina),
        cargaHoraria(cargaHoraria)
    {

    }

    QString Monitor::printf()
    {
        QString saida;
        saida += "Disciplina: ";
        saida += getDisciplina();
        saida += "\n";
        saida += "Carga Horária: ";
        saida += QString::number(getCargaHoraria());
        saida += "\n";

        return saida;
    }
}
