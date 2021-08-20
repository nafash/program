#ifndef NODE_H
#define NODE_H
#include <QString>
#include <pessoafisica.h>

namespace tp2 {

    class Node: public PessoaFisica
    {
    private:
        QString nome, localDeMoradia, email, estadoCivil;
        int CPF, dia, mes, ano;
        Node* pAnterior;
        Node* pProximo;
    public:
        Node();
        Node(QString nome,QString localDeMoradia,QString email,QString estadoCivil,int CPF,int dia,int mes,int ano);

        void set_pAnterior(Node* pAnterior){this->pAnterior = pAnterior;}
        Node* get_pAnterior(){return pAnterior;}

        void set_pProximo(Node* pProximo){this->pProximo = pProximo;}
        Node* get_pProximo()const{return pProximo;}

    };
}

#endif // NODE_H
