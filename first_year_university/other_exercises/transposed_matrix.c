#include <stdio.h>
int main(int argc, char* argv[]){
	float matrice[10][10];
	float tmp;
	int i, j;
	int righe, colonne;
	
	printf("Righe: ");
	scanf("%d", &righe);
	printf("Colonne: ");
	scanf("%d", &colonne);
	
	if (righe <= 0 || righe > 10 || colonne <= 0 || colonne > 10){
		printf("Errore\n");
	} else {
		printf("\n");
		for(i = 1; i <= righe; i++){
			for (j = 1; j <= colonne; j++){
				printf("Inserire elemento riga %d", i);
				printf(", e colonna %d", j);
				printf("\t");
				scanf("%f", &matrice[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for(i = 1; i <= righe; i++){
			for (j = 1; j <= colonne; j++){
				printf("[%f", matrice[i][j]);
				printf("]\t");
			}
			printf("\n");
		}
		
		printf("\n");
		for(i = 1; i <= righe; i++){
			for (j = i+1; j <= colonne; j++){
				tmp = matrice[i][j];
				matrice[i][j] = matrice[j][i];
				matrice[j][i] = tmp;	
			}
		}
		for(i = 1; i <= righe; i++){
			for (j = 1; j <= colonne; j++){
				printf("[%f", matrice[i][j]);
				printf("]\t");
			}
			printf("\n");
		}
		
	}
	return 0;
}
