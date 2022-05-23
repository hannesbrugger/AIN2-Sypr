/*
 * listvar.cpp
 *
 * Beispielprogramm eingebettete Klassen.
 * Variante mit const_iterator und Iterator-Hilfstypen fuer std-Algorithmen.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 6.5.2021
 */
#include "intlist.h"
#include <iostream>
#include <algorithm>

int main()
{
    intlist list;
    list.insert(3814).insert(3635).insert(3442).insert(3421);

    auto i = std::find(std::begin(list), std::end(list), 3442);
    if (i != std::end(list)) {
        std::cout << *i << " ist in a enthalten\n";
    }

    const intlist& clist = list;

    auto j = std::find(clist.begin(), clist.end(), 3442);
    if (j != clist.end()) {
        std::cout << *j << " ist in a enthalten\n";
    }

    auto k = std::find(list.cbegin(), list.cend(), 3442);
    if (k != list.cend()) {
        std::cout << *k << " ist in a enthalten\n";
    }
}

