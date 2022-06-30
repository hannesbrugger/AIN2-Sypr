#include "stdio.h"
#include "gruss.h"

int main()
{
	printf("Bitte Vorname eingeben: ");
	const char *vorname;

	if(scanf("%s", &vorname) == 0)
	{
		return 1;
	}

	ausgeben(&vorname);

	return 0;
}