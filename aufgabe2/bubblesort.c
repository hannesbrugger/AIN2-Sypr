#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Falsche Parameteranzahl");
        return 1;
    }

    int n = atoi(argv[1]);
    int *a = (int *) calloc(n, sizeof(int));

    if (a == NULL)
    {
        printf("Speicherzuweisung fehlgeschlagen");
        return 1;
    }
    
    printf("Bitte %d ganze Zahl eingeben: ", n);
    int k = 0;
    for (int i = 0; i < n && scanf("%d", &a[i]) > 0; i++)
    {
        ++k;
    }

    srand(time(NULL));
    for (int i = k; i < n; i++)
    {
        a[i] = rand();
        printf("%d\n", a[i]);
    }
    
    for (int i = n; i > 1; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j+1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
            
        }
    }

    printf("\nSortierte Reihenfolge: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    
    free(a);
    
    return 0;
}
