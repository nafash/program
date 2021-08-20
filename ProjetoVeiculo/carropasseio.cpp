#include "carropasseio.h"
namespace tp2 {

CarroPasseio::CarroPasseio():
    Modelo(""),
    Cor("")
{

}
CarroPasseio::CarroPasseio(double Peso,double VelocidadeMaxima,double Preco,int NumeroCilindros,QString Potencia, QString Modelo, QString Cor):
    Veiculo(Peso,VelocidadeMaxima,Preco),
    Motor(NumeroCilindros,Potencia)
{
    setModelo(Modelo);
    setCor(Cor);
}
void CarroPasseio::setModelo(QString Modelo){
    this->Modelo=Modelo;
}
QString CarroPasseio::getModelo() const{
    return Modelo;
}

void CarroPasseio::setCor(QString Cor){
    this->Cor=Cor;
}
QString CarroPasseio::getCor() const{
    return Cor;
}

QString CarroPasseio::print(){

    QString saida="Peso: "+QString::number(getPeso())+"\n";
    saida+="Velocidade Maxima: "+QString::number(getVelocidadeMaxima())+"\n";
    saida+="Preco: "+QString::number(getPreco())+"\n";
    saida+="Numero de Cilindros: "+QString::number(getNumeroCilindros())+"\n";
    saida+="Potencia: "+getPotencia()+"\n";
    saida+="Modelo: "+getModelo()+"\n";
    saida+="Cor: "+getCor();

   return saida;

}
}
