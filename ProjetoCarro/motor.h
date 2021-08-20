#ifndef MOTOR_H
#define MOTOR_H
#include <QString>

namespace tp2
{
    class Motor
    {
    private:
        int nDeCilindros, potencia;
    public:
        Motor();
        Motor(int NumeroCilindros,int Potencia);

        void setNDeCilindros(int nDeCilindros){
            if(nDeCilindros<=0)throw QString("Número de cilindros inválidos");
            this->nDeCilindros = nDeCilindros;
        }
        int getNDeCilindros()const{return nDeCilindros;}

        void setPotencia(int potencia){
            if(potencia<=0)throw QString("Potência inválida");
            this->potencia = potencia;
        }
        int getPotencia()const{return potencia;}

        QString printf();
    };
}

#endif // MOTOR_H
