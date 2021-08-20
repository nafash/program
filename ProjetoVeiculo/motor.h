#ifndef MOTOR_H
#define MOTOR_H
#include<QString>

namespace tp2 {

class Motor
{
private:
    int NumeroCilindros;
    QString Potencia;
public:
    Motor();
    Motor(int NumeroCilindros,QString Potencia);

     int getNumeroCilindros()const;
     void setNumeroCilindros( int NumeroCilindros);

     QString getPotencia()const;
     void setPotencia(QString Potencia);

    virtual QString print()=0;

};
}
#endif // MOTOR_H
