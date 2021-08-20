#ifndef CONVERTER_H
#define CONVERTER_H
#include <QString>

namespace tp2
{
class Converter
{
private:
    QString texto;
public:
    Converter();

    QString getText() const{return texto;}
    void setText(QString value);

    QString converterMaiusculo();
    QString converterMinusculo();
    QString converterMandM();

};
}

#endif // CONVERTER_H
