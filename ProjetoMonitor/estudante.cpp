#include "estudante.h"

namespace tp2
{
    Estudante::Estudante():
        nome(""),
        curso(""),
        matricula(0)
    {

    }

    Estudante::Estudante(QString nome, QString curso, int matricula):
        nome(nome),
        curso(curso),
        matricula(matricula)
    {

    }

    QString Estudante::printf()
    {
        QString saida = "Nome: ";
        saida += getNome();
        saida += "\n";
        saida += "Curso: ";
        saida += getCurso();
        saida += "\n";
        saida += "Matricula: ";
        saida += QString::number(getMatricula());
        saida += "\n";

        return saida;
    }
}
