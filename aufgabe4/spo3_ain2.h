#include <stdbool.h>

#ifndef SPO3_AIN2_H
#define SPO3_AIN2_H

bool ist_spo_note(int note);
bool ist_ain2_modul(const char *modul);

#define SPO_BESTE_NOTE 10
#define SPO_SCHLECHTESTE_NOTE 50
#define AIN2_ANZAHL_LEISTUNGEN 11

#endif
