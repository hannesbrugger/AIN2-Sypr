/*
 * intlist.h
 *
 * Beispielprogramm eingebettete Klassen.
 * Variante mit std::unique_ptr.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 28.11.2019
 */
#ifndef INTLIST_H
#define INTLIST_H

#include <memory>

class intlist final
{
    // entity class ohne Kopiersemantik
    intlist(intlist&) = delete;
    intlist& operator=(intlist&) = delete;

private:
    class element;

public:
    intlist();
    // ~intlist();
    intlist(intlist&&) = default;
    intlist& operator=(intlist&&) = default;
    intlist& insert(int);

    class iterator final
    {
    private:
        element *current;
        explicit iterator(element*);
    public:
        bool operator!=(const iterator&) const;
        int& operator*() const;
        iterator& operator++();

        friend class intlist;
    };

    iterator begin();
    iterator end();

private:
    class element final
    {
        std::unique_ptr<element> next;
        int n;

        element(element *e, int m) : next(e), n(m) { }
        friend class intlist;
        friend class intlist::iterator;
    };

    std::unique_ptr<element> head;
};

#endif

