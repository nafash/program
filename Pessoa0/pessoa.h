#ifndef PESSOA_H
#define PESSOA_H
#include <QString>
namespace tp2 {

    class Pessoa
    {
    private:
        QString nome, localDeMoradia, email;
        int telefone;
    public:
        Pessoa();

        QString getNome()const{return  nome;}
        void setNome(QString nome){this->nome = nome;}

        QString getLocalDeMoradia()const{return localDeMoradia;}
        void setLocalDeMoradia(QString localDeMoradia){this->localDeMoradia = localDeMoradia;}

        QString getEmail()const{return email;}
        void setEmail(QString email){this->email = email;}

        int getTelefone()const{return telefone;}
        void setTelefone(int telefone){
            if(telefone<0) throw ("O telefone não pode ser negativo");
            this->telefone = telefone;
        }
    };
}

#endif // PESSOA_H
