/*
    ALGORITMO:
    --> Design bubble sort for arrays using pointers and function for swapping elements.

*/
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#define SIZE 10

void bubble_sort(int *const array, size_t size);
void swap(int *el_1ptr, int *el_2ptr); 

int main(int argc, char* argv[])
{
    size_t i;
    int array[SIZE] = {2, 4, 6, 8, 10, 12, 89, 68, 45, 37};

    printf("Array non ordinato:\n");
    for(i = 0; i < SIZE; i++){
        printf("Elemento[%d]: %d", i, array[i]);
        puts("");
    }

    bubble_sort(array, SIZE); // As you've seen at lecture u can do also this --> bubble_sort(&array[0], SIZE);

    printf("\n\nArray  ordinato:\n");
    for(i = 0; i < SIZE; i++){
        printf("Elemento[%d]: %d", i, array[i]);
        puts("");
    }

    return 0;
}

void swap(int *el_1ptr, int *el_2ptr)
{
    int tmp = *el_1ptr;
    *el_1ptr = *el_2ptr;
    *el_2ptr = tmp;
}

void bubble_sort(int *const array, size_t size)
{
    size_t i; 
    int j = 0;
    bool ordinato = false;

    // exchange_sort > bubble_sort
    while((j < SIZE) && (!ordinato)){
        ordinato = true;
        for(i = 0; i < SIZE-j-1; i++){
            if(array[i] > array[i+1]){
                swap(&array[i], &array[i+1]); // elements at subscripts specified are passed by reference. 
                ordinato = false;
            }
        }
        j++;
    }

    /*  bubble_sort
        for(i = 0; i < SIZE-1; i++){
            for(j = 0; j < SIZE-1; j++){
                if(array[i] > array[i+1]){
                    swap(&array[i], &array[i+1]);
                }
            }
        }
    */
}