#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int get_random_value(int max);
void bubblesort(char **a, int n);
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
    int m = strlen(argv[1]) + sizeof(char);
    char **a = (char **)malloc(n * sizeof(char *));
    if (a == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }
    int buff_size_s = 0;
    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i)
    {
        a[i] = (char *)malloc(m);
        if (a[i] == NULL)
        {
            printf("Speicherreservierung fehlgeschlagen!\n");
            return 1;
        }
        buff_size_s += sprintf(a[i], "%d", get_random_value(n));
        printf("%s ", (char *)a[i]);
    }
    //-------------------------------------------------- Strings sortieren
    bubblesort(a, n);

    //--------------------------------------------------- Strings ausgeben
    printf("\nSortiertes Array:\n");
    char *s = (char *)malloc(buff_size_s + n);
    if (s == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }
    s = strcpy(s, a[0]);
    for (int i = 1; i < n; ++i)
    {
        if (strcmp(a[i], a[i - 1]) == 0)
        {
            s = strcat(s, "*");
        }
        else
        {
            strcat(s, " ");
            strcat(s, a[i]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        free(a[i]);
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

void bubblesort(char **a, int n)
{
    for (int i = n; i > 1; --i)
    {
        // groessten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                // Werte tauschen
                char *tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}