#include <stdbool.h>

#ifndef LEISTUNG_H
#define LEISTUNG_H

enum leistungsart { benotet, unbenotet };

struct leistung
{
    enum leistungsart u_type;

    union
    {
        int note;
        char best;
    };
    
};

typedef struct leistung leistung;

bool leistung_einlesen(struct leistung *leistung);
void ausgeben(struct leistung *leistung);

#endif
