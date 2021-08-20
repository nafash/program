#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include <pessoa.h>

namespace tp2
{
    class Estudante: public Pessoa
    {
    private:
        int matricula, campus;
        QString curso;

    public:
        Estudante();
        int getMatricula()const{return matricula;}
        void setMatricula(int matricula){this->matricula = matricula;}

        int getCampus()const{return campus;}
        void setCampus(int campus){this->campus = campus;}

        QString getCurso()const{return curso;}
        void setCurso(QString curso){this->curso = curso;}

    };
}

#endif // ESTUDANTE_H
