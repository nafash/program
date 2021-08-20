#include "cilindro.h"

namespace tp2
{
    Cilindro::Cilindro():
        altura(1)
    {
    }
    void Cilindro::setAltura(double altura)
    {
        if(altura <= 0 )throw QString("Altura invalida");
        this->altura  =altura;

    }

    double Cilindro::calcularAreaLateral() const
    {
        double AreaLateralCilindro=2*3.14*getRaio()*getAltura();
        return AreaLateralCilindro;
    }
    double Cilindro::calcularAreaTotal() const{
        double areaDaBase=3.14*(pow(getRaio(),2));
        double arealTotal = (2*areaDaBase) + calcularAreaLateral();
        return arealTotal;
    }
    double Cilindro::calcularVolume()const{
        double volumecilindro= 3.14 * (pow(getRaio(),2))*getAltura();
        return volumecilindro;
    }
}

