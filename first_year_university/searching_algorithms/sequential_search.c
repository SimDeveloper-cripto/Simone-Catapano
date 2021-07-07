// ALGORITMO DI SEQUENTIAL_SEARCH
#include <stdio.h>
#include <stdbool.h>

bool cerca (float vet[], int n, float elemento) {
	bool presente = true;
	
	int i = 1; 
    while ((vet[i] != elemento) && (i <= n))  i++; 
    
	if (i >= n) { 
		printf("Elemento non trovato!");
		printf("\n\t");

		return presente = false;
    } else { 
        printf("Elemento trovato, in posizione: %d", i);
        printf("\n\t");

        return presente;
	}
	/* ALGORITMO ANCORA PIU' PRECISO: SE CI SONO PIU' ELEMENTI IN DIVERSE POSIZIONI.
		for (i = 1; i <= n; i++){
			if (vet[i] == elemento){				
				printf("Elemento trovato in posizione: %d", i);
				printf("\n");
				}
			}
	*/
}

int main(int argc, char*argv[]){
	
	bool risultato;	
	int i = 0, n;
	float vet[10], elemento;
	
	printf("Grandezza del vettore? (MAX 10): ");
	scanf("%d", &n);
	
	if(n <= 0 || n > 10){
		printf("Errore!");
	} else {
		printf("\n\n");
			for (i = 1; i <= n; i++){
				printf("Inserire elemento: ");
				scanf("%f", &vet[i]);
			}
			printf("\n");
			printf("Elemento da cercare?: ");
			scanf("%f", &elemento);
			
			risultato = cerca(vet, n, elemento);	 
			printf("(%d", risultato); printf(")"); printf("\n");
	}
	return 0;
}
