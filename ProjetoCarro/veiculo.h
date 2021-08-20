#ifndef VEICULO_H
#define VEICULO_H
#include <QString>

namespace tp2
{
    class Veiculo
    {
    private:
        float peso, price;
        float velocidade;
    public:
        Veiculo();
        Veiculo(float peso, float price, float velocidade);

        void setPeso(float peso){
            if(peso<=0)throw QString("Peso inváliodo");
            this->peso = peso;
        }
        float getPeso()const{return peso;}

        void setPrice(float price){
            if(price<=0)throw QString("Preço inválido");
            this->price = price;
        }
        float getPrice()const{return price;}

        void setVelocidade(float velocidade){
            if(velocidade<=0)throw QString("Velocidade inválida");
            this->velocidade = velocidade;
        }
        float getVelocidade()const{return velocidade;}

        QString printf();

    };
}

#endif // VEICULO_H
