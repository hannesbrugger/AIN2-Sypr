/*
 * while-schleife.c
 *
 * Liest beliebig viele Zahlen ein und gibt deren Summe aus
 *
 * Autor: H.Drachenfels
 * Erstellt am: 28.6.2019
 */

#include <stdio.h>

int main(void)
{
    printf("Zahlen eingeben (Ende mit Strg-d): ");
	
    int sum = 0;
    int n;
    while (scanf("%d", &n) == 1)
    {
        sum += n;
    }

    printf("Summe: %d\n", sum);

    return 0;
}

