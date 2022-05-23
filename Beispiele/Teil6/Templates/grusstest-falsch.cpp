/*
 * grusstest-falsch.cpp
 *
 * Autor: H.Drachenfels
 * Erstellt am: 20.11.2020
 */

#include "gruss.h"
#include <iostream>
#include <string>

int main()
{
    try
    {
        gruss<std::string> g; // falsch: std::string ist keine Uhr
        std::cout << g.gruessen() << std::endl;

        gruss<int> h; // falsch: int ist keine Uhr
        int stunde, minute;
        while (std::cin >> stunde >> minute)
        {
            h.uhr.stellen(stunde, minute);
            std::cout << h.gruessen() << std::endl;
        }
    }
    catch (std::string &s)
    {
        std::cerr << s << std::endl;
    }
}

