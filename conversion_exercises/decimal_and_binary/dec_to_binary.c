#include "dec_to_binary.h"

void toBinary(int numero){
    int array[MAX];
    int i = 0;
    int valore = 0;
    unsigned int conta = 0;
    
    // Let's start converting:  
    while(numero != 0){
        /* 
            While the number in not equal to zero we have to keep dividing by two.
            Each time this happens we save the remainder of the division inside the array.
        */
        valore = numero % 2;
        array[i] = valore;
        i++; // Of course we have to increment the index to gain another location in which we are going to store the next remainder.
        conta++; // By doing that we keep track of how many values we store into the array so that when the cycle is finished we can print it!
        numero /= 2;
    }    

    // Printing the result
    printf("Valore binario calcolato: ");
    for(i = conta - 1; i >= 0; i--){
        printf("%d", array[i]);
    }
}