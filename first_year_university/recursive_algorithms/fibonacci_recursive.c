/*
    This time we're gonna implement an algotithm to show the fibonacci value of the nth integer.
    Let's see!.
    To do this we'll use recursive approach.
*/
#include <stdio.h> // Standard I/O library

unsigned long int fibonacci(unsigned int number); // prototype of the procedure.
// we used that value to be returned because the fibonacci series is an exponential function, so it grows up fast.
// With that being said, let's work it out!.
int main(void)
{
    unsigned long int result = 0;
    unsigned int fib = 0;

    printf("Enter a number: ");
    scanf("%u", &fib);

    result = fibonacci(fib);

    printf("Fibonacci (%u): %lu", fib, result);
}

unsigned long int fibonacci(unsigned int n)
{
    if(n <= 1){
        return n;
    } else {
        return (fibonacci(n-1) + fibonacci (n-2));
    }
}