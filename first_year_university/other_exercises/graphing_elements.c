#include <stdio.h>
#include <stddef.h>
#define SIZE 5

void graph(); // function prototype.

int main(void){
    graph();
    return 0;
}

void graph(){ // By doing this the compiler won't need to inizialize and create the array each time the function is called.
    static unsigned int array[SIZE] = {1,2,3,4,5};
    size_t i;
    unsigned int j;

    for(i = 0; i < SIZE; i++){
        printf("Elemento [%d]: %d\t", i, array[i]);
        for(j = 1; j <= array[i]; j++){
            printf("%c", '*');
        }
        puts("");
    }
}