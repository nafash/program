#include "veiculo.h"
namespace tp2 {

Veiculo::Veiculo():
    Peso(0),
    VelocidadeMaxima(0),
    Preco(0)
{

}
Veiculo::Veiculo(double Peso,double VelocidadeMaxima,double Preco){
    setPeso(Peso);
    setVelocidadeMaxima(VelocidadeMaxima);
    setPreco(Preco);

}
void Veiculo::setPeso(double Peso){
    if(Peso<=0)throw QString("Peso invalido");
    this->Peso=Peso;
}
double Veiculo::getPeso() const{
    return Peso;
}

void Veiculo::setVelocidadeMaxima(double VelocidadeMaxima){
    if(VelocidadeMaxima<=0)throw QString ("Velocidade Maxima invalida");
    this->VelocidadeMaxima=VelocidadeMaxima;
}
double Veiculo::getVelocidadeMaxima() const{
    return VelocidadeMaxima;
}

void Veiculo::setPreco(double Preco){
    if(Preco<=0)throw QString("Preço invalido");
    this->Preco=Preco;
}
double Veiculo::getPreco() const{
    return Preco;
}

}
