// leistung.c
#include "leistung.h"
#include "spo3_ain2.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#define STR2(x) #x
#define STR(X) STR2(X)

bool leistung_einlesen(struct leistung *leistung);
void ausgeben(struct leistung *leistung);
static void ausgeben_benotet(int note);
static void ausgeben_unbenotet(char status);

bool leistung_einlesen(struct leistung *leistung)
{
    int note;
    char status;
    if (scanf("%" STR(MODUL_SIZE) "s", leistung->modul) == 0)
    {
        return false;
    }
    if (scanf("%d", &note) > 0)
    {
        leistung->note = note;
        leistung->u_type = benotet;
    }
    else if (scanf("%c", &status) > 0)
    {
        leistung->status = status;
        leistung->u_type = unbenotet;
    }
    else
    {
        return false;
    }
    char *ptr = leistung->modul;
    while((ptr = strchr(ptr, '_')) != NULL)
    {
        *ptr++ = ' ';
    }
    return true;
}

void ausgeben(struct leistung *leistung)
{
    if (!ist_ain2_modul(leistung->modul))
    {
        printf("Fehler: %s", leistung->modul);
    }
    else
    {
        printf("%-*s\t", MODUL_SIZE, leistung->modul);
        if (leistung->u_type == benotet)
        {
            printf("L\t");
            ausgeben_benotet(leistung->note);
        }
        else
        {
            printf("S\t");  
            ausgeben_unbenotet(leistung->status);   
        }
    }
    printf("\n");
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
