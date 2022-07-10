// leistung.h
#include <stdbool.h>

#ifndef LEISTUNG_H
#define LEISTUNG_H

#define MODUL_SIZE 20

enum leistungsart { benotet, unbenotet };

struct leistung
{
    enum leistungsart u_type;
    char modul[MODUL_SIZE+1];

    union
    {
        int note;
        char status;
    };
    
};

typedef struct leistung leistung;

bool leistung_einlesen(struct leistung *leistung);
void ausgeben(struct leistung *leistung);

#endif
