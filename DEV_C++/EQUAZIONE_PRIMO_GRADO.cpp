#include <iostream>
#include <cmath>
using namespace std;

int a = 0;
int b = 0;
int x = 0;

int main () {
	cout << "Dammi i valori di a e b:\n";
	cin >> a >> b;
	if ((a != 0) and (b != 0)) {
		x = (-b/a);
		cout << "L'incognita si puo calcolare ed il suo valore è determinato \n" << x;
	} else if (a == 0) {
		cout << "INCOGNITA IMPOSSIBILE DA CALCOLARE" << endl;
	} else ((a == 0) && (b == 0)) {
		cout << "INCOGNITA INDETERMINATA" << endl;
	}
	return 0;
}




