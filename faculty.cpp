#include <stdio.h>
#include <iostream>

using namespace std;

// Recursively calculate the factorial of n
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// Iteratively calculate the factorial of n
int factorial_iter(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int n;
    printf("Enter an integer to calculate the faculty of:\n");
    printf("n = ");
    cin >> n;
    printf("Recursive: The faculty of %d is %d\n", n, factorial(n));
    printf("Iterative: The faculty of %d is %d\n", n, factorial_iter(n));
    return 1;
}
