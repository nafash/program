#include "produto.h"

namespace wictor{
Produto::Produto():
    codigo(""),
    descricao(""),
    quantidade(0),
    preco(0)
{

}

Produto::Produto(QString codigo, QString descricao, int quantidade, double preco)
{
    setCodigo(codigo);
    setDescricao(descricao);
    setQuantidade(quantidade);
    setPreco(preco);
}

void Produto::setCodigo(QString value)
{
    if(value.size() == 0) throw QString("Codigo Invalido");
    codigo = value;
}

void Produto::setDescricao(QString value)
{
    if(value.size() == 0) throw QString("Descriçao Invalida");
    descricao = value;
}

void Produto::setQuantidade(int value)
{
    quantidade = value;
}

void Produto::setPreco(double value)
{
    if(value <= 0) throw QString("Valor Invalido");
    preco = value;
}

QString Produto::print()
{
    QString saida = "";
    saida += "Codigo: " + codigo + "\n";
    saida += "Descrição: " + descricao + "\n";
    saida += "Quantidade em Estoque: " + QString::number(quantidade) + "\n";
    saida += "Preço Unitario: " + QString::number(preco,'f',2) + "\n";
    return saida;
}
}
