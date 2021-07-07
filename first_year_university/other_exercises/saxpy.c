#include <stdio.h>

int main(int argc, char* argv[]){
	int i, n, alpha = 0;
	
	printf("Scrivere un numero per la dimensione dei due vettori: ");
	scanf("%d", &n);
	
	int x[n], y[n];
	
	printf("\nCaricamento del vettore 1:\n");
	for (i = 1; i <= n; i++){	
		printf("Inserire elemento: ");
		scanf("%d", &x[i]);
	}
	printf("\nCaricamento del vettore 2:\n");
	for (i = 1; i <= n; i++){	
		printf("Inserire elemento: ");
		scanf("%d", &y[i]);
	}
	
	printf("Definisci un valore scalare per il calcolo: ");
	scanf("%d", &alpha);
	
	
	// Calcolo di una saxpy
	for (i = 1; i <= n; i++){
		y[i] = y[i] + (alpha * x[i]);
		printf("\n%d", y[i]);
	}
	
	return 0;
}
