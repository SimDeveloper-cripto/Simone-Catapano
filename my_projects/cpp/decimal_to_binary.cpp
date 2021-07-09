#include <iostream>
#include <string>
using namespace std;

int main(){
	int decimal = 0;
	string binario = "";
	
	cin >> decimal;
	
	do{
		if(decimal % 2 == 0) binario = "0" + binario;
		else binario = "1" + binario;
		decimal /= 2;
	} while(decimal != 0);
	
	cout << "Numero binario: " << binario << endl;
	
	return 0;
}
