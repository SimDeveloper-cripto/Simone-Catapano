#include <iostream>
#include <stdlib.h>
using namespace std;

char toChar(int num);

int main(int argc, char* argv[]) {
	system("color 1f");
	system("title CONVERSIONE_INTERO_A_CARATTERE");
	
	int numero = 0;
	
	cout << "Digitare il numero intero da convertire in carattere: ";
	cin >> numero; cout << endl;
	
	cout << "Elaborazione in corso";
	for (int i = 0; i < 3; i++){
		_sleep(1000);
		cout << ".";
	} system("cls");
	
	
	char risultato = toChar(numero);
	cout << "Risultato della conversione: " << risultato << endl;
	
	return 0;
}

char toChar(int num){
	int numero = num;
	
	char ch = static_cast<char>(numero);
	return ch;
} 
