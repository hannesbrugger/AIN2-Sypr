#include "leistung.h"
#include "spo3_ain2.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

// Zusatzaufgabe (bei scanf Variable Stringlänge)
#define STR2(x) #x
#define STR(X) STR2(X)

bool leistung_einlesen(struct leistung *leistung);
void ausgeben(struct leistung *leistung);
static void ausgeben_benotet(int note);
static void ausgeben_unbenotet(char status);

bool leistung_einlesen(struct leistung *leistung)
{
    leistung->modul = malloc(MODUL_SIZE);
    if (leistung->modul == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen\n");
        return false;;
    }
    int note;
    char status;

    // Modul einlesen
    // Zusatzaufgabe (bei scanf Variable Stringlänge)
    if (scanf("%" STR(MODUL_SIZE) "s", leistung->modul) == 0)
    {
        free(leistung->modul);
        return false;
    }
    
    // Wenn benotete Leistung
    if (scanf("%d", &note) > 0)
    {
        leistung->note = note;
        leistung->u_type = benotet;
    }
    // Wenn unbenotete Leistung
    else if (scanf("%c", &status) > 0)
    {
        leistung->status = status;
        leistung->u_type = unbenotet;
    }
    // Fehleingabe
    else
    {
        free(leistung->modul);
        return false;
    }
    
    char *ptr = leistung->modul;
    // Alle _ mit Leerzeichen ersetzen
    while((ptr = strchr(ptr, '_')) != NULL)
    {
        *ptr++ = ' ';
    }

    return true;
}

void ausgeben(struct leistung *leistung)
{
    // Wenn Modulname nicht in SPO, mit Zusatz "Fehler"
    if (!ist_ain2_modul(leistung->modul))
    {
        printf("Fehler: %s", leistung->modul);
    }
    else
    {
        // Modulnamen mit 20 Stellen ausgeben
        printf("%-*s\t", MODUL_SIZE, leistung->modul);

        // Bennotete Leistung
        if (leistung->u_type == benotet)
        {
            printf("L\t");
            ausgeben_benotet(leistung->note);
        }
        // Unbenotete Leistung
        else
        {
            printf("S\t");  
            ausgeben_unbenotet(leistung->status);   
        }
    }
    printf("\n");
    free(leistung->modul);
}

static void ausgeben_benotet(int note)
{
    if (ist_spo_note(note))
    {
        printf("%d,%d", note / 10, note % 10);
    }
    else
    {
        printf("Fehler: %d", note);
    }
}

static void ausgeben_unbenotet(char status)
{
    if (status == 'B')
    {
        printf("bestanden");
    }
    else if (status == 'N')
    {
        printf("nicht bestanden");
    }
    else
    {
        printf("Fehler: %c", status);
    }
}
