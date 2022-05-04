#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void bubblesort(char **words, int n);
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
    
    char **words = (char **)malloc(n * sizeof(char *));
    if (words == NULL)
    {
        printf("Speicherzuweisung fehlgeschlagen\n");
        return 1;
    }
    int size_s = 0;
    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i)
    {
        words[i] = (char *) malloc(strlen(argv[1]) + sizeof(char));
		if (words[i] == NULL)
		{
			printf("Speicherzuweisung fehlgeschlagen\n");
			return 1;
		}
		size_s += sprintf(words[i], "%d", rand() % n);
		printf("%s ", (char *) words[i]);
    }

    printf("\n");
    bubblesort(words, n);

    printf("Sortiertes Array:\n");
    
    char *s = (char *) malloc(size_s + n);
    if (s == NULL)
    {
        printf("Speicherzuweisung fehlgeschlagen\n");
        return 1;
    }

    strcpy(s, words[0]);

    for (int i = 1; i < n; ++i)
    {
        if (strcmp(words[i], words[i - 1]) == 0)
        {
            strcat(s, "*");
        }
        else
        {
            strcat(s, " ");
            strcat(s, words[i]);
        }
        
    }

    for (int i = 0; i < n; ++i)
    {
        free(words[i]);
    }
    
    free(words);
    printf("%s\n", (char *)s);

    free(s);
    return 0;
}

void bubblesort(char **words, int n)
{
    for (int i = n; i > 1 ; --i)
    {
        // groessten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                // Werte tauschen
                char *tmp = words[j + 1];
                words[j + 1] = words[j];
                words[j] = tmp;
            }
        }
    }
}
