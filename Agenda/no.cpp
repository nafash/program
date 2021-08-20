#include "no.h"

namespace tp2
{
    No::No():
        contato(nullptr),
        nodenext(nullptr),
        nodeback(nullptr)
    {

    }
    No::No(pessoa *value):
        nodenext(nullptr),
        nodeback(nullptr)
    {
        this->contato = value;
    }
}
