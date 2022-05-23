/*
 * htwg_array_test.cpp
 *
 * Beispiel-Anwendung fuer die stark vereinfachte Array-Klasse
 *
 * Autor: H.Drachenfels
 * Erstellt am: 2.8.2019
 */

#include "htwg_array.h"
#include <iostream>
#include <algorithm>

int main()
{
    htwg::array<int, 2> a = {10, 20};
    for (unsigned i = 0; i < a.size(); ++i)
    {
        std::cout << i << ": " << a[i] << '\n';
    }

    for (auto i = a.begin(); i != a.end(); ++i)
    {
        std::cout << i << ": " << *i << '\n';
    }

    htwg::array<int, 4> b = {40, 10, 30, 20};
    int n = 10;
    auto i = std::find(b.begin(), b.end(), n);
    if (i != b.end()) {
        std::cout << i << ": " <<  *i << '\n';
    }
 
    std::sort(b.begin(), b.end());
    for (auto& n: b)
    {
        std::cout << &n << ": " << n << '\n';
    }
}

