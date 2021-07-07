#include "dec_to_exadec.h"
#include "exadec_to_dec.h"

int main(){
    int scelta = 0;

    do {
        printf("[1] Conversione da decimale ad esadecimale.\n[2] Conversione da esadecimale a decimale.\n");
        printf("Dichiarare la tua scelta --> ");
        scanf("%d", &scelta);
    } while((scelta != 1) && (scelta != 2));
    

    switch(scelta){
        case 1:
        {
            int numero = 0;
            printf("Digitare il numero da convertire in esadecimale: ");
            scanf("%d", &numero);
            to_exadecimal(numero);
            break;
        }
        case 2: 
        {
            char input[DIM];
            printf("Digitare il valore esadecimale da convertire: ");
            scanf("%s", input);
            from_exadec_to_decimal(input);
            break;
        }
        default: 
            printf("\n\n");
    }

    return 0;
}