#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define dim 256


int getSize(char stringa[]){
    int counter = 0;
    size_t i;
    char *pointer = stringa;

    while(*(pointer + i) != '\0'){
        ++counter;
        ++i;
    }

    return counter;
}


int main(){
   char stringa[dim];
    
    printf("Inserire la stringa: ");
    scanf("%s", &stringa);

    int risultato = getSize(stringa);

    printf("La dimensione della stringa e': %d", risultato);

    return 0;
}
