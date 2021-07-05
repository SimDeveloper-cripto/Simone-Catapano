#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	int scelta = 0;
	char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUWXYZ@#!?%";
	char *Password; // Puntatore "password" del charset di caratteri.
	
	do{
		cout << "Di quanti caratteri vuoi la tua password?: ";
		cin >> scelta;
		if ((scelta <= 0) || (scelta > 67)) cout << "ERRORE DI INSERIMENTO!\n";
	}while ((scelta <= 0) || (scelta > 67));
	
	// Come generare lo spazio in memoria per la password.
	Password = (char*)calloc(scelta,sizeof(char));
	
	srand((unsigned)time(NULL)); // inizializzo il generatore casuale.
	
	for (int i = 0; i < scelta; i++){
		// Sceglie a caso un carattere dal "charset" e lo inserisce nella stringa "Password".
		Password[i] = charset[rand() % 67];
	}
	
	cout << "\nLa password generata e': " << Password;
	
	return 0;
}
