#include <stdio.h>

int main(void){
	int x,y,z;
	
		x = 0;
		y = 1;
		do{
			printf("%d\n", x);	
			z = x+y;
			x = y;
			y = z;
		}while (x <255);
}
