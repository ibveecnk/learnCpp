#include <stdio.h>
#include <iostream>

using namespace std;

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

int main()
{
    printf("Enter an integer to calculate the faculty of: ");
    int n;
    cin >> n;
    printf("The faculty of %d is %d\n", n, factorial(n));
    return 1;
}
