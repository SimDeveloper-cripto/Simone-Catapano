#include <iostream>
using namespace std;

int n,k,x[30];

void carica(){
     do {
	    cout << "Quanti numeri vuoi confrontare?: \t";
	    cin >> n;
    } while (n > 30);
     
     for (k = 0; k < n; k++){
        cout << "Inserire il numero: \t"; cin >> x[k];
    }
}

void massimo (){
	// mass = massimo //
     int mass = 0;
     
     for (k = 0; k < n; k++){
         if (x[k] > mass){
            mass = x[k];
        }
    }
    cout << "Il valore massimo è: \t " << mass << endl;
}

void minimo(){
	// mi = minimo //
     int mi = 0;
     
     for (k = 0; k < n; k++){
         if (x[k] < mi){
            mi = x[k];
        }
    }
    cout << "Il valore minimo è: \t " << mi << endl;
}

void media(){
	int a,m,b;
	
	for (k = 0; k < n; k++){
		a = a + x[k];
		b = b + a;
	}
	m = b / n;
	cout << "La media complessiva e': \t" << m << endl;
}

int main (){
    carica();
    massimo();
    minimo();
    media();
    return 0;
}

