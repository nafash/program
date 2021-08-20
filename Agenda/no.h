#ifndef NO_H
#define NO_H
#include <pessoa.h>

namespace tp2 {

    class No
    {
    private:
        pessoa *contato;
        No *nodenext;
        No *nodeback;
    public:
        No();
        No(pessoa *value);

        pessoa* getValue()const{return contato;}
        void setValue(pessoa *contato){this->contato = contato;}

        No *getNodeNext()const{return nodenext;}
        void setNodeNext(No *value){nodenext = value;}

        No *getNodeBack()const{return nodeback;}
        void setNodeBack(No *value){nodeback = value;}
    };
}

#endif // NO_H
