#include "agenda.h"

namespace tp2
{

    Agenda::Agenda():
        pStart(nullptr),
        pEnd(nullptr),
        size(0)
    {

    }

    void Agenda::pushStart(pessoa *value) {
        try {
            No *aux = new No(value);
            if(empty()) pEnd = aux;
            else pStart->setNodeBack(aux);
            aux->setNodeNext(pStart);
            pStart = aux;
            size++;
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    void Agenda::pushEnd(pessoa *value) {
        try {
            No *aux = new No(value);
            if(empty()) pStart = aux;
            else pEnd->setNodeNext(aux);
            aux->setNodeBack(pEnd);
            pEnd = aux;
            size++;
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    void Agenda::push(int position, pessoa *value) {
        try {
            if(position < 0 || position > size) throw QString("Posição inválida");
            if(position == 0) return pushStart(value);
            if(position == size) return pushEnd(value);
            No *no = new No(value);
            No *aux = (position > size / 2) ? pEnd : pStart;
            int p = (position > size / 2) ? size - position : position - 1;
            for(int i = 0; i < p; i++) aux = (position > size / 2) ? aux->getNodeBack() : aux->getNodeNext();
            no->setNodeNext(aux->getNodeNext());
            no->setNodeBack(aux);
            aux->getNodeNext()->setNodeBack(no);
            aux->setNodeNext(no);
            size++;
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    void Agenda::pushPriority(pessoa *value)
    {
        try {
            if(size == 0) return pushStart(value);
            if(value->getDocumento() < pStart->getValue()->getDocumento()) return pushStart(value);
            if(value->getDocumento() > pEnd->getValue()->getDocumento()) return pushEnd(value);
            No *aux = pStart;
            No *no = new No(value);
            while(aux->getValue()->getDocumento() != value->getDocumento()) aux = aux->getNodeNext();
            while(aux->getValue()->getDocumento() == value->getDocumento() && aux->getValue()->getNome() < value->getNome() && aux->getNodeNext()) aux = aux->getNodeNext();
            if(aux->getValue()->getNome() == value->getNome() && aux->getValue()->getDocumento() == value->getDocumento())
                if(aux == pStart) return pushStart(value);
            if(aux == pEnd) return pushEnd(value);
            no->setNodeNext(aux);
            no->setNodeBack(aux->getNodeBack());
            aux->getNodeBack()->setNodeNext(no);
            aux->setNodeBack(no);
            size++;
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    pessoa* Agenda::popStart() {
        try {
            if(empty()) throw QString("Agenda Vazia");
            pessoa *value = pStart->getValue();
            size--;
            if(empty()) {
                delete pStart;
                pStart = pEnd = nullptr;
            } else {
                pStart->getNodeNext()->setNodeBack(nullptr);
                No *aux = pStart->getNodeNext();
                delete pStart;
                pStart = aux;
            }
            return value;
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    pessoa* Agenda::popEnd() {
        try {
            if(empty()) throw QString("Agenda Vazia");
            pessoa *value = pEnd->getValue();
            size--;
            if(empty()) {
                delete pEnd;
                pStart = pEnd = nullptr;
            } else {
                pEnd->getNodeBack()->setNodeNext(nullptr);
                No *aux = pEnd->getNodeBack();
                delete pEnd;
                pEnd = aux;
            }
            return value;
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    pessoa* Agenda::pop(int position) {
        try {
            if(position < 0 || position >= size) throw QString("Posição inválida");
            if(position == 0) return popStart();
            if(position == size-1) return popEnd();
            No *aux = (position > size / 2) ? pEnd : pStart;
            int p = (position > size / 2) ? size - position - 1 : position;
            for(int i = 0; i < p; i++) aux = (position > size / 2) ? aux->getNodeBack() : aux->getNodeNext();
            pessoa *value = aux->getValue();
            aux->getNodeNext()->setNodeBack(aux->getNodeBack());
            aux->getNodeBack()->setNodeNext(aux->getNodeNext());
            delete aux;
            size--;
            return value;
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    pessoa *Agenda::pop(No *node)
    {
        try {
            if(node == pStart) return popStart();
            if(node == pEnd) return popEnd();
            pessoa *value = node->getValue();
            node->getNodeNext()->setNodeBack(node->getNodeBack());
            node->getNodeBack()->setNodeNext(node->getNodeNext());
            size--;
            return value;
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    bool Agenda::empty() const
    {
        if(size == 0)return true;
        else return false;
    }

    pessoa* Agenda::operator [](int value) const {
        try {
            if(value >= size || value < 0 || empty()) throw QString("Posição inválida");
            if(value == 0) return pStart->getValue();
            if(value == size -1) return pEnd->getValue();
            No *aux = (value > size / 2) ? pEnd : pStart;
            int p = (value > size / 2) ? size - value - 1 : value;
            for(int i = 0; i < p; i++) aux = (value > size / 2) ? aux->getNodeBack() : aux->getNodeNext();
            return aux->getValue();
        } catch (std::bad_alloc&) {
            throw QString("Nó não criado. Memória insuficiente");
        }
    }

    QString Agenda::buscarNome(QString value) const
    {
        QString saida("");
        No *aux = pStart;
        while (aux) {
            if(aux->getValue()->getNome() == value) {
                if(!saida.isEmpty()) saida += "\n--------------------------------------------------------------\n";
                saida += aux->getValue()->printf();
            }
            aux = aux->getNodeNext();
        }
        if(saida.isEmpty()) throw QString("Nenhum resultado encontrado");
        return saida;
    }

    QString Agenda::removerNome(QString value)
    {
        QString saida("");
        No *aux = pStart;
        while (aux) {
            if(aux->getValue()->getNome() == value) {
                if(!saida.isEmpty()) saida += "\n--------------------------------------------------------------\n";
                saida += pop(aux)->printf();
            }
            aux = aux->getNodeNext();
        }
        if(saida.isEmpty()) throw QString("Nenhum resultado encontrado");
        return saida;
    }

    QString Agenda::buscarDocumento(QString value) const
    {
        QString saida("");
        No *aux = pStart;
        while (aux) {
            if(aux->getValue()->getDocumento() == value) {
                if(!saida.isEmpty()) saida += "\n--------------------------------------------------------------\n";
                saida += aux->getValue()->printf();
            }
            aux = aux->getNodeNext();
        }
        if(saida.isEmpty()) throw QString("Nenhum resultado encontrado");
        return saida;
    }

    QString Agenda::removerDocumento(QString value)
    {
        QString saida("");
        No *aux = pStart;
        while (aux) {
            if(aux->getValue()->getDocumento() == value) {
                if(!saida.isEmpty()) saida += "\n--------------------------------------------------------------\n";
                saida += pop(aux)->printf();
            }
            aux = aux->getNodeNext();
        }
        if(saida.isEmpty()) throw QString("Nenhum resultado encontrado");
        return saida;
    }

    QString Agenda::buscarDuplo(QString nome, QString documento) const
    {
        QString saida("");
        No *aux = pStart;
        while (aux) {
            if(aux->getValue()->getNome() == nome && aux->getValue()->getDocumento() == documento) {
                if(!saida.isEmpty()) saida += "\n--------------------------------------------------------------\n";
                saida += aux->getValue()->printf();
            }
            aux = aux->getNodeNext();
        }
        if(saida.isEmpty()) throw QString("Nenhum resultado encontrado");
        return saida;
    }

    QString Agenda::removerDuplo(QString nome, QString documento)
    {
        QString saida("");
        No *aux = pStart;
        while (aux) {
            if(aux->getValue()->getNome() == nome && aux->getValue()->getDocumento() == documento) {
                if(!saida.isEmpty()) saida += "\n--------------------------------------------------------------\n";
                saida += pop(aux)->printf();
            }
            aux = aux->getNodeNext();
        }
        if(saida.isEmpty()) throw QString("Nenhum resultado encontrado");
        return saida;
    }
}
