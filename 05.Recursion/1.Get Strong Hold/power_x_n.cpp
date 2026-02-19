/*
Implement Pow(x,n) | X raised to the power N

Problem Statement: Implement the power function pow(x, n) , which calculates the x raised to n i.e. xn.

Examples
Example 1:
Input:
 x = 2.0000, n = 10  
Output:
 1024.0000  
Explanation:
 The answer is calculated as 2^10, which equals 1024.

Example 2:
Input:
 x = 2.0000, n = -2  
Output:
 0.2500  
Explanation:
 The answer is calculated as 2^(-2), which is equal to 1/4 = 0.25.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<math.h>
using namespace std;

double powerMath(double x, int n)
{
    double ans = 1.0;
    long nn = n;

    if(nn < 0) nn = -1*nn;

    while(nn > 0)
    {
        if(nn % 2 == 1)
        {
            ans = ans * x;
            nn = nn - 1;
        }

        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }

    if(nn < 0) return (double)(1.0) / (double)(ans);

    return ans;
}

double powerMathRecursive(double x, int n)
{
    if(n == 0) return 1;

    if(x == 0) return 0;

    if(n % 2 == 0)
    {
        return powerMathRecursive(x*x, n/2);
    }

    if(n % 2 == 1)
    {
        return x * powerMathRecursive(x*x, n/2);
    }
}

double power(double x, int n)
{   
    if(n < 0)
    {
        double ans = powerMathRecursive(x, n);
        return (1 / ans);
    }

    return powerMathRecursive(x, n);
}

int main()
{
    int n;
    cin>>n;

    int x;
    cin>>x;

    double result = powerMath(x, n);
    cout<<result<<endl;

    double ans = power(x, n);
    cout<<ans<<endl;

    return 0;
}