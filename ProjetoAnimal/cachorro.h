#ifndef CACHORRO_H
#define CACHORRO_H
#include <animal.h>

namespace tp2
{
    class Cachorro: public Animal
    {
    public:
        Cachorro();
        virtual QString fala()override;
    };
}

#endif // CACHORRO_H
