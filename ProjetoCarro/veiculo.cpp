#include "veiculo.h"

namespace tp2 {

    Veiculo::Veiculo():
        peso(0),
        price(0),
        velocidade(0)
    {

    }

    Veiculo::Veiculo(float peso, float price, float velocidade):
        peso(peso),
        price(price),
        velocidade(velocidade)
    {

    }

    QString Veiculo::printf(){
        QString saida;
        saida += "Peso: ";
        saida += QString::number(getPeso());
        saida += "\n";
        saida += "Preço: ";
        saida += QString::number(getPrice());
        saida += "\n";
        saida += "Velocidade: ";
        saida += QString::number(getVelocidade());
        saida += "\n";

        return saida;
    }
}

