/* 

You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.
An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.


Examples:
Input: n = 153

Output: true

Explanation: Number of digits : 3.

13 + 53 + 33 = 1 + 125 + 27 = 153.

Therefore, it is an Armstrong number.

Input: n = 12

Output: false

Explanation: Number of digits : 2.

12 + 22 = 1 + 4 = 5.

Therefore, it is not an Armstrong number.

*/

#include<iostream>
using namespace std;

class Armstrong{
public:
    int cubes_check(int n)
    {
        int sum = 0;
        while(n>0)
        {
            int digit = n%10;
            n = n/10;

            if(n > INT_MAX)
                return 0;

            sum  = sum + (digit * digit * digit);
        }
        return sum;
    }

    bool is_armstrong(int n)
    {
        if(n < 0)
            return false;
        if(cubes_check(n) == n)
            return true;
        else
            return false;
    }
};

int main()
{
    int t;
    cin>>t;
    Armstrong a1;

    for(int i=0; i<t; ++i)
    {
        int n;
        cin>>n;
        bool res = a1.is_armstrong(n);
        cout<<res;
    }
    return 0;
}