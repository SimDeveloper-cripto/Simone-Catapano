#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

string nome = ""; 
string nomi[30];
int n = 0;
int k = 0;

void carica (){
	do {
		cout << "QUANTI NOMI VUOI INSERIRE IN ELENCO? : \t";
		cin >> n;
	} while (n > 30);
	cout << "---------------------------------------" << endl;
	for (k = 0; k < n; k++){
		cout << "INSERIRE IL NOME PREGO: \t"; cin >> nomi[k];
	}
}

void cerca (){
    cout << "----------------------------------------" << endl;
    cout << "QUALE NOME VUOI CONTROLLARE?: \t";
    cin >> nome; cout << endl;
    
    // RICERCA PARZIALE 
    k = 0; 
    while ((nomi[k] != nome) && (k < n))  
    k++; 
    for (int i = 0; i < 6; i++){
    	_sleep(1000);
    	cout << ".";
	}
    cout << endl;
        if (nomi[k] == nome) 
            cout << "ELEMENTO TROVATO!" << "IN POSIZIONE: \t" << k + 1 << endl;
        else 
        	cout << "ELEMENTO NON TROVATO!" << endl;
}

int main(){
	carica();
	cerca();
	system("pause");
}
