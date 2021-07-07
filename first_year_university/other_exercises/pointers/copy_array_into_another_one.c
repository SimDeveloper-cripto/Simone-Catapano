#include <stdio.h>
#include <stddef.h>
#define DIM 100

void copy_table(int tab_1[], int tab_2[], unsigned int dim_1, unsigned int dim_2);

int main(void)
{
    size_t i;
    int tab_1[DIM];
    int tab_2[DIM];
    unsigned int dim_1, dim_2;

    printf("Dimensione array numero 1: ");
    scanf("%u", &dim_1);
    printf("Dimensione array numero 2: ");
    scanf("%u", &dim_2);

    
    printf("\nCaricare array n.1:\n");
    for(i = 0; i < dim_1; i++){
        printf("Elemento[%d]: ", i);
        scanf("%d", &tab_1[i]);
    }
    printf("\nCaricare array n.2:\n");
    for(i = 0; i < dim_2; i++){
        printf("Elemento[%d]: ", i);
        scanf("%d", &tab_2[i]);
    }
    
    copy_table(tab_1, tab_2, dim_1, dim_2);

    printf("\nStampa array n.2:\n");
    for(i = 0; i < dim_2; i++){
        printf("Elemento[%d]: %d", i, tab_2[i]);
        puts("");
    }

    return 0;
}

void copy_table(int tab_1[], int tab_2[], unsigned int dim_1, unsigned int dim_2)
{
    size_t i;
    int *pointer;

    for(i = 0; i < dim_1; i++){
        if(dim_2 >= i){
            pointer = &tab_1[i];
            tab_2[i] = *pointer;
        }
        dim_2--;
    }
}