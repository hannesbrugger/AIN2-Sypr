#include <stdio.h>
#include <stdlib.h>
#include "wuerfel.h"

int main(int argc, const char *argv[])
{
	double k;
	if (argc < 2)
	{
		//return 1;
	}
	
	if (sscanf(argv[1], "%lf", &k) < 1)
	{
		return 1;
	}

	double f = oberflaeche(k);
	double v = volumen(k);
	printf("Kantenlaenge %f, Oberflaeche %f, Volumen %f\n", k, f, v);
	
	return 0;
}
