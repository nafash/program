#include "ll_duplamente_encadeada_fisica.h"

namespace tp2
{
    LL_Duplamente_Encadeada::LL_Duplamente_Encadeada():
        pStart(nullptr),
        pEnd(nullptr),
        quantidade(0)
    {

    }

    bool LL_Duplamente_Encadeada::empty()const
    {
        if(quantidade == 0)return true;
        else return false;
    }

    void LL_Duplamente_Encadeada::pushBegin(QString nome,QString localDeMoradia,QString email,QString estadoCivil,int CPF,int dia,int mes,int ano)
    {
        try {
           Node* pAux = new Node(nome, localDeMoradia, email, estadoCivil, CPF, dia, mes, ano);
           if(empty()){
               pStart = pEnd = pAux;
               quantidade++;
           }
           else {
               pAux->set_pProximo(pStart);
               pStart->set_pAnterior(pAux);
               pStart = pAux;
               quantidade++;
           }
        } catch (std::bad_alloc) {
            throw QString("Memória insuficiente");
        }
    }
    void LL_Duplamente_Encadeada::pushEnd(QString nome,QString localDeMoradia,QString email,QString estadoCivil,int CPF,int dia,int mes,int ano)
    {
        try {
            Node* pAux = new Node(nome, localDeMoradia, email, estadoCivil, CPF, dia, mes, ano);
            if(empty()){
                pStart = pEnd = pAux;
                quantidade++;
            }
            else {
                pEnd->set_pProximo(pAux);
                pAux->set_pAnterior(pEnd);
                pEnd = pAux;
                quantidade++;
            }
        } catch (std::bad_alloc) {
            throw QString("Memória insuficiente");
        }
    }

    int LL_Duplamente_Encadeada::popBegin()
    {
        if(empty())throw QString("Lista vazia");
        if(quantidade == 1){
            int value = pStart->getDado();
            delete pStart;
            pStart = pEnd = nullptr;
            quantidade = 0;
            return value;
        }
        Node* pAux = pStart;
        pStart = pStart->get_pProximo();
        pStart->set_pAnterior(nullptr);
        quantidade--;

        int valor = pAux->getDado();
        delete pAux;
        return valor;
    }

    int LL_Duplamente_Encadeada::popEnd()
    {
        if(empty())throw QString("Lista vazia");
        Node* pAux;
        if(quantidade == 1){
            pAux = pEnd;
            pStart = pEnd = nullptr;
            quantidade = 0;
            int value = pAux->getDado();
            delete pAux;
            return value;
        }
        pAux = pEnd;
        pEnd = pEnd->get_pAnterior();
        pEnd->set_pProximo(nullptr);
        quantidade--;

        int valor = pAux->getDado();
        delete pAux;
        return valor;
    }

    int LL_Duplamente_Encadeada::operator[](int posicao) const
    {
        if(posicao < 0) throw QString("A posição não pode ser negativa");
        if(posicao >= quantidade) throw QString("Posição invalida");
        if(empty()) throw QString("A lista está vazia");

        if(posicao == 0) return pStart->getDado();
        if(posicao == quantidade-1) return pEnd->getDado();
        Node* pAux = pStart;
        int valor;
        for(int i = 0;i < posicao;i++)
            pAux = pAux->get_pProximo();
            valor = pAux->getDado();

        return valor;
    }
}
