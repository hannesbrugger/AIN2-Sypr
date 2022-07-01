#include "stdio.h"
#include "gruss.h"

int main()
{
	printf("Bitte Vorname eingeben: ");
	//char *vorname;

	const char *vorname = (char *) malloc(21);

	if(scanf("%21s", vorname) == 0)
	{
		return 1;
	}

	ausgeben(vorname);

	return 0;
}
