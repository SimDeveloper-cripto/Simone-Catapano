#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

main (void){
	int i = 0;
	int spazio = 0;
	char frase [MAX];
	
	printf("Inserire una frase: "); gets(frase);
	fflush(stdin);

    for(i = 0; i < strlen(frase); i++)
    if(frase[i] == ' ')
    spazio++;
    if (spazio > 0)
    printf("Il numero delle parole presenti nella frase e': %d \n", spazio+1);
    else
    printf("Non ci sono spazi nella frase\n");
}

