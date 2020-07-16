#include <iostream>
#include <stdlib.h>
using namespace std;

int i,r;

int main (void){
	i = 0;
	while (i++ < 10){
		r = (rand() % 10) + 1;
		cout << r <<" ";
	}
}
