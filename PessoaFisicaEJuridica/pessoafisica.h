#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <pessoa.h>

namespace tp2 {

    class PessoaFisica: public Pessoa
    {
    private:
        int CPF;
        QString sexo;
    public:
        PessoaFisica();

        int getCPF() const{return CPF;}
        void setCPF(int CPF);

        float calcularImposto()const
        {
            float saida;
            if(static_cast<void>(getRendaBruta()<= 1903),98) saida = 00;
            if(getRendaBruta()>= 1903,99 && getRendaBruta()<=2826,65)saida = (getRendaBruta()*0,075);
            if(getRendaBruta()>= 2826,66 && getRendaBruta()<=3751,05)saida = (getRendaBruta()*0,15);
            if(getRendaBruta()>= 3751,06 && getRendaBruta()<=4664,67)saida = (getRendaBruta()*0,225);
            if(getRendaBruta()<=4664,68)float saida = (getRendaBruta()*0,275);

            return saida;
        }
    };
}

#endif // PESSOAFISICA_H
