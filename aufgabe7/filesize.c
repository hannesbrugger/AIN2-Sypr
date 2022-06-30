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

	if (argc < 2)
	{
		uintmax_t n = 0;
		unsigned char b;
		while (read(0, &b, 1) > 0)
		{
			++n;
		}
		printf("Size: %"PRIuMAX" Byte\n", n);
		return 0;
	}

	struct stat buf;

	for (int i = 1; i < argc; ++i)
    {
		if (stat(argv[i], &buf) != 0)
		{
			perror(argv[i]);
			continue;
		}
		printf("%s: %"PRIuMAX" Byte\n", argv[i], (uintmax_t)buf.st_size);
	}
	return 0;
}