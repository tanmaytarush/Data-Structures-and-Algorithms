/*
QUESTION:
Given an integer n, return the number of prime numbers that are strictly less than n.

Example:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, which are 2, 3, 5, and 7.

APPROACH:
To count the number of prime numbers less than a given number n, we can use the Sieve of Eratosthenes algorithm.
1. Create a boolean vector `primes` of size n+1 and initialize all elements to true. This vector will be used to mark numbers as prime or not.
2. Initialize a variable `cnt` to count the number of primes.
3. Iterate from 2 to n-1:
   - If primes[i] is true (i.e., i is a prime number), increment `cnt`.
   - Mark all multiples of i as false in the `primes` vector, as they are not prime.
4. Return `cnt`, which will be the count of prime numbers less than n.

CODE:*/

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int sieveOfEratothenes(int N)
    {
        vector<int> prime(N+1);
        for(int i=0; i<N; ++i)
        {
            prime[i] = 1;
        }

        for(int i=2; i*i<=N; ++i)
        {
            if(prime[i] == 1)
            {
                for(int j=i*i; j<=N; j+=i)
                {
                    prime[j] = 0;
                }
            }
        }

        int count = 0;
        for(int i=2; i<N; ++i)
        {
            if(prime[i] == 1) count++;
        }

        return count;
    }
};

int main()
{
    Solution sol;
    int N;
    cin>>N;

    int result = sol.sieveOfEratothenes(N);
    cout<<result;

    return 0;
}

// Time Complexity: O(n log log n)
// Space Complexity: O(n)


