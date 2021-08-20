#ifndef PESSOA_H
#define PESSOA_H
#include <QString>

namespace tp2 {

    class pessoa
    {
    private:
        QString nome, localDeMoradia, email, documento;
        int  dia, mes, ano;
    public:
        pessoa();
        pessoa(QString nome, QString localDeMoradia, QString email, int  dia, int mes, int ano);

        QString getNome()const{return nome;}
        void setNome(QString nome){this->nome = nome;}

        QString getLocalDeMoradia()const{return localDeMoradia;}
        void setLocalDeMoradia(QString localDeMoradia){this->localDeMoradia=localDeMoradia;}

        QString getEmail()const{return email;}
        void setEmail(QString email){this->email =email;}

        int getDia() const{return dia;}
        void setDia(int dia);

        int getMes() const{return mes;}
        void setMes(int mes);

        int getAno() const{return ano;}
        void setAno(int ano);

        QString dataDeNascimento();

        virtual void setDocumento(QString documento);
        virtual QString getDocumento()const{return documento;}

        virtual QString printf();
    };
}

#endif // PESSOA_H
