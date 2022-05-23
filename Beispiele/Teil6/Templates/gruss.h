/*
 * gruss.h
 *
 * Variante des interface-Beispiels aus Teil 5 
 * mit parametrischer Polymorphie mittels template
 * statt Subtyppolymorphie mittels Vererbung.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 20.11.2020
 */

#ifndef GRUSS_H
#define GRUSS_H

#include <string>

template<typename T>
class gruss final
{
public:
    gruss() = default;
    T uhr;
    std::string gruessen();
    // entity: kein copy und move
    gruss(const gruss&) = delete;
    gruss& operator=(const gruss&) = delete;
    gruss(gruss&&) = delete;
    gruss& operator=(gruss&&) = delete;
};

template<typename T>
std::string gruss<T>::gruessen()
{
    int stunde;
    int minute;

    this->uhr.ablesen(stunde, minute);

    if (6 <= stunde && stunde < 11)
    {
        return "Guten Morgen";
    }

    if (11 <= stunde && stunde < 18)
    {
        return "Guten Tag";
    }

    if (18 <= stunde && stunde <= 23)
    {
        return "Guten Abend";
    }

    throw std::string("Nachtruhe!");
}

#endif

