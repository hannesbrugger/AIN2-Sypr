/*
 * main.c
 *
 * Beispiel-Programm Parameter
 *
 * Autor: H.Drachenfels
 * Erstellt am: 20.01.2011 / 10.11.2017 (C11)
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i <= argc; ++i)
    {
        printf("%d: %s\n", i, argv[i]);
    }

    return 0;
}

