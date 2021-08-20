#ifndef GATO_H
#define GATO_H
#include <animal.h>

namespace tp2
{
    class Gato: public Animal
    {
    public:
        Gato();
        virtual QString fala()override;
    };
}

#endif // GATO_H
