#ifndef PRODUTO_H
#define PRODUTO_H
#include <QString>

namespace wictor {
class Produto
{
private:
    QString codigo;
    QString descricao;
    int quantidade;
    double preco;

public:
    Produto();
    Produto(QString codigo, QString descricao, int quantidade, double preco);

    QString getCodigo(){return codigo;}
    void setCodigo(QString value);

    QString getDescricao(){return descricao;}
    void setDescricao(QString value);

    double getQuantidade(){return quantidade;}
    void setQuantidade(int value);

    double getPreco(){return preco;}
    void setPreco(double value);

    QString print();

    bool operator< (const Produto &valor1)const{return codigo < valor1.codigo;}
    bool operator<= (const Produto &valor1)const{return codigo <= valor1.codigo;}
    bool operator> (const Produto &valor1)const{return codigo > valor1.codigo;}
    bool operator>= (const Produto &valor1)const{return codigo >= valor1.codigo;}
};
}

#endif // PRODUTO_H
