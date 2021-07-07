#include "binary_to_dec.h"

void invertString(char input[]){
    int i = 0; 
    int j = strlen(input) - 1;
    char temp;
    /*
        --> To invert an array (the string we received as parameter) what we do is swapping in pairs by incrementing at left and decrementing at right.
        We start swapping the first element and the last element and then proceed like (i+1) <--> (j-1)...
    */
    while(i < j){
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++; 
        j--;
    }
}

int convtoDec(char input[]){
    size_t i;
    int totale = 0;
    int dim = strlen(input);

    printf("\n");
    /*
        --> We could also have used the standard function " strrev(input); ", but i prefered creating one on my own!
    */
    invertString(input);
   
    for(i = 0; i < strlen(input); i++){
        // How to convert a binary number: (1 * 2^0) + (1 * 2^1) + (1 * 2^2) and so on...
        if(input[i] == '1'){
            totale = totale + pow(2, i);
        } 
    }
    return totale; // once the convertion process is finished we just return the decimal value.
}