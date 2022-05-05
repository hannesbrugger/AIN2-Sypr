/*
 * charliteral.c
 *
 * Beispiel-Programm Zeichen-Literale
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015
 */

#include <stdio.h>

int main(void)
{
    printf("%s\n", "Hallo");
    printf("%s\n", "Hal" "lo");
    printf("Hallo\n");
    printf("%c%c%c%c%c\n", 'H', 'a', 'l', 'l', 'o');
    return 0;
}

