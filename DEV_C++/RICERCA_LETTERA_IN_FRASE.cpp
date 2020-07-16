#include <iostream>
#include <string.h>
using namespace std;

int found = 0;
int i = 0;
string parola = "";
string carattere = "f";

int main(int argc, char* argv[]){
	system("title RICERCA LETTERA F NELLE FRASI");
	system("color 0A");
	
	cout << "Inserire una parola: "; getline(cin, parola);
	
	while (found != -1){
		found = parola.find(carattere, i);
		cout << "F, trovata in posizione: " << found << endl;
		i = found + 1;
	}
	system("pause");
}
