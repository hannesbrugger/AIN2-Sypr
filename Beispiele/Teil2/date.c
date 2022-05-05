/*
 * date.c
 *
 * Beispiel-Programm Uebersetzungseinheiten
 *
 * Autor: H.Drachenfels
 * Erstellt am: 13.5.2020
 */

#include  "date.h"
#include  <stdio.h>

date epoch = {1, 1, 1970};

void print_date(const date *d)
{
    printf("%d.%d.%d\n", d->day, d->month, d->year);
}

