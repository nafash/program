#ifndef CONE_H
#define CONE_H
#include <cilindro.h>
namespace tp2
{
    class Cone:public Cilindro
    {
        public:
            Cone();
            double calcularGeratriz()const;
            double calcularAreaLateral()const;
            double calcularAreaTotal()const;
            double calcularVolume()const;

            QString getTipoDaFigura(){return "Cone";}
    };
}

#endif // CONE_H
