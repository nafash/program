#ifndef HUMANO_H
#define HUMANO_H
#include <animal.h>

namespace tp2
{
    class Humano: public Animal
    {
    public:
        Humano();
        virtual QString fala()override;
    };
}

#endif // HUMANO_H
