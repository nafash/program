#ifndef MONITOR_H
#define MONITOR_H
#include <estudante.h>
#include <funcionario.h>

namespace tp2 {

    class Monitor: public Estudante, public Funcionario
    {
    private:
        QString disciplina;
        int cargaHoraria;
    public:
        Monitor();
        Monitor(QString nome, int matricula, QString curso, double salario, QString turno, QString disciplina, int rg, int cargaHoraria);

        void setDisciplina(QString disciplina){this->disciplina = disciplina;}
        QString getDisciplina(){return disciplina;}

        void setCargaHoraria(int cargaHoraria){this->cargaHoraria = cargaHoraria;}
        int getCargaHoraria(){return cargaHoraria;}

        QString printf();
    };
}

#endif // MONITOR_H
