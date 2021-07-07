/* Scrivi un programma che concatena due stringhe. */
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define dim 256

void concatena(char stringa_1[], char stringa_2[]);

int main(int argc, char *argv[])
{
    char stringa_1[dim];
    char stringa_2[dim];

    gets(stringa_1);
    gets(stringa_2);

    concatena(stringa_1, stringa_2);
}

void concatena(char stringa_1[], char stringa_2[])
{
    size_t i = 0;
    int len = strlen(stringa_1);

    for(i = 0; (stringa_1[i+len] = stringa_2[i]) != '\0'; i++) {
        stringa_1[i+len] = stringa_2[i];
    }
    printf("%s", stringa_1);
 
    /* IN ALTERNATIVA:
        strcat(stringa_1, stringa_2);
        printf("%s", stringa_1);
    */
}