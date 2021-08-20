#ifndef LLDEC_H
#define LLDEC_H
#include <no.h>
#include <QString>

namespace wictor {
template <class type>
class LDEC
{
private:
    no<type>* pBegin;
    no<type>* pEnd;
    int size;
public:
    LDEC();
    ~LDEC();

    int getSize()const{return size;}
    bool empty()const{return size == 0;}

    void pushFront(type valor);
    type popFront();

    void pushBack(type valor);
    type popBack();

    void insert(type value, int position);
    type erase(int posicao);

    void priorityInsert(type dado);

    type operator[](int posicao)const;
};

template <class type>
LDEC<type>::LDEC():
    pBegin(0),
    pEnd(0),
    size(0)
{}

template <class type>
LDEC<type>::~LDEC(){
    while(!empty()){
        popFront();
    }
}

template <class type>
void LDEC<type>::pushFront(type valor){
    try{
        no<type>* pAux = new no<type>(valor);
        if(empty()){
            pAux->setBack(pAux);
            pAux->setNext(pAux);
            pBegin = pAux;
            pEnd = pAux;
        }
        else{
            pAux->setBack(pEnd);
            pAux->setNext(pBegin);
            pEnd->setNext(pAux);
            pBegin->setBack(pAux);
            pBegin = pAux;
        }
        size++;
    }catch(std::bad_alloc&){
        throw QString("Memoria insuficiente");
    }
}

template <class type>
type LDEC<type>::popFront(){
    if(empty()) throw QString ("A lista está vazia.");
    type valor;
    if(size == 1){
        valor = pBegin->getValue();
        delete pBegin;
        pBegin = pEnd = 0;
        size = 0;
    }
    else {
        no<type>* pAux = pBegin;
        pBegin = pBegin->getNext();
        pBegin->setBack(pEnd);
        pEnd->setNext(pBegin);
        valor = pAux->getValue();
        size--;
        delete pAux;
    }
    return valor;
}

template <class type>
void LDEC<type>::pushBack(type valor){
    try{
        no<type>* pAux = new no<type>(valor);
        if(empty()){
            pAux->setBack(pAux);
            pAux->setNext(pAux);
            pBegin = pAux;
            pEnd = pAux;
        }
        else{
            pAux->setBack(pEnd);
            pAux->setNext(pBegin);
            pEnd->setNext(pAux);
            pBegin->setBack(pAux);
            pEnd = pAux;
        }
        size++;
    }catch(std::bad_alloc&){
        throw QString("Memoria insuficiente");
    }
}

template <class type>
type LDEC<type>::popBack(){
    if(empty()) throw QString ("A lista está vazia.");
    type valor;
    if(size == 1){
        valor = pEnd->getValue();
        delete pEnd;
        pBegin = pEnd = 0;
        size = 0;
    }
    else {
        no<type>* pAux = pEnd;
        pEnd = pEnd->getBack();
        pBegin->setBack(pEnd);
        pEnd->setNext(pBegin);
        valor = pAux->getValue();
        size--;
        delete pAux;
    }
    return valor;
}


template <class type>
void LDEC<type>::insert(type value, int position) {
    try {
        if(position < 0 || position > size) throw QString("Posição inválida");
        if(position == 0) return pushFront(value);
        if(position == size) return pushBack(value);
        no<type> *No = new no<type>(value);
        no<type> *aux = (position > size / 2) ? pEnd : pBegin;
        int p = (position > size / 2) ? size - position : position - 1;
        for(int i = 0; i < p; i++) aux = (position > size / 2) ? aux->getBack() : aux->getNext();
        No->setNext(aux->getNext());
        No->setBack(aux);
        aux->getNext()->setBack(No);
        aux->setNext(No);
        size++;
    } catch (std::bad_alloc&) {
        throw QString("Memória insuficiente");
    }
}

template <class type>
type LDEC<type>::erase(int position) {
    try {
        if(size == 0) throw QString ("Lista vazia");
        if(position < 0 || position >= size) throw QString("Posição inválida");
        if(position == 0) return popFront();
        if(position == size-1) return popBack();
        no<type> *aux = (position > size / 2) ? pEnd : pBegin;
        int p = (position > size / 2) ? size - position - 1 : position;
        for(int i = 0; i < p; i++) aux = (position > size / 2) ? aux->getBack() : aux->getNext();
        type value = aux->getValue();
        aux->getNext()->setBack(aux->getBack());
        aux->getBack()->setNext(aux->getNext());
        delete aux;
        size--;
        return value;
    } catch (std::bad_alloc&) {
        throw QString("Memória insuficiente");
    }
}

template <class type>
void LDEC<type>::priorityInsert(type dado){
    try {
        if(size == 0) return pushFront(dado);
        if(dado <= pBegin->getValue()) return pushFront(dado);
        if(dado >= pEnd->getValue()) return pushBack(dado);
        no<type> *aux= pBegin;
        no<type> *No= new no<type>(dado);
        while(aux->getValue() < dado)aux = aux->getNext();
        No->setNext(aux);
        No->setBack(aux->getBack());
        aux->getBack()->setNext(No);
        aux->setBack(No);
        size++;

    } catch (std::bad_alloc&) {
        throw QString("Memória insuficiente");
    }
}

template <class type>
type LDEC<type>::operator[](int posicao) const{
    if(posicao < 0) throw QString("A posição não pode ser negativa");
    if(posicao >= size) throw QString("Posição invalida");
    if(empty()) throw QString("A lista está vazia");

    if(posicao == 0) return pBegin->getValue();
    if(posicao == size-1) return pEnd->getValue();
    no<type>* pAux;
    type valor;
    if(posicao > size / 2){
        pAux = pEnd;
        for(int i = 0;i < size - posicao -1;i++){
            pAux = pAux->getBack();
        }
    }
    else {
        pAux = pBegin;
        for(int i = 0;i < posicao;i++){
            pAux = pAux->getNext();
        }
    }
    valor = pAux->getValue();
    return valor;
}
}
#endif // LLDE_H
