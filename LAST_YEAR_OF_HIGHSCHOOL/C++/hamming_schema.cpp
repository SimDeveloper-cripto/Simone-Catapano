#include <iostream>
using namespace std;

int i, r1, r2, r3;
int vettore_bit[4];

// STRINGA TOTALE // r1 r2 vettore_bit[0] r3 vettore_bit[1] vettore_bit[2] vettore_bit[3]
int main(){
	
	r1 = 0;
	r2 = 0;
	r3 = 0;
	
	// carico il vettore bit[0][1][2][3]
	for (i = 0; i < 4; i++){
		do{
			cout << "Inserire il bit: ";
			cin >> vettore_bit[i];
			if ((vettore_bit[i] != 0) && (vettore_bit[i] != 1))
			cout << "ERRORE!" << endl;
		}while ((vettore_bit[i] != 0) && (vettore_bit[i] != 1));
	}
	
	cout << endl;
	
	int valore_r1 = 0;
	int valore_r2 = 0;
	int valore_r3 = 0;
	
	// r1 + vettore_bit[0] + vettore_bit[1] + vettore_bit[3]
	valore_r1 = r1 + vettore_bit[0] + vettore_bit[1] + vettore_bit[3];
	r1 = valore_r1 % 2;
	if (r1 == 0){
		r1 = 0;
		cout << "Il bit di ridondanza (r1) e': " << r1 << endl;
	} else{
		r1 = 1;
		cout << "Il bit di ridondanza (r1) e': " << r1 << endl;
	}
	
	// r2 + vettore_bit[0] + vettore_bit[2] + vettore_bit[3]
	valore_r2 = r2 + vettore_bit[0] + vettore_bit[2] + vettore_bit[3];
	r2 = valore_r2 % 2;
	if (r2 == 0){
		r2 = 0;
		cout << "Il bit di ridondanza (r2) e': " << r2 << endl;
	} else{
		r2 = 1;
		cout << "Il bit di ridondanza (r2) e': " << r2 << endl;
	}
	
	// r3 + vettore_bit[1] + vettore_bit[2] + vettore_bit[3]
	valore_r3 = r3 + vettore_bit[1] + vettore_bit[2] + vettore_bit[3];
	r3 = valore_r3 % 2;
	if (r3 == 0){
		r3 = 0;
		cout << "Il bit di ridondanza (r3) e': " << r3 << endl;
	} else{
		r3 = 1;
		cout << "Il bit di ridondanza (r3) e': " << r3 << endl;
	}
	
	cout << endl;
	
	cout << "STRINGA FINALE: ";
	cout << r1 << r2 << vettore_bit[0] << r3 << vettore_bit[1] << vettore_bit[2] << vettore_bit[3] << endl;
		
	cout << endl;
	
	system("pause");
	return 0;
}
