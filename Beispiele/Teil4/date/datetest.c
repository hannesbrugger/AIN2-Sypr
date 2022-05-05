/*
 * datetest.c
 *
 * Beispiel-Programm Uebersetzungseinheiten
 *
 * Autor: H.Drachenfels
 * Erstellt am: 13.5.2020
 */

#include  "date.h"

int main(void)
{
    print_date(&epoch);

    date d = {1, 9, 2000};
    print_date(&d);

    return 0;
}

