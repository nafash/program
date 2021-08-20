#include "pessoajuridica.h"

namespace tp2
{
    PessoaJuridica::PessoaJuridica():
        CNPJ(0),
        razaoSocial("")
    {

    }

    void PessoaJuridica::setCNPJ(int CNPJ)
    {
        if(CNPJ<=0) throw QString ("CNPJ inválido");
        this->CNPJ = CNPJ;
    }

}
