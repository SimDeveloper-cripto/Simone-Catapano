#include <iostream>
using namespace std;

int i, space, rows;
int k = 0;

int main (){
	cout << "Enter the number of rows: \t"; cin >> rows;
	
	for (i = 1; i <= rows; ++i){
		for (space = 1; space <= rows-i; ++space){
			cout<<"  ";
		}
		while (k != 2*i-1) {
			cout << "* ";
			k++;
		}
		k = 0;
		cout << "\n";
	}
	return 0;
}

