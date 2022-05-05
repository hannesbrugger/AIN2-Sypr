#include "spo3_ain2.h"
#include <stdbool.h>
#include <string.h>

bool ist_spo_note(int n)
{
    switch (n)
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
bool ist_ain2_modul(const char *course)
{
    if (strcmp(course, "Rechnerarchitekturen") == 0)
    {
        return true;
    }
    else if (strcmp(course, "Mathematik 2") == 0)
    {
        return true;
    }
    else if (strcmp(course, "Stochastik") == 0)
    {
        return true;
    }
    else if (strcmp(course, "Systemprogrammierung") == 0)
    {
        return true;
    }
    else if (strcmp(course, "Programmiertechnik 2") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}