#include "gruss.h"
#include <string>
#include <iostream>

using namespace std;

void gruss::ausgeben(const string& vorname)
{
	//if (vorname.compare("Sepp") == 0)
	string GRUSS_FORMAT = "{} {}!\n";
	if (vorname == "Sepp")
	{
		//cout << format(GRUSS_FORMAT, "Servus", vorname);
		cout << "Servus " << vorname << "!" << endl;
	} else {
		cout << "Hallo " << vorname << "!" << endl;
	}
}
