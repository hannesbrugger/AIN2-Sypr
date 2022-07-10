#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		return 1;
	}

	char *s = argv[1];
	char *t = argv[2];
	char *st = (char *) malloc(strlen(s) + strlen(t) + 1);
	strcpy(st, s);
	strcat(st, t);
	return 0;	
}
// hallo
