/*
    Scrivere un algoritmo che permette di stampare uno alla volta i caratteri di una stringa.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_chars(const char *string);

int main(int argc, char *argv[]){
    char string[] = "hello guys!";
    print_chars(string);
    return 0;
}


void print_chars(const char *string){
    for(; *string != '\0'; *string++){
        printf("%c", *string);
    }
}