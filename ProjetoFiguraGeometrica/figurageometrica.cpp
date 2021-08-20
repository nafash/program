#include "figurageometrica.h"

namespace tp2{

    FiguraGeometrica::FiguraGeometrica():
    raio(1)
    {
    }
    void FiguraGeometrica::setRaio(double raio){
        if(raio <= 0 )throw QString("Raio invalido");
        this->raio = raio;

    }
}
