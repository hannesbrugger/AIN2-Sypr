/*
 * htwg_array.h
 *
 * Stark vereinfachte Array-Klasse.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 27.4.2017
 */
#ifndef HTWG_ARRAY_H
#define HTWG_ARRAY_H

namespace htwg
{
    template<typename T, unsigned N>
    class array
    {
    public:
        T a[N];

        // array();
        // ~array();

        // array(const array& v);
        // array& operator=(const array& v);

        // array(array&& v);
        // array& operator=(array&& v);

        unsigned size() const
        {
            return N;
        }

        T& operator[](unsigned i)
        {
            // Verbesserungsvorschlag: Index pruefen
            return this->a[i];
        }

        const T& operator[](unsigned i) const
        {
            // Verbesserungsvorschlag: Index pruefen
            return this->a[i];
        }

        typedef T* iterator;
        typedef const T* const_iterator;

        iterator begin()
        {
            return &this->a[0];
        }

        iterator end()
        {
            return &this->a[N];
        }

        const_iterator begin() const
        {
            return &this->a[0];
        }

        const_iterator end() const
        {
            return &this->a[N];
        }
    };
}

#endif

