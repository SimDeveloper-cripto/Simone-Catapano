#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#define DIM 256

void toUpper(char stringa[]);

int main(void)
{
    char miaStringa[DIM];

    printf("Inserire la stringa: ");
    gets(miaStringa);

    toUpper(miaStringa);
}

void toUpper(char stringa[])
{   
    char *pointer = stringa;
    while(*pointer != '\0'){
        printf("%c", toupper(*pointer++));
    }
}
/* ALTERNATIVAMENTE: 

    void toUpper(char stringa[])
    {
        size_t i = 0;
        while(stringa[i] != '\0'){
            printf("%c", toupper(stringa[i]));
            i++;
        } 
    } 

*/
