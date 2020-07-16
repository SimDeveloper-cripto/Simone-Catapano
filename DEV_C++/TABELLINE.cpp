#include <iostream>
#include <iomanip>
using namespace std;

short int m1,k;

int main (int argc, char* argv[]){
	
	cout << "Dammi il fattore: \t"; cin >> m1;
	
	if (m1 > 0 && m1 <= 12){
		for (int k = 1;k <= 10;k++){
			cout << setw(10) << k;
			cout << setw(10) << k * m1;
			cout << endl;
		}	
	} else {
		cout<<"errore! \n";
	}	
	return 0;
}

