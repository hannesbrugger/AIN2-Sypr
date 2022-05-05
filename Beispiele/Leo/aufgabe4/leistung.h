#include <stdbool.h>
#include <stdlib.h>
#ifndef LEISTUNG_H
#define LEISTUNG_H

enum leistungsart
{
    benotet,
    unbenotet
};
struct leistung
{
    char *course;
    enum leistungsart la;
    union
    {
        int grade;   // wenn benotet
        char passed; // wenn unbenotet
    };
};
typedef struct leistung leistung;
bool leistung_einlesen(struct leistung *l);
void ausgeben(struct leistung *l);
// static void ausgeben_benotet(int note);
// static void ausgeben_unbenotet(char status);
#endif
