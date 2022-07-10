#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *s1 = (char*) malloc(5 * sizeof(char));
	strcpy(s1, "Hallo");
	//s1 = "Hallo";
	char *s2 = (char*) malloc(5 * sizeof(char));
	//s2 = "Welt";
	strcpy(s2, " Welt");
	printf("Size S1: %lu\n", strlen(s1));
	strcat(s1, s2);
	s1 = (char*) realloc(s1, strlen(s1) + strlen(s2));
	strcat(s1, s2);

	printf("Size S1 realloc: %lu\n", strlen(s1));
	printf("Size S2: %lu\n", strlen(s2));
	//printf("Size S3: %lu\n", sizeof(&s3));
	return 0;
}
