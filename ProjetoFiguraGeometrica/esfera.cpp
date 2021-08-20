#include "esfera.h"

namespace tp2
{
    Esfera::Esfera():FiguraGeometrica ()
    {

    }
    double FiguraGeometrica::calcularAreaTotal()const{
        double areaTotal= 4*3.14*(pow(getRaio(),2));
        return areaTotal;
    }
    double FiguraGeometrica::calcularVolume() const{
        double volume = (4*3.14*(pow(getRaio(),3)))/3;
        return volume;
    }
}
