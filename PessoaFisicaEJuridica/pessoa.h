#ifndef PESSOA_H
#define PESSOA_H
#include <QString>


namespace tp2
{
    class Pessoa
    {
    private:
        QString nome, moradia, email;
        float rendaBruta;
        int telefone;
    public:
        Pessoa();
        void setNome(QString nome){this->nome = nome;}
        QString getNome()const{return nome;}

        void setMoradia(QString moradia){this->moradia = moradia;}
        QString getMoradia()const{return moradia;}

        void setEmail(QString email){this->email = email;}
        QString getEmail()const{return email;}

        void setRendaBruta(float rendaBruta){
            if(rendaBruta<=0) throw QString ("Renda Bruta inválida");
            this->rendaBruta = rendaBruta;
        }
        float getRendaBruta()const{return rendaBruta;}

        void setTelefone(int telefone){
            if(telefone<=0) throw QString ("Telefone inválido");
            this->telefone = telefone;
        }
        int getTelefone()const{return telefone;}

        virtual float calcularImposto()const=0;
    };
}

#endif // PESSOA_H
