// A C++ implementation of the above idea to process
// queries of finding a number with maximum divisors.
#include <bits/stdc++.h>
using namespace std;
 
#define maxn 1000005
#define INF 99999999
 
long long smallest_prime[maxn];
long long divisors[maxn];
long long segmentTree[4 * maxn];
 
// Finds smallest prime factor of all numbers in
// range[1, maxn) and stores them in smallest_prime[],
// smallest_prime[i] should contain the smallest prime
// that divides i
void findSmallestPrimeFactors()
{
    // Initialize the smallest_prime factors of all
    // to infinity
    for (long long i = 0 ; i < maxn ; i ++ )
        smallest_prime[i] = INF;
 
    // to be built like eratosthenes sieve
    for (long long i = 2; i < maxn; i++)
    {
        if (smallest_prime[i] == INF)
        {
            // prime number will have its smallest_prime
            // equal to itself
            smallest_prime[i] = i;
            for (long long j = i * i; j < maxn; j += i)
 
                // if 'i' is the first prime number reaching 'j'
                if (smallest_prime[j] > i)
                    smallest_prime[j] = i;
        }
    }
}
 
// number of divisors of n = (p1 ^ k1) * (p2 ^ k2) ... (pn ^ kn)
// are equal to (k1+1) * (k2+1) ... (kn+1)
// this function finds the number of divisors of all numbers
// in range [1, maxn) and stores it in divisors[]
// divisors[i] stores the number of divisors i has
void buildDivisorsArray()
{
    for (long long i = 1; i < maxn; i++)
    {
        divisors[i] = 1;
        long long n = i, p = smallest_prime[i], k = 0;
 
        // we can obtain the prime factorization of the number n
        // n = (p1 ^ k1) * (p2 ^ k2) ... (pn ^ kn) using the
        // smallest_prime[] array, we keep dividing n by its
        // smallest_prime until it becomes 1, whilst we check
        // if we have need to set k zero
        while (n > 1)
        {
            n = n / p;
            k ++;
 
            if (smallest_prime[n] != p)
            {
                //use p^k, initialize k to 0
                divisors[i] = divisors[i] * (k + 1);
                k = 0;
            }
 
            p = smallest_prime[n];
        }
    }
}
 
// builds segment tree for divisors[] array
void buildSegtmentTree(long long node, long long a, long long b)
{
    // leaf node
    if (a == b)
    {
        segmentTree[node] = divisors[a];
        return ;
    }
 
    //build left and right subtree
    buildSegtmentTree(2 * node, a, (a + b) / 2);
    buildSegtmentTree(2 * node + 1, ((a + b) / 2) + 1, b);
 
    //combine the information from left
    //and right subtree at current node
    segmentTree[node] = max(segmentTree[2 * node],
                            segmentTree[2 *node + 1]);
}
 
//returns the maximum number of divisors in [l, r]
long long query(long long node, long long a, long long b, long long l, long long r)
{
    // If current node's range is disjoint with query range
    if (l > b || a > r)
        return -1;
 
    // If the current node stores information for the range
    // that is completely inside the query range
    if (a >= l && b <= r)
        return segmentTree[node];
 
    // Returns maximum number of divisors from left
    // or right subtree
    return max(query(2 * node, a, (a + b) / 2, l, r),
               query(2 * node + 1, ((a + b) / 2) + 1, b,l,r));
}
 
// driver code
int main()
{
    // First find smallest prime divisors for all
    // the numbers
    findSmallestPrimeFactors();
 
    // Then build the divisors[] array to store
    // the number of divisors
    buildDivisorsArray();
 
    // Build segment tree for the divisors[] array
    buildSegtmentTree(1, 1, maxn - 1);
    
    long long numb;

    while (cin >> numb){
        cout << query(1, 1, maxn - 1, 1, numb) << "\n";
    }
 
    return 0;
}