/*
 * count.c
 *
 * Zaehlt die Zeichen in Dateien.
 *
 * Author H.Drachenfels
 * Erstellt am: 13.8.2020
 */

#include <stdio.h>    // fopen, fgetc, fclose, ferror, perror
#include <stdint.h>   // intmax_t
#include <inttypes.h> // PRIdMAX

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            perror(argv[i]);
            continue;
        }

        uintmax_t n = 0;
        while (fgetc(fp) != EOF)
        {
            ++n;
        }

        if (ferror(fp))
        {
            perror(argv[i]);
            fclose(fp);
            continue;
        }

        printf("%s: %"PRIuMAX" Byte\n", argv[i], n);
        fclose(fp);
    }

    return 0;
}

