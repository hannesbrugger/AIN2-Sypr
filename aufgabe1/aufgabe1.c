#include <stdio.h>
#include <stdbool.h>
#define getName(var)  #var

int main(void)
{
    int zahl_int = 10;
    short int zahl_si = 12;
    long int zahl_li = 123L;
    long long int zahl_lli = 1234LL;
    unsigned int zahl_ui = 0xffffffffU;
    unsigned short int zahl_usi = 0xffffU;
    unsigned long int zahl_uli = 0xffffffffffffUL;
    unsigned long long int zahl_ulli = 0xffffffffffffffffULL;
    float zahl_float = 3.14F;
    double zahl_double = 3.14;
    long double zahl_ld = 3.14L;
    char character = 'b';
    signed char s_char = -5;
    unsigned char u_char = 0xDE;
    bool boolean = false;
    const char* s = "Hallo";
    
    printf("Adresse\t\tPlatzbedarf\tTyp\t\t\tName\t\tWert\n");
    printf("%p\t%zu\t\t%s\t\t\t%s\t%d\n", (void*) &zahl_int, sizeof zahl_int, "Int", getName(zahl_int), zahl_int);
    printf("%p\t%zu\t\t%s\t\t%s\t\t%hd\n", (void*) &zahl_si, sizeof zahl_si, "Short Int", getName(zahl_si), zahl_si);
    printf("%p\t%zu\t\t%s\t\t%s\t\t%ld\n", (void*) &zahl_li, sizeof zahl_li, "Long Int", getName(zahl_li), zahl_li);
    printf("%p\t%zu\t\t%s\t\t%s\t%lld\n", (void*) &zahl_lli, sizeof zahl_lli, "Long Long Int", getName(zahl_lli), zahl_lli);
    printf("%p\t%zu\t\t%s\t\t%s\t\t%o\n", (void*) &zahl_ui, sizeof zahl_ui, "Unsigned Int", getName(zahl_ui), zahl_ui);
    printf("%p\t%zu\t\t%s\t%s\t%hu\n", (void*) &zahl_usi, sizeof zahl_usi, "Unsigned Short Int", getName(zahl_usi), zahl_usi);
    printf("%p\t%zu\t\t%s\t%s\t%lu\n", (void*) &zahl_uli, sizeof zahl_uli, "Unsigned Long Int", getName(zahl_uli), zahl_uli);
    printf("%p\t%zu\t\t%s\t%s\t%llu\n", (void*) &zahl_ulli, sizeof zahl_ulli, "Unsigned Long Long Int", getName(zahl_ulli), zahl_ulli);
    printf("%p\t%zu\t\t%s\t\t\t%s\t%f\n", (void*) &zahl_float, sizeof zahl_float, "Float", getName(zahl_float), zahl_float);
    printf("%p\t%zu\t\t%s\t\t\t%s\t%lf\n", (void*) &zahl_double, sizeof zahl_double, "Double", getName(zahl_double), zahl_double);
    printf("%p\t%zu\t\t%s\t\t%s\t\t%Lf\n", (void*) &zahl_ld, sizeof zahl_ld, "Long Double", getName(zahl_ld), zahl_ld);
    printf("%p\t%zu\t\t%s\t\t\t%s\t%c\n", (void*) &character, sizeof character, "Char", getName(character), character);
    printf("%p\t%zu\t\t%s\t\t%s\t\t%hhd\n", (void*) &s_char, sizeof s_char, "Signed Char", getName(s_char), s_char);
    printf("%p\t%zu\t\t%s\t\t%s\t\t%hhu\n", (void*) &u_char, sizeof u_char, "Unsigned Char", getName(u_char), u_char);
    printf("%p\t%zu\t\t%s\t\t\t%s\t\t%d\n", (void*) &boolean, sizeof boolean, "Boolean", getName(boolean), boolean);
    printf("%p\t%zu\t\t%s\t\t\t%s\t\t%s\n", (void*) &s, sizeof s, "Char*", getName(s), s);

    if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(char*) == 4)
        printf("\nILP32\n");
    else if (sizeof(int) == 4 && sizeof(long) == 8 && sizeof(char*) == 8)
        printf("\nLP64\n");
    else if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(long long) == 8 && sizeof(char*) == 8)
        printf("\nLLP64\n");
    else
        printf("\nEs handelt sich um keins der drei Modelle\n");

    return 0;
}
