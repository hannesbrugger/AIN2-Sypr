/*
 * do-schleife.c
 *
 * Gibt eine Zahl zwischen 0 und 255 binaer aus
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015 / 10.11.2017 (C11)
 */

#include <stdio.h>

int main(void)
{
    int n = 0;
  
    // Dezimalzahl einlesen
    do
    {
        printf("Zahl zwischen 0 und 255 eingeben: ");
    }
    while (scanf("%d", &n) == 1 && (n < 0 || n > 255));

    // Binaerzahl ausgeben
    printf("       "); // sieben Leerzeichen

    do
    {
        printf("%d\b\b", n % 2);
        n /= 2;
    }
    while (n > 0);

    printf("\n");

    return 0;
}

