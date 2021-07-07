#include "dec_to_exadec.h"

void invert_array(int array[], int dim){
    size_t i = 0, j = dim - 1;
    int temp = 0;
    /*
        --> To invert an array what we do is swapping in pairs by incrementing at left and decrementing at right.
        We start swapping the first element and the last element and then proceed like (i+1) <--> (j-1)...
    */
    while(i < j){
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}

void stampa(int array[], int dim){
    size_t i = 0;
    for(i = 0; i < dim; i++){
        switch(array[i]){
            case 10:
                printf("A");
                break;
            case 11: 
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13: 
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15: 
                printf("F");
                break;
            default: 
                printf("%d", array[i]);
        }
    }
}

void to_exadecimal(int numero){
    size_t i = 0;
    int array_rest[MAX];
    int dim = 0;
    int rest = 0;
    /* 
        While the number in not equal to zero we have to keep dividing by six-teen.
        Each time this happens we save the remainder of the division inside the array.
    */
    while(numero > 0){
        rest = numero % 16;
        array_rest[i] = rest;
        i++;
        dim++;
        numero /= 16;
    }
    invert_array(array_rest, dim);
    stampa(array_rest, dim);
}