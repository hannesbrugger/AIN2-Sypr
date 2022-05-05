/*
 * structvar.c
 *
 * Beispiel-Programm struct-Variable
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015 / 10.11.2017 (C11)
 */

#include  <stdio.h>

struct date
{
  int day;
  const char *month;
  int year;
};

int main(void)
{
    struct date d = {1, "September", 2000};

    //--------------------------------------------- print variable value
    printf("%d. %s %d\n", d.day, d.month, d.year);

    //------------------------------------------- print variable address
    printf("&d = %p\n", (void*) &d);
    printf("&d.day = %p\n", (void*) &d.day);
    printf("&d.month = %p\n", (void*) &d.month);
    printf("&d.year = %p\n", (void*) &d.year);

    //---------------------------------------------- print variable size
    printf("sizeof d = %zu\n", sizeof d);

    return 0;
}

