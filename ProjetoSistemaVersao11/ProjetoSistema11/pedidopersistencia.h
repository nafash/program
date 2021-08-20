#ifndef PEDIDOPERSISTENCIA_H
#define PEDIDOPERSISTENCIA_H
#include "pedido.h"
#include <QStringList>
#include <fstream>

namespace wictor{
class pedidoPersistencia
{
public:
    pedidoPersistencia();
    static void lerArquivo(wictor::LDEC<wictor::Pedido> *lista);
    static void salvarArquivo(wictor::LDEC<wictor::Pedido> *listaPedido);
};
}

#endif // PEDIDOPERSISTENCIA_H
