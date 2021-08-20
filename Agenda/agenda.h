#ifndef AGENDA_H
#define AGENDA_H
#include <no.h>
#include <pessoafisica.h>
#include <pessoa.h>
#include <pessoajuridica.h>

namespace tp2
{
    class Agenda
    {
    private:
        No *pStart;
        No *pEnd;
        int size;
    public:
        Agenda();

        void pushStart(pessoa *value);
        void pushEnd(pessoa *value);
        void push(int position, pessoa *value);
        void pushPriority(pessoa *value);

        pessoa* popStart();
        pessoa* popEnd();
        pessoa* pop(int position);
        pessoa* pop(No *node);

        bool empty()const;

        pessoa* operator[](int value)const;

        QString buscarNome(QString value)const;
        QString removerNome(QString value);
        QString buscarDocumento(QString value)const;
        QString removerDocumento(QString value);
        QString buscarDuplo(QString nome, QString documento)const;
        QString removerDuplo(QString nome, QString documento);

        int getSize()const{return size;}
    };
}

#endif // AGENDA_H
