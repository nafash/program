#include "pessoa.h"

namespace tp2 {

    pessoa::pessoa():
        nome(""),
        localDeMoradia(""),
        email(""),
        dia(0),
        mes(0),
        ano(0)
    {

    }

    pessoa::pessoa(QString nome, QString localDeMoradia, QString email, int dia, int mes, int ano)
    {
        setNome(nome);
        setLocalDeMoradia(localDeMoradia);
        setEmail(email);
        setDia(dia);
        setMes(mes);
        setAno(ano);
    }

    void pessoa::setDia(int dia)
    {
        if(dia<1||dia>31) throw QString("Dia inválido");
        this->dia = dia;
    }

    void pessoa::setMes(int mes)
    {
        if(mes<1||mes>12) throw QString("Mês inválido");
        this->mes = mes;
    }

    void pessoa::setAno(int ano)
    {
        if(ano<1800) throw QString("Ano inválido");
        this->ano = ano;
    }

    QString pessoa::dataDeNascimento()
    {
        QString saida = "";
        saida += QString::number(getDia());
        saida += "/";
        saida += QString::number(getMes());
        saida += "/";
        saida += QString::number(getAno());

        return saida;
    }

    void pessoa::setDocumento(QString documento)
    {
        if(documento.size()<0)throw QString("Documento inválido");
        this->documento = documento;
    }

    QString pessoa::printf()
    {
        QString saida = "";
        saida = "Nome: ";
        saida += getNome();
        saida += "\n";
        saida += "Endereço: ";
        saida += getLocalDeMoradia();
        saida += "\n";
        saida += "E-mail: ";
        saida += getEmail();
        saida += "\n";
        saida += "Data de nascimento: ";
        saida += dataDeNascimento();
        saida += "\n";

        return saida;
    }

}
