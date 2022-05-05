/*
 * aufgabe1.c
 *
 * Lorem ipsum.
 *
 * Autor: Leo Tschritter
 * Erstellt am: 29.03.2022
 */
#include <stdio.h>
#define getName(var) #var

int main(void)
{

    int zahl1 = 123123123;
    short int zahl2 = -32768;
    long int zahl3 = 123123123123L;
    long long int zahl4 = 123123123123123LL;

    unsigned int zahl5 = 123123123U;
    unsigned short int zahl6 = 65535U;
    unsigned long int zahl7 = 123UL;
    unsigned long long int zahl8 = 123ULL;

    float zahl9 = 12.3456789;
    double zahl10 = 12.3456789;
    long double zahl11 = 1234567.89L;

    char zeichen1 = 'a';
    signed char zeichen2 = -1;
    unsigned char zeichen3 = 0xff;

    _Bool boolean = 1;
    char *s = "Hallo";

    // Adresse, Platzbedarf, Typ, Name und Wert ausgeben
    printf("Adresse\t\tPlatzbedarf\tName\t\tWert\n");
    printf("%p\t%zu\t\t%s\t\t%d\n", (void *)&zahl1, sizeof(int), getName(zahl1), zahl1);
    printf("%p\t%zu\t\t%s\t\t%d\n", (void *)&zahl2, sizeof(short int), getName(zahl2), zahl2);
    printf("%p\t%zu\t\t%s\t\t%ld\n", (void *)&zahl3, sizeof(long int), getName(zahl3), zahl3);
    printf("%p\t%zu\t\t%s\t\t%lld\n", (void *)&zahl4, sizeof(long long int), getName(zahl4), zahl4);

    printf("%p\t%zu\t\t%s\t\t%d\n", (void *)&zahl5, sizeof(unsigned int), getName(zahl5), zahl5);
    printf("%p\t%zu\t\t%s\t\t%d\n", (void *)&zahl6, sizeof(unsigned short int), getName(zahl6), zahl6);
    printf("%p\t%zu\t\t%s\t\t%ld\n", (void *)&zahl7, sizeof(unsigned long int), getName(zahl7), zahl7);
    printf("%p\t%zu\t\t%s\t\t%lld\n", (void *)&zahl8, sizeof(unsigned long long int), getName(zahl8), zahl8);

    printf("%p\t%zu\t\t%s\t\t%f\n", (void *)&zahl9, sizeof(float), getName(zahl9), zahl9);
    printf("%p\t%zu\t\t%s\t\t%f\n", (void *)&zahl10, sizeof(double), getName(zahl10), zahl10);
    printf("%p\t%zu\t\t%s\t\t%Lf\n", (void *)&zahl11, sizeof(long double), getName(zahl11), zahl11);

    printf("%p\t%zu\t\t%s\t%d\n", (void *)&zeichen1, sizeof(char), getName(zeichen1), zeichen1);
    printf("%p\t%zu\t\t%s\t%d\n", (void *)&zeichen2, sizeof(signed char), getName(zeichen2), zeichen2);
    printf("%p\t%zu\t\t%s\t%d\n", (void *)&zeichen3, sizeof(unsigned char), getName(zeichen3), zeichen3);

    printf("%p\t%zu\t\t%s\t\t%d\n", (void *)&boolean, sizeof(_Bool), getName(boolean), boolean);
    printf("%p\t%zu\t\t%s\t\t%s\n", (void *)&s, sizeof(char *), getName(s), s);

    return 0;
}
