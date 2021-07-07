#include <stdio.h>

float c[50];

void merge_sort(float a[], float b[], int n, int m){
	int i = 1, j = 1, k = 1, h;
	// MANTENIAMO L'ORDINE CRECENTE DELL'ARRAY ANCHE SE UNITI TRA LORO.
	while (i <= n && j <= m){
		if (a[i] < b[j]){
			c[k] = a[i];
			i++;
		} else {
			c[k] = b[j];
			j++;
		}
		k++;	
	} 
	
	if (i > n){
		for (h = j; h <= m; h++){
			c[k] = b[h];
			k++;
		}
	} else {
		for (h = i; h <= n; h++){
			c[k] = a[h];
			k++;
		}
	}
	printf("\n");
	for (k = 1; k <= n+m; k++){
		printf("%f \n", c[k]);
	}
		
}

int main(int argc, char* argv[]){
	float a[25]; int n = 0, i = 0;
	float b[25]; int m = 0, j = 0;
	int tmp = 0;
	int tmp2 = 0;
	
		printf("Dimensione vettore 1 (MAX 25): ");
		scanf("%d", &n);
		
		printf("Dimensione vettore 2 (MAX 25): ");
		scanf("%d", &m);
		
		if (n <= 0 || n > 25 || m <= 0 || m > 25){
			printf("Errore!");
		} else {
			// CARICAMENTO DEI DUE VETTORI A E B.
			printf("\n");
			printf("Caricamento vettore 1\n");
			for (i = 1; i <= n; i++){
				printf("Elemento: ");
				scanf("%f", &a[i]);
			}
			printf("\n");
			printf("Caricamento vettore 2\n");
			for (j = 1; j <= m; j++){
				printf("Elemento: ");
				scanf("%f", &b[j]);
			}
			printf("\n\n");
			
			// ORDINAMENTO VETTORE A EXCHANGE_SORT.
			int conta = 1;
			while (conta <= n){
				for (i = 1; i <= n-conta; i++){
					if(a[i] > a[i+1]){
						tmp = a[i];
						a[i] = a[i+1];
						a[i+1] = tmp;
					}
				}
				conta++;
			}
			for (i = 1; i <= n; i++){
				printf("%f \n", a[i]);
			}
			// ORDINAMENTO VETTORE B EXCHANGE_SORT.
			printf("\n\n");
			int contatore = 1;
			while (contatore <= m){
				for (j = 1; j <= m-contatore; j++){
					if(b[j] > b[j+1]){
						tmp2 = b[j];
						b[j] = b[j+1];
						b[j+1] = tmp2;
					}
				}
				contatore++;
			}
			for (j = 1; j <= m; j++){
				printf("%f \n", b[j]);
			}
			printf("\n\n");			
			
			merge_sort(a,b,n,m);
		}
	return 0;
}
