/*
 * verzweigung.c
 *
 * Liesst zwei Zahlen ein und gibt das Maximum aus
 *
 * Autor: H.Drachenfels
 * Erstellt am: 28.6.2019
 */

#include <stdio.h>

int main(void)
{
    printf("Zwei Zahlen eingeben: ");

    int m, n;
    if  (scanf("%d%d", &m, &n) < 2)
    {
        fprintf(stderr, "Eingabefehler !\n");
    }
    else if (m > n)
    {
        printf("Maximum: %d\n", m);
    }
    else
    {
        printf("Maximum: %d\n", n);
    }

    return 0;
}

