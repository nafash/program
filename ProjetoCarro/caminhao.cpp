#include "caminhao.h"

namespace tp2
{
    Caminhao::Caminhao():
        toneladas(0),
        altura(0),
        comprimento(0)
    {

    }

    Caminhao::Caminhao(double Peso,double VelocidadeMaxima,double Preco,int NumeroCilindros,int Potencia, double Tonelada, double AlturaMaxima,double Comprimento):
        toneladas(Tonelada),
        altura(AlturaMaxima),
        comprimento(Comprimento),
        Veiculo(Peso, Preco, VelocidadeMaxima),
        Motor(NumeroCilindros,Potencia)
    {

    }

    QString Caminhao::printf(){
        Motor motor;
        Veiculo veiculo;
        QString saida;

        saida += motor.printf();
        saida += veiculo.printf();
        saida += "Toneladas: ";
        saida += QString::number(getToneladas());
        saida += "\n";
        saida += "Alturas: ";
        saida += QString::number(getAltura());
        saida += "\n";
        saida += "Comprimento: ";
        saida += QString::number(getComprimento());
        saida += "\n";

        return saida;
    }
}
