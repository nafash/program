#ifndef CARRODEPASSEIO_H
#define CARRODEPASSEIO_H
#include <QString>
#include <motor.h>
#include <veiculo.h>

namespace tp2
{
    class CarroDePasseio: public Motor, public Veiculo
    {
    private:
        QString modelo,cor;
    public:
        CarroDePasseio();
        CarroDePasseio(double Peso,double VelocidadeMaxima,double Preco,int NumeroCilindros,int Potencia, QString Modelo, QString Cor);

        void setModelo(QString modelo){this->modelo=modelo;}
        QString getModelo()const{return modelo;}

        void setCor(QString cor){this->cor = cor;}
        QString getCor() const{return cor;}

        QString printf();
    };
}

#endif // CARRODEPASSEIO_H
