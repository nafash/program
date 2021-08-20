#include "pessoafisica.h"

namespace tp2 {
    PessoaFisica::PessoaFisica():
        estadoCivil(""),
        CPF("")
    {

    }

    PessoaFisica::PessoaFisica(QString nome,QString  endereco,QString  email,QString documento,int  dia,int mes,int ano,QString estadoCivil):
        pessoa(nome, endereco, email, dia, mes, ano)
    {
        setEstadoCivil(estadoCivil);
        setDocumento(documento);
    }

    void PessoaFisica::setDocumento(QString documento)
    {
        if(documento.size() != 11) throw QString ("CPF Invalido");
            std::string cpfString = documento.toStdString();
            int cont = 1, cont2 = 9, sum =  0, sum2 = 0;
            for (int i = 0;i < (int)documento.size()-2;i++){
                if(documento[i].isNumber()){
                    sum += (cpfString[i] - '0')* cont;
                    sum2 += (cpfString[i] - '0')* cont2;
                    cont++;
                    cont2--;
                }
                else
                    throw QString ("CPF Invalido");
            }
            int b1 = sum % 11;
            int b2 = sum2 % 11;
            if((b1 == cpfString[cpfString.size() - 2] - '0' ) &&  (b2 == cpfString[cpfString.size()- 1] - '0'))

                this->CPF = documento;

            else throw QString ("CPF Invalido");
    }

    QString PessoaFisica::printf()
    {
        QString saida = "";
        saida += pessoa::printf();
        saida += "Estado Civil: ";
        saida += getEstadoCivil();
        saida += "\n";
        saida += "CPF: ";
        saida += getDocumento();
        saida += "\n";

        return saida;
    }

}
