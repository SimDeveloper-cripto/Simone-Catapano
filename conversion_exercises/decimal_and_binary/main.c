/*
    To run this project in terminal write this command:
    --> "gcc binary_to_dec.c dec_to_binary.c main.c -o main" 

*/
#include "binary_to_dec.h"
#include "dec_to_binary.h"

int main(int argc, char* argv[]){
    int scelta = 0;

    do{
        printf("[1] Conversione da binario a decimale.\n[2] Conversione da decimale a binario.\n");
        printf("Digitare la tua scelta --> "); 
        scanf("%d", &scelta);
    } while((scelta != 1) && (scelta != 2));

    switch(scelta){
        case 1:
        {
            char input[20];
            int ris = 0;
            do {
                printf("Digitare la stringa in binario da convertire in decimale: ");
                scanf("%s", input);
            } while(strlen(input) <= 0 || strlen(input) > 20);
            ris = convtoDec(input);
            printf("Il risultato in decimale e': %d", ris);
            break;
        }
        case 2:
        {
            int numero = 0;
            printf("Digitare il numero da convertire: ");
            scanf("%d", &numero);
            toBinary(numero);
            break;
        }
        default: 
            printf("\n\n");
    }  
    return 0;
}