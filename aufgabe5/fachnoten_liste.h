#ifndef FACHNOTEN_LISTE_H
#define FACHNOTEN_LISTE_H

class fachnoten_liste final
{
private:
    class element;
    element *head;

public:
    fachnoten_liste();
    ~fachnoten_liste();
    // Entity-Klasse ohne Kopier- und Move-Semantik
    fachnoten_liste(const fachnoten_liste&) = delete;
    fachnoten_liste& operator=(const fachnoten_liste&) = delete;
    fachnoten_liste(fachnoten_liste&&) = delete;
    fachnoten_liste& operator=(fachnoten_liste&&) = delete;

    fachnoten_liste& insert(fachnote*);

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
};

#endif
