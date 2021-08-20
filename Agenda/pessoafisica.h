#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <QString>
#include <pessoa.h>

namespace tp2
{
    class PessoaFisica: public pessoa
    {
    private:
        QString estadoCivil;
        QString CPF;
    public:
        PessoaFisica();
        PessoaFisica(QString nome,QString endereco,QString  email,QString documento,int  dia,int mes,int ano,QString estadoCivil);

        QString getEstadoCivil()const{return estadoCivil;}
        void setEstadoCivil(const QString estadoCivil){this->estadoCivil = estadoCivil;}

        virtual void setDocumento(QString documento)override;
        virtual QString getDocumento()const override{return CPF;}

        QString printf() override;
    };
}
#endif // PESSOAFISICA_H
