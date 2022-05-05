/*
 * constpointer.c
 *
 * Beispiel-Programm Zeiger-Variable
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.3.2021
 */

#include <stdio.h>

int main(void)
{
    const int i = 0;
    const int *p = &i;

    int j = 0;
    int * const q = &j;

    // *p = 0; // Fehler, *p konstant
    p = NULL;

    *q = 0;
    // q = NULL; // Fehler, q konstant

    return 0;
}

