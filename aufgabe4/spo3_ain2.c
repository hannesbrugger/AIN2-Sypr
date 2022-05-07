#include "spo3_ain2.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ist_spo_note(int note);
bool ist_ain2_modul(const char *modul);

bool ist_spo_note(int note)
{
    switch (note)
    {
    case 10:
    case 13:
    case 17:
    case 20:
    case 23:
    case 27:
    case 30:
    case 33:
    case 37:
    case 40:
    case 50:
        return true;
    default:
        return false;
    }
}

bool ist_ain2_modul(const char *modul)
{
    if (strcmp(modul, "Systemprogrammierung") == 0)
    {
        return true;
    }
    else if (strcmp(modul, "Programmiertechnik 2") == 0)
    {
        return true;
    }
    else if (strcmp(modul, "Mathematik 2") == 0)
    {
        return true;
    }
    else if (strcmp(modul, "Rechnerarchitekturen") == 0)
    {
        return true;
    }
    else if (strcmp(modul, "Stochastik") == 0)
    {
        return true;
    }
    return false;
}
