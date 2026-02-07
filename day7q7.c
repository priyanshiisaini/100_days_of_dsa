#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fib(int n)
{
    if (n == 0)
        return 0;          // base case 1
    else if (n == 1)
        return 1;          // base case 2
    else
        return fib(n-1) + fib(n-2);   // recursive call
}

int main()
{
    int n;
    
    scanf("%d", &n);       // take input
    
    printf("%d", fib(n));  // print nth Fibonacci number
    
    return 0;
}
