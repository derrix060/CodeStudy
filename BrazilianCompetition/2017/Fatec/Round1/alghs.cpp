#include <bits/stdc++.h>

using namespace std;


// with memoization
int fib(int n) {
    static vector<int> table; // our cache
    if (n <= 1) {
        return n;
    }
    else if (n >= table.size()) {
        table.resize(n+1);
    }

    if (table[n] == 0) {
        // only recalc if we don't have a value
        table[n] = fib(n-1) + fib(n-2);
    }
    return table[n];
}


// Best
int fib(int n) {
    const double sqrt5 = std::sqrt(5);
    const double phi = (1 + sqrt5) / 2;
    return (int)(std::pow(phi, n+1) / sqrt5 + 0.5);
}


// Prime numbers
// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes 
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}