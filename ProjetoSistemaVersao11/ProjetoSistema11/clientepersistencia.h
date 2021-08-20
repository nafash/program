#ifndef CLIENTEPERSISTENCIA_H
#define CLIENTEPERSISTENCIA_H
#include "cliente.h"
#include <ldec.h>
#include <QStringList>
#include <fstream>

namespace wictor{
class clientePersistencia
{
public:
    clientePersistencia();
    static void lerArquivo(wictor::LDEC<wictor::Cliente> *lista);
    static void salvarArquivo(wictor::LDEC<wictor::Cliente> *listaCliente);
};
}

#endif // CLIENTEPERSISTENCIA_H
