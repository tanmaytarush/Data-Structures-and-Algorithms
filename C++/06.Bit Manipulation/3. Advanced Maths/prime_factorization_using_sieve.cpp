/*
QUESTION:
Given a positive number N, compute its prime factorization using the concept of Sieve.

Example:
Input: N = 12246
Output: 2 3 13 157
Explanation: The prime factorization of 12246 is 2 * 3 * 13 * 157.

APPROACH:
To compute the prime factorization of a number N, we can use the concept of Sieve.
1. Create a boolean vector `prime` of size N+1 and initialize all elements to true. This vector will be used to mark numbers as prime or not.
2. Create an empty vector `ans` to store the prime factors of N.
3. Iterate from 2 to sqrt(N):
   - If prime[i] is true (i.e., i is a prime number):
     - While N is divisible by i, add i to the `ans` vector and divide N by i.
     - Mark all multiples of i as false in the `prime` vector, as they are not prime.
4. If N is greater than 1, it means N is a prime number itself, so add N to the `ans` vector.
5. Return the `ans` vector, which will contain the prime factors of N.

CODE:*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    bool isPrime(int num)
    {
        bool isPrime = true;
        for(int i=2; i<num; ++i)
        {
            if(num%i == 0)
            {
                isPrime = false;
            }
        }
        return isPrime;
    }

    vector<int> primtFactorsBF(int num)
    {
        vector<int> arr;
        for(int i=2; i<num; ++i)
        {
            if(num%i == 0)
            {
                if(isPrime(i)) arr.push_back(i);
            }
        }
        return arr;
    }

    vector<int> primeFactor(int num)
    {
        vector<int> arr;
        for(int i=2; i*i<=num; ++i)
        {
            if(num % i == 0)
            {
                arr.push_back(i);
                while(num % i == 0)
                {
                    num = num/i; // removes all the multiples of 2's factors
                }
            }
        }
        if(num > 1) arr.push_back(num);
        return arr;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> result = sol.primtFactorsBF(n);
    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    vector<int> result2 = sol.primeFactor(n);
    for(vector<int>::iterator it = result2.begin(); it != result2.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}

// Time Complexity: O(N log(log N))
// Space Complexity: O(N)


