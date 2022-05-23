/*
 * intlist.cpp
 *
 * Beispielprogramm eingebettete Klassen.
 * Variante mit std::unique_ptr.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 28.11 2019
 */
#include "intlist.h"

//----------------------------------------- Member-Funktionen intlist::iterator
intlist::iterator::iterator(element *e)
: current(e)
{ }

bool intlist::iterator::operator!=(const iterator& i) const
{
    return this->current != i.current;
}

int& intlist::iterator::operator*() const
{
    return this->current->n;
}

intlist::iterator& intlist::iterator::operator++()
{
    this->current = this->current->next.get();
    return *this;
}

//--------------------------------------------------- Member-Funktionen intlist
intlist::intlist()
: head(nullptr)
{ }

intlist& intlist::insert(int n)
{
    this->head.reset(new element(this->head.release(), n));
    return *this;
}

intlist::iterator intlist::begin()
{
    return intlist::iterator(this->head.get());
}

intlist::iterator intlist::end()
{
    return intlist::iterator(nullptr);
}

