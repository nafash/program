#include "cliente.h"

namespace wictor {

Cliente::Cliente():
    id(0),
    nome(""),
    endereco(""),
    telefone(""),
    cpf("")
{

}

Cliente::Cliente(int id, QString nome, QString endereco, QString telefone, QString cpf){
    setId(id);
    setNome(nome);
    setEndereco(endereco);
    setTelefone(telefone);
    setCpf(cpf);
}

void Cliente::setId(int value)
{
    id = value;
}

void Cliente::setNome(QString value)
{
    if(value.size() == 0) throw QString ("Nome Invalido");
    for(int i = 0; i < value.size();i++){
        if(value[i].isNumber()) throw QString ("Nome Invalido");
    }
    nome = value;
}

void Cliente::setEndereco(QString value)
{
    if(value.size() == 0) throw QString ("Endereco Invalido");
    endereco = value;
}

void Cliente::setTelefone(QString value)
{
    if(value.size() == 0) throw QString("Telefone invalido");
    int cont = 0;
    for (int i = 0; i < value.size();i++){
        if(value[i].isNumber())
            cont++;
    }
    if(cont != 8 && cont != 9) throw QString("Telefone invalido");
    telefone = value;
}

void Cliente::setCpf(QString value)
{
    if(value.size() != 11) throw QString("CPF Inválido");
    int dv2 = 0;
    int dv1 = 0;
    QString digito;
    for(int i = 0, j = 11; i < 9; i++) {
        if(value[i].isLetter()) throw QString("CPF Inválido");
        digito = value[i];
        dv2 += (digito.toInt() * j);
        j--;
        dv1 += (digito.toInt() * j);
    }
    dv1 = (dv1%11 < 2) ? 0 : 11 - dv1%11;
    dv2 += dv1 * 2;
    dv2 = (dv2%11 < 2) ? 0 : 11 - dv2%11;
    if(QString::number(dv1) != value[value.size()-2] || QString::number(dv2) != value[value.size()-1]) throw QString("CPF Inválido");
    cpf = value;
}

QString Cliente::print()
{
    QString saida = "";
    saida += "Id: " + QString::number(id) + "\n";
    saida += "Nome: " + nome + "\n";
    saida += "Endereço: " + endereco + "\n";
    saida += "Telefone: " + telefone + "\n";
    saida += "CPF: " + cpf + "\n";
    return saida;
}
}
