/*
 * find.cpp
 *
 * Beispiel-Programm std::find-Funktionstemplate
 *
 * Autor: H.Drachenfels
 * Erstellt am: 10.6.2020
 */

#include <iostream>
#include <algorithm>
#include <array>
//#include <vector>
//#include <list>
 
int main()
{
    {
        int a[] = {3421, 3442, 3635, 3814};
        int *begin = a; // Zeiger auf Elementtyp dienen als Iteratoren
        int *end = a + 4;

        auto i = std::find(begin, end, 3442); // I = int* und T = int
        if (i != end) {
            std::cout << *i << " ist in a enthalten\n";
        }
    }

    {
        std::array<int,4> a{3421, 3442, 3635, 3814};
        // std::vector<int> a{3421, 3442, 3635, 3814};
        // std::list<int> a{3421, 3442, 3635, 3814};
        auto begin = a.begin();
        auto end = a.end();

        auto i = std::find(begin, end, 3442);
        if (i != end) {
            std::cout << *i << " ist in a enthalten\n";
        }
    }
}

