#include "pessoajuridica.h"

namespace tp2 {

    PessoaJuridica::PessoaJuridica():
        inscricaoSocial(0),
        razaoSocial(""),
        CNPJ("")
    {

    }

    PessoaJuridica::PessoaJuridica(QString nome, QString endereco, QString email, QString CNPJ, int inscricaoSocial, QString razaoSocial):
        inscricaoSocial(inscricaoSocial),
        razaoSocial(razaoSocial),
        CNPJ(CNPJ)
    {
        setNome(nome);
        setLocalDeMoradia(endereco);
        setEmail(email);
    }

    void PessoaJuridica::setInscricaoSocial(int inscricaoSocial)
    {
        if(inscricaoSocial <= 0) throw QString("Inscrição social inválida");
        this->inscricaoSocial = inscricaoSocial;
    }

    void PessoaJuridica::setDocumento(QString documento)
    {
        if(documento.size()<0)throw QString("CNPJ inválido");
        CNPJ = documento;
    }

    QString PessoaJuridica::printf()
    {
        QString saida = "";
        saida += pessoa::printf();
        saida += "CNPJ: ";
        saida += getDocumento();
        saida += "\n";
        saida += "CNPJ: ";
        saida += QString::number(getInscricaoSocial());
        saida += "\n";
        saida += "Razão Social: ";
        saida += getRazaoSocial();
        saida += "\n";

        return saida;
    }
}
