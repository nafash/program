#ifndef GRADUADO_H
#define GRADUADO_H
#include <pessoa.h>

namespace tp2
{
    class Graduado: public Pessoa
    {
    private:
        int anoDeConclusao, anoDaColacaoDeGrau, numeroDoDiploma;
    public:
        Graduado();
        int getAnoDeConclusao()const{return anoDeConclusao;}
        void setAnoDeConclusao(int anoDeConculsao){
            if(anoDeConculsao<0) throw QString("O ano de conclusão não pode ser negativo");
            this->anoDeConclusao = anoDeConclusao;
        }

        int getAnoDaColacaoDeGrau()const{return anoDaColacaoDeGrau;}
        void setAnoDaColacaoDeGrau(int anoDaColacaoDeGrau){
            if(anoDaColacaoDeGrau<0) throw QString("O ano da gradução não pode ser negativo");
            this->anoDaColacaoDeGrau = anoDaColacaoDeGrau;
        }

        int getNumeroDoDiploma()const{return numeroDoDiploma;}
        void setNumeroDoDiploma(int numeroDoDiploma){
            if(numeroDoDiploma) throw QString("O número do diploma não pode ser negativo");
            this->numeroDoDiploma = numeroDoDiploma;
        }
    };
}

#endif // GRADUADO_H
