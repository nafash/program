#ifndef CAMINHAO_H
#define CAMINHAO_H
#include <QString>
#include <motor.h>
#include <veiculo.h>

namespace tp2
{
    class Caminhao: public Motor, public Veiculo
    {
    private:
        float toneladas, altura, comprimento;
    public:
        Caminhao();
        Caminhao(double Peso,double VelocidadeMaxima,double Preco,int NumeroCilindros,int Potencia,double Tonelada, double AlturaMaxima,double Comprimento);

        void setToneladas(float toneladas){
            if(toneladas<=0)throw QString("Peso inválido");
            this->toneladas = toneladas;
        }
        float getToneladas()const{return toneladas;}

        void setAltura(float altura){
            if(altura<=0)throw QString("Altura inválida");
            this->altura = altura;
        }
        float getAltura()const{return altura;}

        void setComprimento(float comprimento){
            if(comprimento<=0)throw QString("Comprimento inválido");
            this->comprimento = comprimento;
        }
        float getComprimento()const{return comprimento;}

        QString printf();
    };
}

#endif // CAMINHAO_H
