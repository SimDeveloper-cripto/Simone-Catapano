#include "exadec_to_dec.h"

void from_exadec_to_decimal(char input[]){
    size_t i;
    int lenght = strlen(input);
    int decimale = 0;
    int help;

    for(i = 0; i < lenght; i++){
        /*
            --> We have to check is there is the case A --> F.
            The compiler, using this technique, knows A = 10, ... , F = 15.
        */
        if(input[i] >= 'A' && input[i] <= 'F')
            help = 10 + input[i] - 'A';
        else 
            help = input[i] - '0';
        /*
            --> The process is equal to the conversion binary to decimal but we sum (input[i] * 16^0) + (input[i] * 16^1)... 
        */
        decimale += help * (pow(16, lenght - 1 - i));
    }
    printf("Valore in decimale: %d", decimale);
    puts("");
}