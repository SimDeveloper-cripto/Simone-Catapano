#include <stdio.h>

int main(int argc, char* argv[]){
	int i, j, n, tmp;
	
	printf("Quanti numeri vuoi nell'array: ");
	scanf("%d", &n);
	printf("\n");
	
	if (n <= 0) return 0;
	
	int vet[n];
	
	for (i = 1; i <= n; i++){
		printf("Inserire numero n.%d", i);
		printf(": ");
		scanf("%d", &vet[i]);
	}	
	printf("\nVettore creato:");
	for (i = 1; i <= n; i++){
		printf("\n%d", vet[i]);
	}
	
	i = 1;
	j = n;
	while (i <= j){
		tmp = vet[i];
		vet[i] = vet[j];
		vet[j] = tmp;	
		i++;
		j--;
	}
	printf("\nVettore invertito:\n");
	for (i = 1; i <= n; i++){
		printf("\n%d", vet[i]);
	}	
	
	return 0;
}
