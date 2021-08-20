#ifndef TRABALHADOR_H
#define TRABALHADOR_H
#include <pessoa.h>

namespace tp2
{
    class Trabalhador: public Pessoa
    {
    private:
        QString function, departamento;
        double salario;
    public:
        Trabalhador();

        QString getFunction()const{return function;}
        void setFunction(QString function){this->function = function;}

        QString getDepartamento()const{return departamento;}
        void setDepartamento(QString departamento){this->departamento = departamento;}

        double getSalario()const{return salario;}
        void setSalario(double salario){
            if(salario<0) throw ("Salário não pode ser negativo");
            this->salario = salario;
        }
    };
}

#endif // TRABALHADOR_H
