#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <QString>
#include <pessoa.h>

namespace tp2
{
    class PessoaJuridica: public pessoa
    {
    private:
        int inscricaoSocial;
        QString razaoSocial,  CNPJ;
    public:
        PessoaJuridica();
        PessoaJuridica(QString nome,QString endereco,QString email,QString CNPJ, int inscricaoSocial, QString razaoSocial);

        int getInscricaoSocial()const{return inscricaoSocial;}
        void setInscricaoSocial(int inscricaoSocial);

        QString getRazaoSocial()const{return razaoSocial;}
        void setRazaoSocial(const QString razaoSocial){
            this->razaoSocial = razaoSocial;
        }

        virtual void setDocumento(QString documento) override;
        virtual QString getDocumento()const override{return CNPJ;}

        QString printf();
    };
}

#endif // PESSOAJURIDICA_H
