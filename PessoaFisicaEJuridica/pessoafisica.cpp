#include "pessoafisica.h"

namespace tp2
{
    PessoaFisica::PessoaFisica():
        CPF(0),
        sexo("")
    {

    }


    void PessoaFisica::setCPF(int CPF)
    {
        if(CPF<=0) throw QString("CPF inválido");
        this->CPF = CPF;
    }
}
