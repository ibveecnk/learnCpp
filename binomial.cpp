#include <stdio.h>
#include <iostream>
#include <chrono>

using namespace std;

// Recursively calculate n over k
long long binomial(int n, int k)
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
long long binomial_iter(int n, int k)
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
    typedef std::chrono::high_resolution_clock Clock;

    // Variable declaration
    int n, k;
    long long res;
    std::chrono::high_resolution_clock::time_point t1, t2;
    std::chrono::duration<double> duration;

    printf("Enter two integers to calculate the binomial coefficient of:\n");

    printf("n = ");
    cin >> n;

    printf("k = ");
    cin >> k;

    t1 = Clock::now();
    res = binomial_iter(n, k);
    t2 = Clock::now();
    duration = t2 - t1;
    cout << "Iterative: " << n << " over " << k << " is " << res << " (took " << duration.count() << "s)" << endl;

    t1 = Clock::now();
    res = binomial(n, k);
    t2 = Clock::now();
    duration = t2 - t1;
    cout << "Recursive: " << n << " over " << k << " is " << res << " (took " << duration.count() << "s)" << endl;

    return 1;
}
