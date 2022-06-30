#define _POSIX_C_SOURCE 1
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <locale.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    setlocale(LC_MESSAGES, "de_DE.UTF-8");

	if (argc != 3)
	{
		fprintf(stderr, "Aufruf mit Parameter source und destination\n");
		return 1;
	}

	int src = open(argv[1], O_RDONLY);
	if(src < 0)
	{
		perror(argv[1]);
		exit(1);
	}

	struct stat st;

	if(fstat(src, &st) != 0)
	{
		perror(argv[1]);
		exit(1);
	}

	int *size = (int *)malloc(st.st_size);
	if(size == NULL)
	{
		fprintf(stderr, "Speicherreservierung fehlgeschlagen!\n");
		return 1;
	}

	ssize_t reader = 0;
	if((reader = read(src, size, st.st_size)) == -1)
	{
		fprintf(stderr, "Lesefehler %d: %s\n", errno, strerror(errno));
		free(size);
		return 1;
	}

	const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int dest = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, mode);
	if(dest < 0)
	{
		perror(argv[2]);
		exit(1);
	}

	ssize_t writer = 0;
	if((writer = write(dest, size, st.st_size)) == -1)
	{
		fprintf(stderr, "Schreibfehler %d: %s\n", errno, stderror(errno));
		free(size);
		return 1;
	}
	else if(writer != st.st_size)
	{
		fprintf(stderr, "Fehler beim Kopieren!\n");
		free(size);
		return 1;
	}

	close(src);
	close(dest);
	free(size);
	
	return 0;
}