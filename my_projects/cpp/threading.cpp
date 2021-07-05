#include <windows.h> // Contiene prototipi delle funzioni per la gestione dei thread
#include <iostream>
using namespace std;

HANDLE thread; // il tread e' sempre di tipo Handle

// necessaria funzione per la creazione e sviluppo del thread
unsigned long WINAPI frase(void*arg){
	cout << "CIAO" << endl;
	ExitThread(0);
}

int main(int argc, char*argv[]){
	thread = CreateThread (NULL,4096,&frase,NULL,0,NULL);
	WaitForSingleObject(thread, INFINITE);
	system("pause");
}
