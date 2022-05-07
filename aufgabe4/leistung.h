#include <stdbool.h>

#ifndef LEISTUNG_H
#define LEISTUNG_H

enum leistungsart { benotet, unbenotet };

struct leistung
{
    enum leistungsart u_type;
    char *modul;

    union
    {
        int note;
        char status;
    };
    
};

typedef struct leistung leistung;

bool leistung_einlesen(struct leistung *leistung);
void ausgeben(struct leistung *leistung);

#define MODUL_SIZE 21

#endif
