#include <stdio.h>
#include <conio.h>

int x_elevato_n(int x, int n){
	if (n == 0)
		return 1;
	else 
		return x * x_elevato_n(x,n-1);
}

int main(int argc, char* argv[]){
	int base = 0, esponente = 0;
	int potenza;
	
	printf("Dichiarare la base: ");
	scanf("%d", &base);
	printf("Dichiarare l'esponente: ");
	scanf("%d", &esponente);
	
	potenza = x_elevato_n(base, esponente);
	
	printf("\nRisultato della potenza: %d", potenza);
	
	getch();
	return 0;
}
