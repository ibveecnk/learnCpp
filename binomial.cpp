#include <stdio.h>
#include <iostream>

using namespace std;

// Recursively calculate n over k
int binomial(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return binomial(n - 1, k - 1) + binomial(n - 1, k);
    }
}

// Iteratively calculate n over k
int binomial_iter(int n, int k)
{
    int result = 1;
    for (int i = 1; i <= k; i++)
    {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}

int main()
{
    int n, k;
    printf("Enter two integers to calculate the binomial coefficient of:\n");
    printf("n = ");
    cin >> n;
    printf("k = ");
    cin >> k;
    printf("Recursive: %d over %d is %d\n", n, k, binomial(n, k));
    printf("Iterative: %d over %d is %d\n", n, k, binomial_iter(n, k));
    return 1;
}
