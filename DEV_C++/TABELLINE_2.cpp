#include <iostream>
using namespace std;

int main() {
	int numero = 0;
	
	cout << "Inserire il numero di cui fare la tabellina (max 10): "; 
	cin >> numero;
		
	for (int i = 1; i <= 10; i++) {
		int tabellina = numero * i;
		cout << tabellina << endl;
	}
	
	return 0;
}
