#ifndef CAMINHAO_H
#define CAMINHAO_H
#include<QString>
#include<veiculo.h>
#include<motor.h>

namespace tp2 {

class Caminhao:public Veiculo, public Motor
{
private:
    double Tonelada;
    double AlturaMaxima;
    double Comprimento;
public:
    Caminhao();
    Caminhao(double Peso,double VelocidadeMaxima,double Preco,int NumeroCilindros,QString Potencia,double Tonelada, double AlturaMaxima,double Comprimento);

    double getTonelada()const;
    void setTonelada(double Tonelada);

    double getAlturaMaxima()const;
    void setAlturaMaxima(double AlturaMaxima);

    double getComprimento()const;
    void setComprimento( double Comprimento);

    QString print() override;

};
}

#endif // CAMINHAO_H
