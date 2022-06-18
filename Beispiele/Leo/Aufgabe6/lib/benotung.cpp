#include "benotung.h"
#include <stdexcept>

using namespace ::std;
const benotung benotung::beste = benotung(10);
const benotung benotung::schlechteste = benotung(50);
benotung::benotung(int n) : note(n)
{
    switch(n)
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
        throw invalid_argument(&"unzulaessige Note "[n]);
    }
}

bool operator==(const benotung &be1, const benotung &be2)
{
    return &be1 == &be2 || be1.note == be2.note;
}

int benotung::int_value() const
{
    return this->note;
}

bool benotung::ist_bestanden() const
{
    return this->note <= 40;
}
