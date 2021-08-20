#ifndef PEDIDO_H
#define PEDIDO_H
#include <produto.h>
#include <ldec.h>

namespace wictor {
class Pedido
{
private:
    int idPedido;
    int idCliente;
    QString dataDaCompra;
    LDEC<Produto>* listaProdutos;

public:
    Pedido();
    Pedido(int idPedido, int idCliente, QString data, LDEC<Produto>* listaProdutos);

    int getIdPedido(){return idPedido;}
    void setIdPedido(int value);

    int getIdCliente(){return idCliente;}
    void setIdCliente(int value);

    QString getDataDaCompra(){return dataDaCompra;}
    void setDataDaCompra(QString value);

    LDEC<Produto>* getListaProdutos(){return listaProdutos;}
    void setListaProdutos(LDEC<Produto>* value);

    void realizarPedido();
    double calcularValorTotalPorProduto(int value);
    double calcularValorTotalCompra();
};
}

#endif // PEDIDO_H
