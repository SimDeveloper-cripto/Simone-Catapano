// EXCHANGE SORT CRESCENTE  
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
	int i, j, n;
	bool ordinato;
	float vet[25];
	float tmp;
		
	printf("Dimensione del vettore (MAX 25): ");
	scanf("%d", &n);
	
	if (n <= 0 || n > 25){
		printf("Errore nella dimensione del vettore!");
	} else {
		printf("\n");
		
		for (i = 1; i <= n; i++){
			printf("Inserire elemento nel vettore: ");
			scanf("%f", &vet[i]);
		}
		printf("\n");
		
		ordinato = false;
		j = 1;
		
		while ((j <= n) && (!ordinato)){
			ordinato = true;
			
			for (i = 1; i <= n-j; i++){
				if (vet[i] > vet[i+1]){
					tmp = vet[i];
					vet[i] = vet[i+1];
					vet[i+1] = tmp;
					
					ordinato = false;
				}
			}
			j = j + 1;
		}
		
		printf("Vettore ordinato: ");
		printf("\n");
		
		for(i = 1; i <= n; i++){
			printf("%f", vet[i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
