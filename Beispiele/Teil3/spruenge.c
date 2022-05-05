/*
 * spruenge.c
 *
 * Version von while-Schleife.c mit ausfuehrliche Fehlerbehandlung
 * als Beispiel fuer die Verwendung von break, continue, return.
 * Liest wie while-Schleife.c beliebig viele Zahlen ein und
 * gibt deren Summe aus.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 28.6.2019
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("Zahlen eingeben (Ende mit Strg-D): ");

    int sum = 0;
    while (1) // Endlos-Schleife, alternativ auch: for (;;)
    {
        //------------------------------------------------ Eingabe lesen
        int n;
        int i = scanf("%d", &n);

        //-------------------------------------- Eingabefehler behandeln
        if (i == EOF)
        {
            // Fehlerursache: Benutzer hat Strg-D eingegeben
            fprintf(stderr, "*** Eingabeende\n");
            break;  // hinter die Schleife springen
        }
        else if (i == 0)
        {
            // Fehlerursache: Der Benutzer hat keine Ziffern eingegeben
            fprintf(stderr, "*** Eingabe ist keine ganze Zahl: ");

            //  Falsche Zeichen entfernen
            int c;
            while ((c = getchar()) != EOF && !isspace(c))
            {
                putc(c, stderr);
            }

            putc('\n', stderr);
            continue;  // zum naechsten Schleifendurchlauf springen
        }

        //------------------------------------------------- aufsummieren
        sum += n;
    }

    printf("Summe: %d\n", sum);

    return 0; // normales Programmende
}

