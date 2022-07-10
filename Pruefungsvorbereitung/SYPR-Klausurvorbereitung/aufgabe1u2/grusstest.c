// grusstest.c
#include <stdio.h>
#include <stdlib.h>
#include "gruss.h"

int main()
{
	printf("Bitte Vorname eingeben: ");

	char *vorname = (char *) malloc(21);
	
	if(scanf("%s", vorname) == 0)
	{
		return 1;
	}
	ausgeben(vorname);
	free(vorname);
	return 0;
}
