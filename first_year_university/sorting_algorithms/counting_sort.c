#include <stdio.h>
#include <conio.h>

void counting_sort(int vet[], int n, int k);

int main(int argc, char* argv[]){
	int i, n = 0, k = 0;
	int vet[60];
	
	printf("Dichiarare la dimensione del vettore (MAX 10): ");
	scanf("%d", &n);
	
	while (n <= 0 || n > 60){
		printf("Dichiarare la dimensione del vettore (MAX 10): ");
		scanf("%d", &n);
	}
	printf("\n");
	for(i = 1; i <= n; i++){
		printf("Inserire elemento nel vettore: ");
		scanf("%d", &vet[i]);
	}
	printf("\nVettore appena creato:\n");
	for(i = 1; i <= n; i++){
		printf("%d\t", vet[i]);
	}
	
	printf("\n\nDichiarare il valore di k: ");
	scanf("%d", &k);
	
	if (k >= n){
		counting_sort(vet, n, k);
		printf("\nVettore ordinato:\n");
		for (i = 1; i <= n; i++){
			printf("%d\t", vet[i]);
		}
	}

	getch();
	return 0;
}

void counting_sort(int vet[], int n, int k){
	int i, j, s;
	int conta[400];
	
	for(i = 1; i <= k; i++){
		conta[i] = 0; // azzeriamo il vettore conta.
	}
	for(j = 1; j <= n; j++){
		conta[vet[j]] = conta[vet[j]] + 1;
	}
	/* for (j = 1; j <= n; j++){
		vet[j] = 0;
	} */
	j = 1;
	for(i = 1; i <= k; i++){
		for(s = 1; s <= conta[i]; s++){
			vet[j] = i;
			j++;
		}
	}
}











