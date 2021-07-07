#include <stdio.h>
#include <conio.h>

int MCD(int m, int n){
	int risultato;
	if (m % 2 == 0){
		risultato = n;
	} else {
		risultato = MCD(n, m%n);
	}
	return risultato;
}

int main(int argc, char* argv[]){
	int m,n;
	
	printf("Dichiarare il primo numero: ");
	scanf("%d", &m);
	printf("Dichiarare il secondo numero: ");
	scanf("%d", &n);
	
	int risultato = MCD(m,n);
	printf("MCD: %d", risultato);
	
	getch();
	return 0;
}
