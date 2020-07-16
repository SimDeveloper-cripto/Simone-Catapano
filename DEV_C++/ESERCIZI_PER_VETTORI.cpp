#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(){
	int tot_elementi = 10;
	int vettore[tot_elementi];
	int conta_negativi = 0;
	int conta_positivi = 0;
	int conta_pari = 0;
	int conta_dispari = 0;
	
	for (int i = 0; i < tot_elementi; i++){
		cout << "Inserisci numero: "; 
		cin>> vettore[i];
	} cout << endl;
	
	cout << "Caricamento";
	for (int k = 0; k < 3; k++){
		_sleep(1000);
		cout << ".";	
	} system("cls");
	

	for (int i = 0; i < tot_elementi; i++){
		if(vettore[i] < 0) conta_negativi++;
		if(vettore[i] > 0) conta_positivi++;
		if(vettore[i] % 2 == 0) conta_pari++;
		if(vettore[i] % 2 != 0) conta_dispari++;
	}
	
	cout << "Totale numeri positivi inseriti: " << conta_positivi << endl;
	cout << "Totale numeri negativi inseriti: " << conta_negativi << endl;
	cout << "Totale numeri pari inseriti: " << conta_pari << endl;
	cout << "Totale numeri dispari inseriti: " << conta_dispari << endl;
	
	return 0;
}
