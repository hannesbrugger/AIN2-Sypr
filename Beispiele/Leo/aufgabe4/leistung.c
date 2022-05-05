#include "leistung.h"
#include "spo3_ain2.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 21

void ausgeben(struct leistung *l);
bool leistung_einlesen(struct leistung *l);
bool ist_spo_note(int n);
bool ist_ain2_modul(const char *course);
static void ausgeben_benotet(int note);
static void ausgeben_unbenotet(char status);

bool leistung_einlesen(struct leistung *l)
{
    l->course = malloc(SIZE);
    if (l->course == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen");
        return false;
    }
    char *ptr;
    int note;
    char bewertung;

    if (scanf("%21s", l->course) == 0)
    {
        free(l->course);
        return false;
    }

    ptr = strchr(l->course, '_');
    while (ptr != NULL)
    {
        *ptr = ' ';
        ptr = strchr(ptr + 1, '_');
    }

    if (scanf("%d", &note) > 0)
    {
        l->la = benotet;
        l->grade = note;
        return true;
    }
    else if (scanf("%c", &bewertung) > 0)
    {
        l->la = unbenotet;
        l->passed = bewertung;
        return true;
    }
    else
    {
        free(l->course);
        return false;
    }
}

void ausgeben(struct leistung *l)
{
    if (!ist_ain2_modul(l->course))
    {
        printf("Fehler: %s\n", l->course);
    }
    else if (l->la == benotet)
    {
        printf("%-20s\tL\t", l->course);
        ausgeben_benotet((int)l->grade);
    }
    else if (l->la == unbenotet)
    {
        printf("%-20s\tS\t", l->course);
        ausgeben_unbenotet(l->passed);
    }
    // sicherer free
    free(l->course);
}

static void ausgeben_benotet(int note)
{
    if (ist_spo_note(note) == false)
    {
        printf("Fehler: %d\n", note);
    }
    else
    {
        char *str = malloc(4);
        if (str == NULL)
        {
            printf("Speicherreservierung fehlgeschlagen!\n");
            exit(1);
        }
        sprintf(str, "%d", note);
        char *output = malloc(4);
        if (output == NULL)
        {
            printf("Speicherreservierung fehlgeschlagen!\n");
            exit(1);
        }

        memcpy(output, str, 1);
        memcpy(output + 1, ",", 1);
        memcpy(output + 2, str + 1, 1);
        free(str);

        memcpy(output + 3, "\0", 1);
        printf("%s\n", output);
        free(output);
    }
}

static void ausgeben_unbenotet(char status)
{
    if (status == 'B')
    {
        printf("bestanden\n");
    }
    else if (status == 'N')
    {
        printf("nicht bestanden\n");
    }
    else
    {
        printf("Fehler: %c\n", status);
    }
}