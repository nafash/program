#include "converter.h"

namespace tp2
{

Converter::Converter():
    texto("")
{
}

QString Converter::converterMinusculo()
{
    std::string textoFinal, texto;
    texto = this->texto.toStdString();
    for (int i = 0; i < (int)texto.size();i++){

        if(texto[i] >= 97 && texto[i] <= 122)
            textoFinal += char(texto[i] - 32);
        else
            textoFinal += texto[i];
    }

    return QString::fromStdString(textoFinal);
}

QString Converter::converterMaiusculo()
{
    std::string textoFinal, texto;
    texto = this->texto.toStdString();
    for (int i = 0; i < (int)texto.size();i++){
        if(texto[i] >= 65 && texto[i] <= 90)
            textoFinal += char(texto[i] + 32);
        else
            textoFinal += texto[i];
    }

    return QString::fromStdString(textoFinal);
}

QString Converter::converterMandM(){
    std::string textoFinal, texto;
    texto = this->texto.toStdString();
    for (int i = 0; i < (int)texto.size();i++){
        if(texto[i] >= 65 && texto[i] <= 90)
            textoFinal += char(texto[i] + 32);
        else if(texto[i] >= 97 && texto[i] <= 122)
            textoFinal += char(texto[i] - 32);
        else
            textoFinal += texto[i];
    }

    return QString::fromStdString(textoFinal);
}

void Converter::setText(QString value)
{
    if(value.size() == 0) throw::QString("Arquivo Vazio.");
    texto = value;
}
}
