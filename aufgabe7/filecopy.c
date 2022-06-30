#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Aufruf mit Parameter source und destination\n");
		return 1;
	}
	
	return 0;
}