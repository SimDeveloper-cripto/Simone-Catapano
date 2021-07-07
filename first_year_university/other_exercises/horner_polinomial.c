#include <stdio.h>

int horner(int grado_pol, int coeff[], int x);

int main(int argc, char* argv[]){
	int grado_pol = 0;
	int x = 0, i;
	int coeff[255];

	
	printf("Dichiarare il grado massimo del polinomio: ");
	scanf("%d", &grado_pol);
	printf("\nPunto di valutazione per la variabile x?: ");
	scanf("%d", &x);
	
	printf("\n");
	for (i = 0; i < grado_pol+1; i++){
		printf("Dichiarare il coefficiente di x^%d", grado_pol-i);
		printf(": "); scanf("%d", &coeff[i]);
	}
	printf("\n\nIl polinomio ha la seguente forma: ");
	for(i = 0; i < grado_pol+1; i++){
		printf("%dx^%d", coeff[i], grado_pol-i);
		printf("+");
	}
	printf("\n");
	
	// CALCOLO DEL POLINOMIO TRAMITE HORNER
	/*
		Ex: pol = (2x^3 + 3x^2 + 3x^1 + 5x^0)  
		a3 = 2, a2 = 3, a1 = 3, a0 = 5 ----> x = 2
		
		Con questo algoritmo faremo: [(a3*x + a2)x + a1] + a0 ------> [(2*2 + 3)*2 + 3] + 5
	*/	 
	
	/*
	int pol = coeff[0];
	for (i = 1; i <= grado_pol; i++){
		pol = pol*x + coeff[i]; // Ex: [(2*2 + 3)*2 + 3] + 5 // 
	}
	printf("\n%d", pol);   */
	
	int risultato = horner(grado_pol, coeff, x);
	printf("Valore complessivo del polinomio: %d", risultato);
	
	return 0;
}

int horner(int grado_pol, int coeff[], int x){
	int pol = coeff[0], i;
	for (i = 1; i <= grado_pol; i++){
		pol = pol*x + coeff[i]; // Ex: [(2*2 + 3)*2 + 3] + 5 // 
	}
	return pol;
}
