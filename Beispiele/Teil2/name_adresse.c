/*
 * name_adresse.c
 *
 * Beispiel-Programm Speichernutzung per Name oder Adresse
 *
 * Autor: H.Drachenfels
 * Erstellt am: 30.10.2015 / 10.11.2017 (C11)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    {
       // Speichernutzung per Wertvariable:
       int a = 0;
       int b = 1;

       b = a;

       printf("a = %d\n", a);
       printf("b = %d\n", b);
    }

    {
        // Speichernutzung per Zeigervariable:
        int *a = (int*) calloc(1, sizeof (int));
        int *b = (int*) malloc(sizeof (int));

        if (a == NULL || b == NULL)
        {
            printf("Speicherallokierungsfehler\n");
            return 1;
        }

        *b = 1;

        *b = *a;

        printf("*%p = %d\n", (void*) a, *a);
        printf("*%p = %d\n", (void*) b, *b);

        free(a);
        free(b);
    }

    return 0;
}

