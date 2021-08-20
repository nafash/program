#include "caminhao.h"
namespace  tp2{

Caminhao::Caminhao():
    Tonelada(0),
    AlturaMaxima(0),
    Comprimento(0)
{

}
Caminhao::Caminhao(double Peso,double VelocidadeMaxima,double Preco,int NumeroCilindros,QString Potencia,double Tonelada, double AlturaMaxima,double Comprimento):
    Veiculo(Peso,VelocidadeMaxima,Preco),
    Motor(NumeroCilindros,Potencia)
{
    setTonelada(Tonelada);
    setAlturaMaxima(AlturaMaxima);
    setComprimento(Comprimento);
}

void Caminhao::setTonelada(double Tonelada){
    if(Tonelada<0)throw QString("Tonelada invalida");
    this->Tonelada=Tonelada;
}
double Caminhao::getTonelada() const{
    return Tonelada;
}

void Caminhao::setAlturaMaxima(double AlturaMaxima){
    if(AlturaMaxima<0)throw QString("Altura Maxima invalida");
    this->AlturaMaxima=AlturaMaxima;
}
double Caminhao::getAlturaMaxima() const{
    return AlturaMaxima;
}

void Caminhao::setComprimento(double Comprimento){
    if(Comprimento<0)throw QString("Comprimento invalido");
    this->Comprimento=Comprimento;
}
double Caminhao::getComprimento() const{
    return Comprimento;
}

QString Caminhao::print(){
    QString saida="Peso: "+QString::number(getPeso())+"\n";
    saida+="Velocidade Maxima: "+QString::number(getVelocidadeMaxima())+"\n";
    saida+="Preco: "+QString::number(getPreco())+"\n";
    saida+="Numero de Cilindros: "+QString::number(getNumeroCilindros())+"\n";
    saida+="Potencia: "+getPotencia()+"\n";
    saida+="Tonelada: "+QString::number(getTonelada())+"\n";
    saida+="Altura Maxima: "+QString::number(getAlturaMaxima())+"\n";
    saida+="Comprimento: "+QString::number(getComprimento());
    return saida;
}
}
