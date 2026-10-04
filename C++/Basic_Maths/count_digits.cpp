/*

Count Digits of a Number: Easy

You are given an integer n. You need to return the number of digits in the number.
The number will have no leading zeroes, except when the number is 0 itself.

Examples:
Input: n = 4

Output: 1

Explanation: There is only 1 digit in 4.

Input: n = 14

Output: 2

Explanation: There are 2 digits in 14.

*/

#include<iostream>
#include<math.h>
using namespace std;

int count_digits_1(int n)
{
    int cnt = 0;
    while(n>0)
    {
        int rem = n%10;
        cnt += 1;
        n = n/10;
    }
    return cnt;
}

int count_digits_2(int n)
{
    int cnt = 0;
    while(n>0)
    {
        // int rem=n%10;
        cnt += 1;
        n = n/10;
    }
    return cnt;   
}

int count_digits_3(int n) // Logarithm of number = Number of digits
{
    if (n == 0)
        return 1;
    return static_cast<int>(log10(abs(n))) + 1;  // Type Casting STL
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; ++i)
    {
        int n;
        cin>>n;
        cout<<count_digits_1(n);
        cout<<count_digits_2(n);
        cout<<count_digits_3(n);
    }
    return 0;
}