#ifndef PRODUTOPERSISTENCIA_H
#define PRODUTOPERSISTENCIA_H
#include "pedido.h"
#include <QStringList>
#include <fstream>

namespace wictor{
class produtoPersistencia
{
public:
    produtoPersistencia();
    static void lerArquivo(wictor::LDEC<wictor::Produto> *lista);
    static void salvarArquivo(wictor::LDEC<wictor::Produto> *listaProduto);
};
}

#endif // PRODUTOPERSISTENCIA_H
