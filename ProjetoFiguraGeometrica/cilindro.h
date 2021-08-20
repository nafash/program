#ifndef CILINDRO_H
#define CILINDRO_H
#include <QString>
#include <figurageometrica.h>
namespace tp2
{
    class Cilindro:public FiguraGeometrica
    {
        private:
        double altura;
        public:
        Cilindro();
        void setAltura(double altura);
        double getAltura()const{return altura;}

        double calcularAreaLateral()const;
        double calcularAreaTotal()const;
        double calcularVolume()const;

        QString getTipoDaFigura(){return "Cilindro";}

};
}

#endif // CILINDRO_H
