#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int get_random_value(int max);
void bubblesort(void *a, int n, int m, int (*cmp)(const void *, const void *));
int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    //--------------------------------------------- Arraygroesse bestimmen
    if (argc != 2)
    {
        fprintf(stderr, "Aufruf: ./stringsort Anzahl\n");
        return 1;
    }
    if (atoi(argv[1]) < 1)
    {
        fprintf(stderr, "Anzahl muss mindestens 1 sein\n");
        return 1;
    }

    //--------------------------------------------------- Strings wuerfeln
    int n = atoi(argv[1]);
    int m = strlen(argv[1]) + 1;

    char *a = (char *)malloc(n * m);
    if (a == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }
    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i)
    {
        sprintf(a + m * i, "%d", get_random_value(n));
        printf("%s ", a + m * i);
    }

    //-------------------------------------------------- Strings sortieren

    bubblesort(a, n, m, (int (*)(const void *, const void *))strcmp);

    //--------------------------------------------------- Strings ausgeben

    printf("\nSortiertes Array:\n");

    char *s = (char *)malloc(m * n);
    if (s == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }
    s = memcpy(s, a, m);

    for (int i = 1; i < n; ++i)
    {
        if (strcmp(a + m * i, a + m * (i - 1)) == 0)
        {
            s = strcat(s, "*");
        }
        else
        {
            strcat(s, " ");
            strcat(s, a + m * i);
        }
    }

    free(a);
    printf("%s\n", (char *)s);
    free(s);

    return 0;
}
int get_random_value(int max)
{
    max -= 1;
    return (rand() % (max + 1));
}

void bubblesort(void *a, int n, int m, int (*cmp)(const void *, const void *))
{
    char *tmp = (char *)malloc(n * sizeof(char));
    if (tmp == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        exit(1);
    }
    for (int i = n; i > 1; --i)
    {
        // groessten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (cmp((char *)a + (m * j), (char *)a + m * (j + 1)) > 0)
            {
                memcpy(tmp, (char *)a + m * (j + 1), m);
                memcpy((char *)a + m * (j + 1), (char *)a + m * j, m);
                memcpy((char *)a + m * j, tmp, m);
            }
        }
    }
    free(tmp);
}