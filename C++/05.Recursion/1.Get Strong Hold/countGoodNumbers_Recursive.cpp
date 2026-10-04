/*QUESTION:
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Example 1:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

Example 2:
Input: n = 4
Output: 400

Example 3:
Input: n = 50
Output: 564908303

Approach:
- We can observe that for a good digit string of length n, each digit can be either even or a prime number (2, 3, 5, or 7).
- For odd indices, there are 4 choices (2, 3, 5, or 7) since they must be prime.
- For even indices, there are 5 choices (0, 2, 4, 6, or 8) since they must be even.
- We can use a recursive approach to count the number of good digit strings.
- The base case is when n = 1, in which case there are 5 possible digit strings (0, 2, 4, 6, or 8).
- For even lengths (n % 2 == 0), we multiply the count of good digit strings of length n-1 by 4 (since there are 4 choices for odd indices).
- For odd lengths (n % 2 != 0), we multiply the count of good digit strings of length n-1 by 5 (since there are 5 choices for even indices).
- We return the result modulo 10^9 + 7 to handle large outputs.

Time Complexity: O(n) (due to the recursive calls)
Space Complexity: O(n) (due to the recursive calls)


APPROACH :

At even index:
5 choices → {0,2,4,6,8}

At odd index:
4 choices → {2,3,5,7}

So total:
If n = 4
Positions: 0 1 2 3
Choices:   5 4 5 4
Total = 5 × 4 × 5 × 4

So general formula:
even_count = (n+1)/2
odd_count = n/2
answer = (5^even_count * 4^odd_count) % mod

CODE:*/

#define LOG(x) cerr << #x << " " << x <<endl;
#define MOD 1000000007;

#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long power(long long base, long long exp)
{
    if(exp == 0)
    {
        LOG(exp);
        return 1;
    } 
    long long half = power(base, exp / 2);
    LOG(half);
    long long result = (half * half) % MOD;
    LOG(result);

    if(exp % 2 == 1)
    {
        LOG(exp);
        result = (result * base) % MOD;
    }

    return result;
}

int countGoodNumbers(long long n)
{
    return (long long)(power(5, (n + 1) / 2) * power(4, n/2)) % MOD;
}

int main()
{
    long long n;
    cin>>n;

    int result = countGoodNumbers(n);

    cout<<result<<endl;

    return 0;
}