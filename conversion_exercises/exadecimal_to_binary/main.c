#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#define DIM 100
 
size_t i;

void print_exadec_to_binary(char stringa[], int lenght){
    printf("Binary value: ");
    for(i = 0; i < lenght; i++){
        switch(stringa[i]){
            case '1': 
                printf("0001 ");
                break;
            case '2': 
                printf("0010 ");
                break;
            case '3': 
                printf("0011 ");
                break;
            case '4': 
                printf("0100 ");
                break; 
            case '5': 
                printf("0101 ");
                break;
            case '6': 
                printf("0110 "); 
                break;
            case '7': 
                printf("0111 "); 
                break; 
            case '8': 
                printf("1000 "); 
                break; 
            case '9': 
                printf("1001 "); 
                break;
            case 'a':
            case 'A': 
                printf("1010 ");
                break; 
            case 'b':
            case 'B': 
                printf("1011 ");
                break;
            case 'c':
            case 'C': 
                printf("1100 "); 
                break;
            case 'd':
            case 'D': 
                printf("1101 "); 
                break; 
            case 'e':
            case 'E': 
                printf("1110 "); 
                break; 
            case 'f':
            case 'F': 
                printf("1111"); 
                break;
            default: 
                printf("\n\n");
        }
    }
}

int main() {
    int lenght = 0;
    char stringa[DIM];

    do {
        printf("Inserire stringa esadecimale: ");
        scanf("%s", stringa);
    } while((strlen(stringa)) <= 0 || (strlen(stringa) > 100));
    
    lenght = strlen(stringa);

    print_exadec_to_binary(stringa, lenght);
    return 0;
}