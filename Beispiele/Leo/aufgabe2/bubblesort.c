#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));

    //---------------------------------------------- Arraygroesse einlesen
    if (argc < 2)
    {
        printf("Aufruf: bubblesort Anzahl\n");
        return 0;
    }
    int n = atoi(argv[1]);
    int *a = calloc(n, sizeof(int));

    //---------------------------------------------------- Zahlen einlesen
    printf("Bitte %d ganze Zahlen eingeben: \n", n);
    int k = 0;
    for (int i = 0; i < n && (scanf("%d", &a[i]) > 0); ++i)
    {
        ++k;
    }

    for (int i = k; i < n; ++i)
    {

        a[i] = rand();
        printf("%d\n", a[i]);
    }

    //--------------------------------------------------- Zahlen sortieren
    for (int i = n; i > 1; --i)
    {
        // groessten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                // Werte tauschen
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

    //---------------------------------------------------- Zahlen ausgeben
    printf("Sortierte Zahlenfolge: \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", a[i]);
    }

    free(a);
    return 0;
}
