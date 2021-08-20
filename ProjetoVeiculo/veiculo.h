#ifndef VEICULO_H
#define VEICULO_H
#include<QString>

namespace tp2 {

class Veiculo
{
private:
    double Peso;
    double VelocidadeMaxima;
    double Preco;
public:
    Veiculo();
    Veiculo(double Peso,double VelocidadeMaxima,double Preco);

    double getPeso()const;
    void setPeso(double Peso);

    double getVelocidadeMaxima()const;
    void setVelocidadeMaxima(double VelocidadeMaxima);

    double getPreco()const;
    void setPreco(double Preco);

   virtual QString print()=0;
};
}

#endif // VEICULO_H
