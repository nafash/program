#include "nodefisica.h"

namespace tp2
{
    Node::Node():
        nome(""),
        localDeMoradia(""),
        email(""),
        estadoCivil(""),
        CPF(0),
        dia(0),
        mes(0),
        ano(0),
        pAnterior(nullptr),
        pProximo(nullptr)
    {

    }

    tp2::Node::Node(QString nome,QString localDeMoradia,QString email,QString estadoCivil,int CPF,int dia,int mes,int ano):
        nome(nome),
        localDeMoradia(localDeMoradia),
        email(email),
        estadoCivil(estadoCivil),
        CPF(CPF),
        dia(dia),
        mes(mes),
        ano(ano),
        pAnterior(nullptr),
        pProximo(nullptr)
    {

    }
}
