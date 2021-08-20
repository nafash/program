#include "carrodepasseio.h"

namespace tp2
{
    CarroDePasseio::CarroDePasseio():
        modelo(""),
        cor("")
    {

    }
    CarroDePasseio::CarroDePasseio(double Peso,double VelocidadeMaxima,double Preco,int NumeroCilindros,int Potencia, QString Modelo, QString Cor):
        Veiculo(Peso,VelocidadeMaxima,Preco),
        Motor(NumeroCilindros,Potencia)
    {
        setModelo(Modelo);
        setCor(Cor);
    }

    QString CarroDePasseio::printf(){
        Motor motor;
        Veiculo veiculo;
        QString saida;

        saida += motor.printf();
        saida += veiculo.printf();
        saida += "Modelo: ";
        saida += getModelo();
        saida += "\n";
        saida += "Cor: ";
        saida += getCor();
        saida += "\n";

        return saida;
    }
}
