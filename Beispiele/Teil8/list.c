/*
 * list.c
 *
 * Listet Verzeichnisse auf.
 * Verwendet Funktionen nach POSIX-Standard.
 *
 * Author H.Drachenfels
 * Erstellt am: 15.6.2015 / 8.3.2018 (C11)
 */

#define _POSIX_C_SOURCE 1

#include <stdio.h>  // fprintf, printf
#include <string.h> // strerror

#include <sys/stat.h> // struct stat, S_ISDIR
#include <dirent.h>   // DIR, struct dirent, opendir, readdir
#include <errno.h>    // errno

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        struct stat s; // Dateistatus
        if (stat(argv[i], &s) == -1)
        {
            fprintf(stderr, "%s existiert nicht (errno %d: %s)\n",
                    argv[i], errno, strerror(errno));
            continue;
        }

        if (!S_ISDIR(s.st_mode))
        {
            fprintf(stderr, "%s ist kein Verzeichnis\n", argv[i]);
            continue;
        }

        DIR *d = opendir(argv[i]); // geoeffnetes Verzeichnis
        if (d == NULL)
        {
            fprintf(stderr, "%s kann nicht geoeffnet werden (errno %d: %s)\n",
                    argv[i], errno, strerror(errno));
            continue;
        }

        errno = 0;

        struct dirent *e; // gelesener Verzeichniseintrag
        while ((e = readdir(d)) != NULL)
        {
            printf("%s/%s\n", argv[i], e->d_name);
        }

        if (errno)
        {
            fprintf(stderr, "Lesefehler in %s (errno %d: %s)\n",
                    argv[i], errno, strerror(errno));
        }

        closedir(d);
    }

    return 0;
}

