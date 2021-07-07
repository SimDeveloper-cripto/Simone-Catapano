#include <stdio.h>
#include <stddef.h>
#define DIM 100

int *massimale(int array[], unsigned int dim);

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
    int *risultato = massimale(array, n);

    printf("\nElemento massimale: %d", *risultato);

    return 0;
}

int *massimale(int array[], unsigned int dim)
{
    size_t i;
    int max = 0;

    for(i = 0; i < dim; i++){
       if(array[i] > max) max = array[i];
    }
    int *tot = &max;

    return tot;
}