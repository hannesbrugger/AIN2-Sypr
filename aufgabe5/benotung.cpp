#include "benotung.h"
#include <stdexcept>

const benotung benotung::beste = benotung(10);
const benotung benotung::schlechteste = benotung(50);

benotung::benotung(int note)
: note(note)
{
    switch (note)
    {
    case 10:
    case 13:
    case 17:
    case 20:
    case 23:
    case 27:
    case 30:
    case 33:
    case 37:
    case 40:
    case 50:
        break;
    
    default:
        throw std::invalid_argument("unzulaessige Note");
        break;
    }
    
}

int benotung::int_value() const
{
    return this->note;
}

bool benotung::ist_bestanden() const
{
    return this->note < schlechteste.int_value();
}

bool operator==(const benotung& b1, const benotung& b2)
{
    return b1.int_value() == b2.int_value();
}
