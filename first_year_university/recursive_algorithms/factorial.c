#include <stdio.h>

int fattoriale(int n){
	if (n < 0) return -1;
	
	if (n == 0) 
		return 1;
	else 
		return n *fattoriale(n-1);
}

int main(int argc, char* argv[]){
	int n;
	
	printf("Dichiarare il numero di cui calcolare il fattoriale: ");
	scanf("%d", &n);
	
	int risultato = fattoriale(n);
	printf("Fattoriale: %d", risultato);
	
	return 0;
}
