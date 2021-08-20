#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include <QString>
#include <cmath>
#include <QMessageBox>

namespace tp2
{
    class FiguraGeometrica
    {
        private:
        double raio;

        public:
        FiguraGeometrica();
        FiguraGeometrica(double raio);
        void setRaio(double raio);
        double getRaio()const{return raio;}

        virtual double calcularAreaTotal()const=0;
        virtual double calcularVolume()const=0;
        virtual QString getFigura(){return "Figura Geométrica";}
    };
}

#endif // FIGURAGEOMETRICA_H
