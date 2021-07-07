#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
	int vet[25];
	int n = 0;
	int i = 0;
	
	while (true){
		printf("Dimensione del vettore (MAX 25): ");
		scanf("%d", &n);
		
		if ((n <= 0) || n > 25){
			printf("Errore nella grandezza del vettore: ");
		} else {
			printf("\n");
			for (i = 1; i <= n; i++){
				printf("Elemento: ");
				scanf("%d", &vet[i]);
			}
			
			int k = 0;
			for (i = 1; i <= n; i++){
				if (vet[i] != 0){
					k++;
					vet[k] = vet[i];
				}
			}
			printf("\nVettore compattato: \n");
			for (i = 1; i <= n; i++){
				printf("%d", vet[i]);
				printf("\n");
			}	
		}
		printf("\n");
	}
	return 0;
}
