#include "pedidopersistencia.h"

namespace wictor{
pedidoPersistencia::pedidoPersistencia()
{

}

void pedidoPersistencia::lerArquivo(wictor::LDEC<wictor::Pedido> *lista)
{
    std::string leitura;
    wictor::Pedido pedido;
    QString arquivoProdutos="ListaDePedidos.csv";
    std::ifstream arquivo;
    arquivo.open("ListaDePedidos.csv");
    if (arquivo.is_open()){
        getline(arquivo,leitura);
        while(!arquivo.eof()){
            QString linha=QString::fromStdString(leitura);
            if(linha!=""){
                QStringList list=linha.split(';');
                pedido.setIdPedido(list[0].toInt());
                pedido.setIdCliente(list[1].toInt());
                pedido.setDataDaCompra(list[2]);

                wictor::LDEC<wictor::Produto>* ListaDeItens = new wictor::LDEC<wictor::Produto>();
                //lista->pushBack(pedido);
                int quantidade=list[3].toInt();
                getline(arquivo,leitura);
                linha=QString::fromStdString(leitura);
                if(linha!=""){
                    list=linha.split(';');
                    for(int i=1, j=1;i<=quantidade;i++,j+=3){
                        wictor::Produto item;
                        item.setCodigo(list[j]);
                        item.setQuantidade(list[j+1].toInt());
                        item.setPreco(list[j+2].toDouble());
                        item.setDescricao("vazio");
                        ListaDeItens->pushBack(item);
                    }
                }
                pedido.setListaProdutos(ListaDeItens);
                lista->pushBack(pedido);
            }
            getline(arquivo,leitura);
        }
    }

    arquivo.close();
}

void pedidoPersistencia::salvarArquivo(wictor::LDEC<wictor::Pedido> *listaPedido)
{
    std::ofstream arquivo;
    arquivo.open("ListaDePedidos.csv");
    QString aux;
    for(int i=0;i<listaPedido->getSize();i++){
        wictor::Pedido pedido=listaPedido->operator[](i);
        aux = QString::number(pedido.getIdPedido());
        arquivo<< aux.toStdString()<<";";
        aux = QString::number(pedido.getIdCliente());
        arquivo<< aux.toStdString()<<";";
        arquivo<< pedido.getDataDaCompra().toStdString()<<";";
        wictor::LDEC<wictor::Produto> listaProduto;
        listaProduto = *pedido.getListaProdutos();
        arquivo<< listaProduto.getSize()<<"\n";
        for(int i=0;i<listaProduto.getSize();i++){
            wictor::Produto item = listaProduto.operator[](i);
            arquivo <<";"<<item.getCodigo().toStdString();
            arquivo <<";"<<item.getQuantidade();
            arquivo <<";"<<item.getPreco();
        }
        arquivo<<"\n";
    }
}
}

