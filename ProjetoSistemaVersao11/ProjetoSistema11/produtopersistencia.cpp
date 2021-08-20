#include "produtopersistencia.h"

namespace wictor {
produtoPersistencia::produtoPersistencia()
{
}

void produtoPersistencia::lerArquivo(wictor::LDEC<Produto> *lista)
{
    std::string leitura;
    wictor::Produto produto;
    QString arquivoProdutos="ListaDeProdutos.csv";
    std::ifstream arquivo;
    arquivo.open("ListaDeProdutos.csv");
    if (arquivo.is_open()){
        getline(arquivo,leitura);
        while(!arquivo.eof()){
            QString linha=QString::fromStdString(leitura);
            if(linha!=""){
                QStringList list=linha.split(';');
                produto.setCodigo(list[0]);
                produto.setDescricao(list[1]);
                produto.setQuantidade(list[2].toInt());
                produto.setPreco(list[3].toDouble());
                lista->pushBack(produto);
            }
            getline(arquivo,leitura);
        }
    }

    arquivo.close();
}

void produtoPersistencia::salvarArquivo(wictor::LDEC<Produto> *listaProduto)
{
    std::ofstream arquivo;
    arquivo.open("ListaDeProdutos.csv");
    QString aux;
    for(int i=0;i<listaProduto->getSize();i++){
        wictor::Produto produto = listaProduto->operator[](i);
        arquivo<< produto.getCodigo().toStdString()<<";";
        arquivo<<produto.getDescricao().toStdString()<<";";
        aux = QString::number(produto.getQuantidade());
        arquivo<< aux.toStdString()<<";";
        aux = QString::number(produto.getPreco(),'f',2);
        arquivo<< aux.toStdString();
        arquivo<<"\n";
    }
}

}
