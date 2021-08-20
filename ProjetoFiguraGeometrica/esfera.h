#ifndef ESFERA_H
#define ESFERA_H
#include <figurageometrica.h>
namespace tp2
{
    class Esfera:public FiguraGeometrica
    {
    public:
        Esfera();
        QString getTipoDaFigura()const{
            return "Esfera";
        }
        double calcularAreaTotal()const;
        double calcularVolume()const;
    };
}

#endif // ESFERA_H
