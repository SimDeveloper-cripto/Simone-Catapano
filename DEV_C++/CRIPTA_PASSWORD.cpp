#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

char pass[32]; 
char a; 
int k = 0, j; // k = Contatore lettera maiuscola
              // j = Indice del ciclo di delay
int main () {
	system("color 1f");
    
    cout << "Inserisci la password: ";
    
   do{
   	 for (int i = 0 ;;) { // Ciclo infinito.
    a = getch(); // Attesa di Input.
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' &&  a <= '9')) { 
           if (a >= 'A' && a <= 'Z') {
           	   k = k + 1;
            }
            pass[i] = a;
            ++ i;
            cout << "*";
        }
        if (a == '\r'){ // La stringa si cancella e finisce il ciclo se premi INVIO.
         	if (k == 1) {
            pass [i] = '\0'; 
            cout << endl;
            cout << "La password inserita e': " << pass << endl << endl;
            break; 
           } 
		   if (k == 0 || k > 1){
		   	pass [i] = '\0'; // AZZERA IL CONTENUTO DEL VETTORE
		   	cout << "\nErrore! ";
		   	_sleep(1500);
          	cout << "La password deve contenere solo un carattere maiuscolo!"<< endl;
          	_sleep(1500);
          	cout << "Attivazione richiesta input";
          	for (j = 0; j < 3; j++){
          	_sleep(1000);
          	cout << ".";
            }
          	system("cls");
          	cout << "Inserisci nuovamente la password: ";
          	k = 0; 
          	break;
		  }
        }
	 }  
   } while (k == 0 || k > 1);

    system("pause");
}
