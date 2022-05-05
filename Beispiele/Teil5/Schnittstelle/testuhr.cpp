/*
 * testuhr.cpp
 *
 * Autor: H.Drachenfels
 * Erstellt am: 12.8.2020
 */

#include "testuhr.h"
#include <stdexcept>

testuhr::testuhr()
: stunde(0), minute(0)
{ }

void testuhr::stellen(unsigned s, unsigned m)
{
    this->stunde = (s + m / 60) % 24;
    this->minute = m % 60;
}

void testuhr::ablesen(unsigned& s, unsigned& m) const
{
    s = this->stunde;
    m = this->minute;
}

