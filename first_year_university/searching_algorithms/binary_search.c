#include <stdio.h>
#include <stdbool.h>

bool ricerca(float vet[], int n, float elemento){
	int primo = 1;
	int ultimo = n;
	int medio;
	int pos_elemento = -1;
	bool trovato = false;
	
	while (primo <= ultimo && !trovato){
		medio = (primo + ultimo) / 2;
		if (elemento == vet[medio]){
			trovato = true;
			pos_elemento = medio;
		} else if(elemento < vet[medio]){
			ultimo = medio - 1;
		}else{
			primo = medio + 1;
		}
	}
	return trovato;
}


int main(int argc, char* argv){	
	float vet[20];
	int i, n;
	float elemento;
	
	scanf("%d", &n);
	if(n <= 0 || n > 20){
		printf("Errore");
	} else {
		printf("\n");
		for (i = 1; i <= n; i++){
			scanf("%f", &vet[i]);
			printf("\n");
		}
		printf("\n");
		printf("Elemento da cercare?: ");
		scanf("%f", &elemento);
		
		bool risultato = ricerca(vet, n, elemento);
		printf("%d ", risultato);
	
	}
	return 0;
}
