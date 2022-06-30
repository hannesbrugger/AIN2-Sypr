#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "de_DE");

    if(argc == 1)
    {
        char buf;
        uintmax_t counter = 0;
        /*if(read(0, &buf, &t) == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }*/

        while(read(0, &buf, 1) > 0) // On error, -1 is returned, and errno is set appropriately. 0 means EOF.
        {
            counter += 1;

            //read(0, &s, &t);
            //counter += t;
        }

        printf("Filesize: %"PRIuMAX" Byte\n", (uintmax_t)counter);
        return 0;
    }


    struct stat st;
    uintmax_t sizeCounter = 0;
    for (int i = 1; i < argc; ++i)
    {
        if (stat(argv[i], &st) == -1) // On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
        {
            perror(argv[i]);
            continue;
        }
        printf("%s: %"PRIuMAX" Byte\n", argv[i], (uintmax_t)st.st_size);
        sizeCounter += st.st_size;
    }
    printf("Filesize byte sum: %"PRIuMAX" Byte\n", sizeCounter);
    return 0;
}
