#include "quadrat.h"

static double zumQuadrat(const double);

double flaeche(double seitenlaenge)
{
	return zumQuadrat(seitenlaenge);
}

static double zumQuadrat(const double d)
{
	return d*d;
}
