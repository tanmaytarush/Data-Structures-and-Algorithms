/*

** GCD of Two Numbers:-

You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.


Examples:
Input: n1 = 4, n2 = 6

Output: 2

Explanation: Divisors of n1 = 1, 2, 4, Divisors of n2 = 1, 2, 3, 6

Greatest Common divisor = 2.

Input: n1 = 9, n2 = 8

Output: 1

Explanation: Divisors of n1 = 1, 3, 9 Divisors of n2 = 1, 2, 4, 8.

Greatest Common divisor = 1.


EUCLIDEAN ALGORITHM:

GCD(a, b) = GCD(a-b, b)
GCD(a, b) = GCD(a%b, b)

*/

#include<iostream>
using namespace std;

class GCD{
public:
    int gcd_bf(int a, int b) // O(N)
    {
        int gcd;
        for(int i = min(a,b); i>=1; --i)
        {
            if(a%i==0 && b%i==0)
            {
                gcd = i;
                break;
            }
        }
        return gcd;
    }

    int gcd_euclidean(int a, int b) // O(log(N))
    {
        for(int i = min(a,b); i>=1; --i)
        {
            if(a>b) a=a-b;
            else b=b-a;
        }
        if(a==0){
            return b;
        }
        else{
            return a;
        }
    }

    int gcd_euc(int a, int b)
    {
        for(int i=min(a,b); i>=1; --i) // O(log(N))
        {
            if(a>b) a=a%b;
            else b=b%a; 
        }
        if(a==0){
            return b;
        }
        else{
            return a;
        }
    }
};

int main()
{
    GCD g1;
    int t;
    cin>>t;
    for(int i=0; i<t; ++i)
    {
        int a, b;
        cin>>a>>b;
        int ans1 = g1.gcd_bf(a,b);
        int ans2 = g1.gcd_euc(a,b);
        int ans3 = g1.gcd_euclidean(a,b);
        cout<<ans1<<" "<<ans2<<" "<<ans3;
    }
    return 0;
}