#include <iostream>
using namespace std;

int n = 0;
int k;
int e = 0;
int x[100];
bool trovato;

void caricamento() {
	cout << "Quanti elementi vuoi inserire?: \t";
	cin >> n;
	for (k = 0; k < n; k++){
		cout << "Inserisci elemento: \t";
		cin>>x[k];
	}
}

void ricerca (){
	trovato = false;
	
	cout << endl;
	cout << "Inserire elemento da cercare: \t";
	cin >> e;
	
	// RICERCA PARZIALE
	k = 0;
	while ((trovato == false) && (k < n)){
		if (x[k] == e){
			trovato == true;
			cout << endl;
			cout << x[k] << "Trovato!" << endl << "In posizione: " << k + 1 << endl;
		}
		k++;
	}
	if (trovato == false){
		cout << endl;
		cout << "Elemento non trovato!" << endl;
	}
}
int main ()
{
	caricamento();
	ricerca();
	system("pause");
}
