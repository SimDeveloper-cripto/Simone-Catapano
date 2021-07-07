// SELECTION SORT CRESCENTE
#include <stdio.h>

int main(int argc, char* argv[]){
	int vet[25];
	int min = 0;

	int i = 0; 
	int j = 0;
	int p = 0;
	
	int n; // dimensione del vettore. 
	
	printf("Dichiarare la dimensione del vettore: ");
	scanf("%d", &n);
	printf("\n");
	
	for (i = 1; i <= n; i++){
		printf("Elemento: ");
		scanf("%d", &vet[i]);
	}
	printf("\n");
	
	for (i = 1; i <= n-1; i++){
		min = vet[i];
		p = i;
	
		// L'elemento più piccolo sarà messo all'estrema sinistra.
		for (j = i+1; j <= n; j++){
			if (vet[j] < min){ // PER ORDINAMENTO DECRESCENTE BASTA CAMBIARE LA CONDIZIONE.
				min = vet[j];
				p = j; // Il numero con il più piccolo valore è in posizione p.
			}
		}
		int tmp = vet[i];
		vet[i] = vet[p];
		vet[p] = tmp;  // Alla prima "passata" l'elemento più piccolo sarà posizionato nella prima posizione del vettore.
	}
	
	for (i = 1; i <= n; i++){
		printf("%d", vet[i]);
		printf("\n");
	}
	
	return 0;
}
