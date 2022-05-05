/*
 * voidpointer.c
 *
 * Beispiel-Programm Zeiger-Variable
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015
 */

#include <stdio.h>

int main(void)
{
    float n = 1;
    void *vp = &n;
    int *ip = (int*) vp;

    printf("%x\n", *ip);

    return 0;
}

