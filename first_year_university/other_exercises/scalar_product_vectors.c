#include <stdio.h>

int main(int argc, char* argv[]){
	int i, n, prod_scal = 0;
	
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
	// Calcolo del prodotto scalare
	for (i = 1; i <= n; i++){
		prod_scal = prod_scal + (x[i]*y[i]);
	}
	
	printf("\nIl prodotto scalare dei due vettori e': %d", prod_scal);
	return 0;
}
