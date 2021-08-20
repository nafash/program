#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <QString>
namespace tp2 {

template <class T>

    class Calculadora
    {
    private:
        T num1, num2;
    public:
        Calculadora();
        Calculadora(T num1, T num2);
        T adicionar();
        T subtrair();
        T multiplicar();
        T dividir();
    };

    template <class T>
    Calculadora<T>::Calculadora():
        num1(0),
        num2(0)
    {

    }

    template<class T>
    Calculadora<T>::Calculadora(T num1, T num2):
        num1(num1),
        num2(num2)
    {

    }

    template<class T>
    T Calculadora<T>::adicionar()
    {
        T soma = num1 + num2;
        return soma;
    }

    template<class T>
    T Calculadora<T>::subtrair()
    {
        T subtrair = num1 - num2;
        return subtrair;
    }

    template<class T>
    T Calculadora<T>::multiplicar()
    {
        T multiplicar = num1 * num2;
        return multiplicar;
    }

    template<class T>
    T Calculadora<T>::dividir()
    {
        if(num2==0)throw QString("Não existe divisão por zero");
        T dividir = num1 / num2;
        return dividir;
    }
}

#endif // CALCULADORA_H
