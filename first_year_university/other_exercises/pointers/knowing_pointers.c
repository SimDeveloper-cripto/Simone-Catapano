/*
    Scrivi un programma che esegue le seguenti azioni, e dopo ogni azione, stampa per ogni
    puntatore l’indirizzo del puntatore, il valore del puntatore (i.e. l’indirizzo verso qui punta) e
    il contenuto del puntatore (i.e. il valore presente al indirizzo dove punta il puntatore):

    • dichiara un puntatore di integer p senza inizializzarlo, e un puntatore di integer q inizializzato a NULL;
    • far puntare p verso una variabile v inizializzata a 10;
    • grazie a p, cambiare il valore di v dalla tastiera;
    • utilizza un puntatore r che punta verso p per cambiare v dalla tastiera.
*/
#include <stdio.h>

int main(void)
{
    int *p;
    int *q = NULL;
    int v = 10;

    /* 
        Inridizzo a cui fa riferimento il puntatore: p.
        Indirizzo di memoria in cui si trova il puntatore: &p.
        Contenuto del puntatore: *p.
    */
    printf("p --> &p = %p, p = %p, *p = %p", &p, p, *p);
    puts("");
    printf("q --> &q = %p, q = %p", &q, q);
    puts("");
    printf("Intero v --> &v = %p, v = %d", &v, v);
   
    p = &v; // p punta a v.

    /* Dopo che p punta a v */
    puts("");
    printf("Inridizzo a cui fa riferimento il puntatore: %p", p); 
    puts("");
    printf("Indirizzo di memoria in cui si trova il puntatore: %p", &p); 
    puts("");
    printf("Contenuto del puntatore: %p", *p); 

    // Cambio valore di v tramite p.
    printf("\nCambiare il valore di v: ");
    scanf("%d", p);
    printf("Valore di v: %d", v);

    // Utilizziamp un puntatore r che punta verso p per cambiare v dalla tastiera.
    int *r = p;

    printf("\nCambiare il valore di v: ");
    scanf("%d", r);
    printf("Valore di v: %d", v);

    return 0;
}