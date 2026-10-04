/*
QUESTION:
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

Example:
Input: x = 2.00000, n = 10
Output: 1024.00000

APPROACH:
To calculate x raised to the power n, we can use the concept of binary exponentiation.
1. If n is 0, return 1, as any number raised to the power 0 is 1.
2. Initialize a variable res to 1 to store the result.
3. If n is negative, set isNegative flag to true and make n positive.
4. Iterate until n becomes 0:
   - If the least significant bit of n is 1 (i.e., n is odd), multiply res by x.
   - Update x to x^2 by multiplying it with itself.
   - Right-shift n by 1 to remove the least significant bit.
5. If isNegative is true, return 1/res; otherwise, return res.

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
    int fastPower(int x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn = (-1*nn);

        while(nn > 0)
        {
            if(nn % 2 == 1)
            {
                ans = ans * x;
                nn -= 1;
            }
            else
            {
                x = x*x;
                nn = nn/2;
            }
        }

        if(nn < 0) ans = (double)1.0 / (double)ans;

        return ans;
    }
};

int main()
{
    Solution sol;

    int x;
    cin>>x; 

    int n;
    cin>>n;

    int result = sol.fastPower(x, n);
    cout<<result;

    return 0;
}

// Time Complexity: O(log(n))
// Space Complexity: O(1)


