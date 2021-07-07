#include <stdio.h>

void insertion_sort(float vet[], int n){
	int i, j;
	float x;
	
	for(i = 2; i <= n; i++){
		x = vet[i];
		j = i;
		while(x < vet[j-1] && j >= 2){
			vet[j] = vet[j-1];
			j = j-1;
		}
		vet[j] = x;
	}
	printf("\n");
	printf("Vettore ordinato in maniera crescente: \n");
	for(i = 1; i<= n; i++){
		printf("%f\n", vet[i]);
	}
}

int main(int argc, char *argv[]) {
	int i, n;
	float vet[20];
	
	printf("Dichiarare la dimensione del vettore: ");
	scanf("%d", &n);

	if (n <= 0 || n > 20){
		printf("Errore");
	} else {
		for(i = 1; i <= n; i++){
			printf("Inserisci elemento %d", i);
			printf(": ");
			scanf("%f", &vet[i]);
		}
		insertion_sort(vet, n);
	}
	return 0;
}
