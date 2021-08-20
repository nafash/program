#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <QString>

namespace tp2
{
    class Funcionario
    {
    private:
        QString nome, turno;
        int rg;
        double salario;
    public:
        Funcionario();
        Funcionario(QString nome, QString turno, int rg, double salario);

        void setNome(QString nome){this->nome = nome;}
        QString getNome()const{return nome;}

        void setTurno(QString turno){this->turno = turno;}
        QString getTurno()const{return turno;}

        void setRg(int rg){this->rg = rg;}
        int getRg()const{return rg;}

        void setSalario(double salario){this->salario = salario;}
        double getSalario()const{return salario;}

        QString printf();
    };
}

#endif // FUNCIONARIO_H
