#include <iostream>
#include <cmath>
using namespace std;

int a = 0;
int b = 0;
int c = 0;
int delta = 0;
float x1 = 0;
float x2 = 0;

int main (int argc, char* argv[]) {
	
	cout << "Inserisci il valore della x2:"; cin >> a;
	cout << "Inserisci il valore della x:"; cin >> b;
	cout << "Inserisci il valore del termine noto:"; cin >> c;
	
	delta = sqrt((b*b)-4*(a*c));
	if (delta > 0) {
		x1 = (-b+delta) / (2*a);
		x2 = (-b-delta) / (2*a);
		cout << "LE SOLUZIONI SONO:\t \n:" << x1 << x2 << endl;
	} else if (delta < 0) {
		cout<<"LA SOLUZIONE E PRESENTE SOLO NEI NUMERI COMPLESSI" << endl;
	} else (delta == 0) {
		x1 = (-b+(sqrt(b*b-4*a*c)));
		x2 = (-b-(sqrt(b*b-4*a*c)));
		cout << "LE SOLUZIONI SONO \n" << x1 << x2;
	}
	return 0;
}
