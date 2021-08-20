#ifndef CARROPASSEIO_H
#define CARROPASSEIO_H
#include<QString>
#include<motor.h>
#include<veiculo.h>

namespace tp2 {

class CarroPasseio:public Veiculo, public Motor
{
private:
    QString Modelo;
    QString Cor;
public:
    CarroPasseio();
    CarroPasseio(double Peso,double VelocidadeMaxima,double Preco,int NumeroCilindros,QString Potencia, QString Modelo, QString Cor);

    QString getModelo()const;
    void setModelo(QString Modelo);

    QString getCor()const;
    void setCor(QString Cor);

    QString print() override;
};
}

#endif // CARROPASSEIO_H
