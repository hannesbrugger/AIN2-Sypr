// grusstest.cpp
#include <string>
#include <iostream>
#include "gruss.h"

using namespace std;
int main(void)
{
	cout << "Bitte Vorname eingeben: \n";
	string vorname;
	if (!(cin >> vorname))
	{
		cerr << "Eingabefehler!\n";
		return 1;
	}
	gruss::ausgeben(vorname);
	return 0;
}
