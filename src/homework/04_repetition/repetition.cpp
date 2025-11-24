//add include statements
#include "repetition.h"

//add function(s) code here

// Returns the factorial of a given number 'num'.
int get_factorial(int num)
{
    int factorial = 1;
    
    for (int i = 1; i <= num; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

// Returns the sum of all odd numbers from 1 up to and including 'num'.
int sum_odd_numbers(int num)
{
    int sum = 0;
    int i = 1;

    while (i <= num){
        sum += i;
        i += 2;
    }
    return sum;
}