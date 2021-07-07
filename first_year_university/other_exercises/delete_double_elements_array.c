#include <stdio.h>

int main(int argc, char* argv[]){
	int i, j;
	int a[30];
	int size;

	printf("Dimenisione del vettore (MAX 30): ");
	scanf("%d", &size);
	if (size <= 0 || size > 30){
		printf("Errore");
	} else {
		printf("\n");
		for(i = 1; i <= size; i++){
			printf("Inserire elemento nel vettore: ");
			scanf("%d", &a[i]);
		}
		printf("\n");
		
		printf("Vettore creato: \n");
		for(i = 1; i <= size; i++){
			printf("%d \n", a[i]);
		}
		
		// ELIMINAZIONI DEI DOPPIONI
		for (i = 1; i <= size; i++){
			if (a[i] == a[i+1]){
				for (j = i+1; j <= size; j++){
					a[j] = a[j+1];
				}
				size--;
			}
		}	
		printf("\n");
		
		printf("Vettore senza doppioni: \n");
		for(i = 1; i <= size; i++){
			printf("%d \n", a[i]);
		}
	}
	return 0;
}
