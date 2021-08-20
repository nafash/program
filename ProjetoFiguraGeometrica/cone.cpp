#include "cone.h"

namespace tp2{
    Cone::Cone()
    {

    }
    double Cone::calcularGeratriz()const{
        double geratriz = sqrt((pow(getAltura(),2))+(pow(getRaio(),2)));
        return geratriz;
    }
    double Cone::calcularAreaLateral()const{
        double AreaLateralCone=3.14*getRaio()*calcularGeratriz();
        return AreaLateralCone;
    }
    double Cone::calcularAreaTotal()const{
        double arealTotalCone = 3.14*getRaio()*(calcularGeratriz() + getRaio()) ;
        return arealTotalCone;
    }
    double Cone::calcularVolume()const{
        double volumeCone = 3.14 * (pow(getRaio(),2))*getAltura();
        return volumeCone;
    }
}
