#include <stdio.h>
#include <stdbool.h>

bool isSorted(int vet[], int n){
	if(n == 1) 
		return true;
	else if (vet[n-1] > vet[n])
		return false;
	else
		return isSorted(vet, n-1);
}

int main(int argc, char* argv[]){
	int i, n;
	
	printf("Dichiarare la dimensione del vettore: ");
	scanf("%d", &n);
	
	int vet[n];
	
	printf("\n");
	for(i = 0; i < n; i++){
		printf("Inserire elemento nel vettore: ");
		scanf("%d", &vet[i]);
	}
	
	bool sort = isSorted(vet, n);
	printf("\nRisultato del controllo: %d", sort);
	
	return 0;
}
