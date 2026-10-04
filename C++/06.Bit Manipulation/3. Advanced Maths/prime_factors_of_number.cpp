/*
QUESTION:
Given a number N, find its unique prime factors in increasing order.

Example:
Input: N = 100
Output: 2 5
Explanation: 2 and 5 are the unique prime factors of 100.

APPROACH:
To find the unique prime factors of a number N, we can iterate from 2 to sqrt(N) and check if each number divides N.
1. Initialize an empty vector `ans` to store the prime factors.
2. Iterate from 2 to sqrt(N):
   - If `i` divides `N` (i.e., N % i == 0):
     - Add `i` to `ans`.
     - Divide `N` by `i` until it is no longer divisible by `i`.
3. If `N` is still greater than 1, it means that `N` itself is a prime factor. Add it to `ans`.
4. Return `ans`.

CODE:*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
    bool isPrime(int num)
    {
        bool isPrime = true;
        for(int i=2; i<num; ++i)
        {
            if(num % i == 0) isPrime = false;
        }
        return isPrime;
    }

    vector<int> primeFactorsBF(int num)
    {
        vector<int> ans;
        for(int i=2; i<num; ++i)
        {
            if(num%i == 0)
            {
                if(isPrime(i)) ans.push_back(i);
            }
        }
        return ans;
    }

    // Time Complexity - O(N)
    // Space Complexity - O(1)

    vector<int> primeFactorsOptimal(int num)
    {
        vector<int> ans;
        for(int i=2; i*i<=num; ++i)
        {
            if(num%i == 0)
            {
                ans.push_back(i);

                while(num%i == 0) 
                {
                    num = num/i;
                }
            }
            //ans.push_back(num/i);
        }
        if(num > 1) ans.push_back(num); // last remaining number

        return ans;
    }

    // Time Complexity - O(log N)
    // Space Complexity - O(1)
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> res1 = sol.primeFactorsBF(n);
    vector<int> res3 = sol.primeFactorsOptimal(n);

    for(vector<int>::iterator it = res1.begin(); it != res1.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    for(vector<int>::iterator it = res3.begin(); it != res3.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}


// Time Complexity: O(sqrt(N))
// Space Complexity: O(1) (excluding the space required for the output vector)


