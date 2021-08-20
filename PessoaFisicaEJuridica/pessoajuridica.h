#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <pessoa.h>

namespace tp2
{

    class PessoaJuridica: public Pessoa
    {
    private:
        int CNPJ;
        QString razaoSocial;
    public:
        PessoaJuridica();
        int getCNPJ()const{return CNPJ;}
        void setCNPJ(int CNPJ);

        QString getRazaoSocial()const{return razaoSocial;}
        void setRazaoSocial(QString razaoSocial){
            this->razaoSocial = razaoSocial;
        }

        float calcularImposto()const{
            return getRendaBruta()*12*0.08;
        }
    };
}

#endif // PESSOAJURIDICA_H
