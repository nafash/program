#include "pedido.h"

namespace wictor {
Pedido::Pedido()
{

}

Pedido::Pedido(int idPedido, int idCliente, QString data, LDEC<Produto> *listaProdutos)
{
    setIdPedido(idPedido);
    setIdCliente(idCliente);
    setDataDaCompra(data);
    setListaProdutos(listaProdutos);
}

void Pedido::setIdPedido(int value)
{
    idPedido = value;
}

void Pedido::setIdCliente(int value)
{
    idCliente = value;
}

void Pedido::setDataDaCompra(QString value)
{
    dataDaCompra = value;
}

void Pedido::setListaProdutos(LDEC<Produto> *value)
{
    listaProdutos = value;
}

double Pedido::calcularValorTotalPorProduto(int value)
{
    return listaProdutos->operator[](value).getQuantidade() * listaProdutos->operator[](value).getPreco();
}

double Pedido::calcularValorTotalCompra()
{
    wictor::Produto objProduto;
    double total = 0;
    for (int i = 0; i < listaProdutos->getSize();i++){
        objProduto = listaProdutos->operator[](i);
        total += objProduto.getPreco() * objProduto.getQuantidade();
    }
    return total;
}
}
