#include "gruss.h"
#include <string>
#include <iostream>

using namespace std;

void gruss::ausgeben(const string& vorname)
{
	string GRUSS_FORMAT = "{} {}!\n";
	if (vorname == "Sepp")
	{
		cout << "Servus " << vorname << "!" << endl;
	} else {
		cout << "Hallo " << vorname << "!" << endl;
	}
}
