/*
 * for-schleife.c
 *
 * Gibt alle Elemente eines Felds aus
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015 / 10.11.2017 (C11)
 */

#include <stdio.h>

int main(void)
{
    int an_array[] = {3082, 3101, 3275, 3436};
    const int array_size = (int) (sizeof an_array / sizeof *an_array);

    for (int i = 0; i < array_size; ++i)
    {
        printf("%d\n", an_array[i]);
    }

    return 0;
}

