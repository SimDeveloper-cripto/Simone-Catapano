#include <stdio.h>

union number{
    int x; 
    double y;
};

int main(){
    union number value;

    value.x = 100;
    printf("Put 100 in the integer member and print both\nint: %d\ndouble: %f", value.x, value.y);

    value.y = 100.0;
    printf("\nPut 100.0 in the floating member and print both\nint: %d\ndouble: %f", value.x, value.y);

    return 0;
}