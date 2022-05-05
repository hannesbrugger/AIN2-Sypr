/*
 * doubleliteral.c
 *
 * Beispiel-Programm Gleitkomma-Literale
 *
 * Autor: H.Drachenfels
 * Erstellt am: 26.10.2018
 */

#include <stdio.h>

int main(void)
{
    printf("%g\n", (1e-30 + 1e30) - 1e30);
    printf("%g\n", 1e-30 + (1e30 - 1e30));
    printf("%f\n", 12.3456789);
    printf("%Lf\n", 1234567.89L);
    printf("%e\n", 12.3456789);
    printf("%Le\n", 1234567.89L);
    return 0;
}

