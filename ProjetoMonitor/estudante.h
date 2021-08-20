#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include <QString>

namespace tp2
{
    class Estudante
    {
    private:
        QString nome, curso;
        int matricula;
    public:
        Estudante();
        Estudante(QString nome, QString curso, int matricula);

        void setNome(QString nome){this->nome = nome;}
        QString getNome()const{return nome;}

        void setCurso(QString curso){this->curso = curso;}
        QString getCurso()const{return curso;}

        void setMatricula(int matricula){this->matricula = matricula;}
        int getMatricula()const{return matricula;}

        QString printf();
    };
}

#endif // ESTUDANTE_H
