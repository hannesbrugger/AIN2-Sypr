/*
 * htwg_string_test.cpp
 *
 * Beispiel-Anwendung fuer die stark vereinfachte String-Klasse
 *
 * Autor: H.Drachenfels
 * Erstellt am: 6.11.2019
 */

#include <iostream>
#include "htwg_string.h"

namespace
{
    htwg::string hallo();
}

int main()
{
    htwg::string s0; // Default-Konstruktor
    std::cout << s0.length() << '\n'; // gibt 0 aus

    htwg::string s1("Hallo"); // Konstruktor mit Parameter const char*
    std::size_t len = s1.length();
    std::cout << len << '\n'; // gibt 5 aus

    htwg::string s2 = s1; // Copy-Konstruktor
    std::cout << s2.c_str() << '\n'; // gibt Hallo aus

    s2 += s1; // s2.operator+=(s1)
    std::cout << s2.length() << '\n'; // gibt 10 aus
    std::cout << s2.c_str() << '\n';  // gibt HalloHallo aus
    std::cout << std::boolalpha;
    std::cout << (s1 < s2) << '\n'; // operator<(s1, s2) liefert true
    std::cout << ("Hallo" < s2) << '\n'; // operator<(s1, s2) liefert true
    std::cout << (s2 < s1) << '\n'; // operator<(s2, s1) liefert false
    std::cout << (s2 < "Hallo") << '\n'; // operator<(s2, s1) liefert false

    s2 = s1; // s2.operator=(s1)
    std::cout << s2.c_str() << '\n'; // gibt Hallo aus

    htwg::string s3 = hallo(); // Move-Konstruktor (i.d.R. wegoptimiert)
    std::cout << s3.c_str() << '\n'; // gibt Hallo aus

    s3 = hallo(); // Move-Zuweisung
    std::cout << s3.c_str() << '\n'; // gibt Hallo aus
}

namespace
{
    htwg::string hallo()
    {
        return htwg::string{"Hallo"};
    }
}

