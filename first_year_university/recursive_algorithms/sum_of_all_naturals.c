#include <stdio.h>

int somma_ric(int n){
	if (n == 1)
		return 1;
	else 
		return n + somma_ric(n-1);
}

int main(int argc, char* argv[]){
	int n;
	
	printf("Dichiarare quanti numeri naturali vuoi sommare: ");
	scanf("%d", &n);
	
	int risultato = somma_ric(n);
	printf("Il valore della somma e': %d", risultato);
	
	return 0;
}
