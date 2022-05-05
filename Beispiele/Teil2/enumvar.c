/*
 * enumvar.c
 *
 * Beispiel-Programm enum-Variable
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015 / 10.11.2017 (C11)
 */

#include <stdio.h>

enum month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

int main(void)
{
    // enum month m = 3; // funktioniert bei C, aber nicht bei C++
    enum month m = mar;

    //---------------------------------------------- print variable value
    printf("m = %d\n", m);

    //-------------------------------------------- print variable address
    printf("&m = %p\n", (void*) &m);

    //----------------------------------------------- print variable size
    printf("sizeof m = %zu\n", sizeof m);

    return 0;
}

