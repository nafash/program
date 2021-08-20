#ifndef LL_DUPLAMENTE_ENCADEADA_H
#define LL_DUPLAMENTE_ENCADEADA_H
#include <nodefisica.h>
#include <QString>
#include <QMessageBox>
#include <QInputDialog>

namespace tp2 {

    class LL_Duplamente_Encadeada
    {
    private:
        Node* pStart;
        Node* pEnd;
        int quantidade;
    public:
        LL_Duplamente_Encadeada();
        ~LL_Duplamente_Encadeada(){while(!empty()) popBegin();}

        bool empty()const;

        void pushBegin(QString nome,QString localDeMoradia,QString email,QString estadoCivil,int CPF,int dia,int mes,int ano);
        void pushEnd(QString nome,QString localDeMoradia,QString email,QString estadoCivil,int CPF,int dia,int mes,int ano);

        int popBegin();
        int popEnd();

        int operator[](int posicao)const;
    };
}

#endif // LL_DUPLAMENTE_ENCADEADA_H
