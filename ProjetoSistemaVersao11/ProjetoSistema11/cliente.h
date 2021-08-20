#ifndef CLIENTE_H
#define CLIENTE_H
#include <QString>

namespace wictor {

class Cliente
{
private:
    int id;
    QString nome;
    QString endereco;
    QString telefone;
    QString cpf;
public:
    Cliente(); //id recebe o ultimo id inserido e da +++
    Cliente(int id, QString nome, QString endereco, QString telefone, QString cpf);

    void setId(int value);
    int getId(){return id;}

    void setNome(QString value);
    QString getNome(){return nome;}

    void setEndereco(QString value);
    QString getEndereco(){return endereco;}

    void setTelefone(QString value);
    QString getTelefone(){return telefone;}

    void setCpf(QString value);
    QString getCpf(){return cpf;}

    QString print();

    bool operator< (const Cliente &valor1)const{return (id < valor1.id);}
    bool operator<= (const Cliente &valor1)const{return (id <= valor1.id);}
    bool operator> (const Cliente &valor1)const{return id > valor1.id;}
    bool operator>= (const Cliente &valor1)const{return id >= valor1.id;}

};
}

#endif // CLIENTE_H
