#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	if (argc < 2)
	{
		return 1;
	}

	int c = 0;

	for (int i = 1; i < argc; i++)
	{
		c += atoi(argv[i]);
	}

	printf("Ergebnis: %d\n", c);
	
	
	return 0;
}
