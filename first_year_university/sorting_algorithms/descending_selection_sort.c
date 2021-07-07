// SELECTION SORT DECRESCENTE
#include <stdio.h>

float vet[25], min = 0, tmp = 0;
int i = 0, j = 0, p = 0, n = 0; 

void selection_sort(float vet[], int n){
	for (i = 1; i <= n-1; i++){
		min = vet[i];
		p = i;
		// L'elemento più piccolo sarà messo all'estrema sinistra.
		for (j = i+1; j <= n; j++){
			if (vet[j] > min){ // PER ORDINAMENTO CRESCENTE BASTA CAMBIARE LA CONDIZIONE.
				min = vet[j];
				p = j; // Il numero con il più piccolo valore è in posizione p.
			}
		}
		tmp = vet[i];
		vet[i] = vet[p];
		vet[p] = tmp;  // Alla prima "passata" l'elemento più piccolo sarà posizionato nella prima posizione del vettore.
	}
	
	for (i = 1; i <= n; i++){
		printf("%f", vet[i]);
		printf("\n");
	}
}

int main(int argc, char* argv[]){

 	
	printf("Dichiarare la dimensione del vettore: ");
	scanf("%d", &n);
	printf("\n");
	
	for (i = 1; i <= n; i++){
		printf("Elemento: ");
		scanf("%f", &vet[i]);
	}
	printf("\n");
	
	selection_sort(vet, n);
		
	return 0;
}
