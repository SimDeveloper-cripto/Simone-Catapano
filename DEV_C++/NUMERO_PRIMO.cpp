#include <iostream>
using namespace std;

char r;

int main (void) {
	clrscr(); 
	
	int i = 0;
	int k = 0;
	
	cout << "Immetti il numero: "; cin>>k;
	if(k == 1) {
		cout << "Il numero primo più piccolo è 2" << endl;
	}
	for (i = 2; i < k; i++) {
		if(k % i == 0) {
			cout<<"Non è un numero primo" <<endl;
			break;
		}
	}
	if(k == i) {
		cout<<"Numero primo" <<endl;
	}
}


