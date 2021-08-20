#include "motor.h"
namespace tp2 {

Motor::Motor():
    NumeroCilindros(0),
    Potencia("")
{

}

Motor::Motor(int NumeroCilindros,QString Potencia)
{
    setNumeroCilindros(NumeroCilindros);
    setPotencia(Potencia);
}

void Motor::setPotencia(QString Potencia){
    this->Potencia=Potencia;
}
QString Motor::getPotencia() const{
    return Potencia;
}

void Motor::setNumeroCilindros(int NumeroCilindros){
    if(NumeroCilindros<=0)throw QString("Numero de Cilindros invalido");
    this->NumeroCilindros=NumeroCilindros;
}
int Motor::getNumeroCilindros() const{
    return NumeroCilindros;
}

}
