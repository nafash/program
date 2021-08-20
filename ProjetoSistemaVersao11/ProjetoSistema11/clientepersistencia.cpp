#include "clientepersistencia.h"

namespace wictor {
clientePersistencia::clientePersistencia()
{
}

void wictor::clientePersistencia::lerArquivo(wictor::LDEC<wictor::Cliente> *lista)
{
    std::string leitura;
    wictor::Cliente cliente;
    std::ifstream arquivo;
    arquivo.open("ListaDeClientes.csv");
    if (arquivo.is_open()){
        getline(arquivo,leitura);
        while(!arquivo.eof()){
            QString linha=QString::fromStdString(leitura);
            if(linha!=""){
                QStringList list=linha.split(';');
                cliente.setId(list[0].toInt());
                cliente.setNome(list[1]);
                cliente.setEndereco(list[2]);
                cliente.setTelefone(list[3]);
                cliente.setCpf(list[4]);
                lista->pushBack(cliente);
            }
            getline(arquivo,leitura);
        }
    }

    arquivo.close();
}

void wictor::clientePersistencia::salvarArquivo(wictor::LDEC<wictor::Cliente> *listaCliente)
{
    std::ofstream arquivo;
    arquivo.open("ListaDeClientes.csv");
    QString aux;
    for(int i=0;i<listaCliente->getSize();i++){
        wictor::Cliente cliente = listaCliente->operator[](i);
        aux = QString::number(cliente.getId());
        arquivo<< aux.toStdString()<<";";
        arquivo<<cliente.getNome().toStdString()<<";";
        arquivo<< cliente.getEndereco().toStdString()<<";";
        arquivo<< cliente.getTelefone().toStdString()<<";";
        arquivo<< cliente.getCpf().toStdString();
        arquivo<<"\n";
    }
}
}
