#include <iostream>
using namespace std;

int potenza(int* base, int* esponente); 

int main(){
  int b,e,pot;
  
  cout << "Digitare la base: "; cin >> b;
  cout << "Digitare l'esponente: "; cin >> e;
  
  pot = potenza(&b, &e);
  
  cout << "La potenza ottenuta e': " << pot <<endl;
  
  return 0;
}

int potenza(int* base, int* esponente) {
    int potenza = 1;
	int k;
	if (*esponente != 0){
		potenza = *base;
	for (k = 1; k < *esponente; k++){
		potenza = potenza * *base;
	}
  }
	return potenza;
}
