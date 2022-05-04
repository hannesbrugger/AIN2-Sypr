#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void bubblesort(void *words, int n, int m, int (*cmp)(const void *, const void *));
int main(int argc, char *argv[])
{
    srand((unsigned int) time(NULL));

    if (argc != 2)
    {
        fprintf(stderr, "Aufruf: ./stringsort Anzahl\n");
        return 1;
    }

    int n = atoi(argv[1]);

    if (n < 1)
    {
        fprintf(stderr, "Anzahl muss mindestens 1 sein\n");
        return 1;
    }

    int m = strlen(argv[1]) + 1;
    
    char *words = (char *) malloc(n * m);
    if (words == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen\n");
        return 1;
    }

    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; i++)
    {
        // Random Wert in entsprechende Speicheradresse schreiben
        sprintf(words + m * i, "%d", rand() % n);
        printf("%s ", words + m * i);
    }

    printf("\n");
    bubblesort(words, n, m, (int (*)(const void *, const void *))strcmp);
    
    printf("Sortiertes Array:\n");
    char *s = (char *) malloc(m * n);
    if (s == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen\n");
        return 1;
    }

    memcpy(s, words, m);
    for (int i = 1; i < n; i++)
    {
        if (strcmp(words + m * i, words + m * (i - 1)) == 0)
        {
            strcat(s, "*");
        }
        else
        {
            strcat(s, " ");
            strcat(s, words + m * i);
        }
    }
    
    free(words);
    printf("%s\n", (char *) s);
    free(s);

    return 0;
}

void bubblesort(void *words, int n, int m, int (*cmp)(const void *, const void *))
{
    char *tmp = (char *) malloc(n * m);
    if (tmp == NULL)
    {
        printf("Speicherzuweisung fehlgeschlagen\n");
        exit(1);
    }

    for (int i = n; i > 1; i--)
    {
        // groessten Wert nach hinten schieben
        for (int j = 0; j < i - 1; j++)
        {
            if (cmp((char *) words + m * j, (char *) words + m * (j + 1)) > 0)
            {
                memcpy(tmp, (char *) words + m * (j + 1), m);
                memcpy((char *) words + m * (j + 1), (char*) words + m * j, m);
                memcpy((char *) words + m * j, tmp, m);
            }
        }
    }
    free(tmp);
}
