#include "motor.h"

namespace tp2
{
    Motor::Motor():
        nDeCilindros(0),
        potencia(0)
    {

    }
    Motor::Motor(int NumeroCilindros,int Potencia):
        nDeCilindros(NumeroCilindros),
        potencia(Potencia)
    {

    }

    QString Motor::printf(){
        QString saida;
        saida += "Número de cilindros: ";
        saida += QString::number(getNDeCilindros());
        saida += "\n";
        saida += "Potência: ";
        saida += QString::number(getPotencia());
        saida += "HP's";
        saida += "\n";

        return saida;
    }
}
