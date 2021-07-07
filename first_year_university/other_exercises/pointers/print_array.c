/*
    ALGORITMO:
    --> Scrivi un programma che entra in una tabella cinque numeri inseriti dall’utente e gli stampi,
        utilizzando puntatori invece di accedere direttamente agli elementi della tabella.
*/
#include <stdio.h>
#include <stddef.h>
#define DIM 100

void show(int array[], unsigned int dim);

int main(void)
{
    int array[DIM];
    size_t i;
    unsigned int n;

    printf("Inserire dimensione array: ");
    scanf("%u", &n);

    for(i = 0; i < n; i++){
        printf("Elemento[%d]: ", i);
        scanf("%d", &array[i]);
    }
    printf("\n");
    show(array, n);

    return 0;
}

void show(int array[], unsigned int dim)
{
    size_t i;
    int *p;

    printf("Stampa dell'array tramite puntatori:\n");
    for(i = 0; i < dim; i++){
        p = &array[i];
        printf("Elemento[%d]: %p", i, *p);
        puts("");
    }
}

/*
    Lo stesso problema può essere risolto in maniera ricorsiva: 
    --> 
        if(dim == 0){
            printf("Fine della ricorsione: %d", 0);
        } else {
            int *p = &array[dim-1];
            printf("Valore: %p", *p);
            puts("");
            show(array, dim-1);
        }
    -->
    I valori dell'array vengono stampati al contrario... Dato che la traccia non dice nulla al riguardo, 
    possiamo comunque considerare ciò come una valida soluzione! :) 
*/