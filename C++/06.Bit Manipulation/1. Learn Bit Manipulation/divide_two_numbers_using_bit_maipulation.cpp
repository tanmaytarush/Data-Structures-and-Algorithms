/*
QUESTION:
Given two integers dividend and divisor, find the quotient after dividing dividend by divisor without using multiplication, division, and mod operator.

Example:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 gives a quotient of 3 and remainder of 1.

APPROACH:
To divide two integers without using multiplication, division, and mod operator, we can use a bitwise shifting approach.
1. Initialize a variable ans as 0 to store the quotient.
2. Check if the dividend and divisor have different signs to determine the sign of the quotient.
3. Take the absolute values of the dividend and divisor to work with positive numbers.
4. Iterate while the absolute value of the dividend is greater than or equal to the absolute value of the divisor:
    a. Initialize a variable q as 1 to represent the current quotient digit.
    b. Iterate while the absolute value of the dividend is greater than the absolute value of the divisor left-shifted by q:
        i. Increment q.
    c. Add (1 << (q - 1)) to the quotient ans.
    d. Subtract the absolute value of the divisor left-shifted by (q - 1) from the absolute value of the dividend.
5. Return the quotient ans, considering the sign based on the step 2.

CODE:*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

int divide(int divident, int divisor)
{
    if(divident == divisor) return 1;

    bool sign = true;
    if(divident >=0 && divisor < 0) sign = false;
    if(divident < 0 && divisor > 0) sign = false;

    long n = abs(divident);
    long d = abs(divisor);
    divisor = abs(divisor);

    long quotient = 0;

    while(n >= d)
    {
        int count = 0;
        while(n >= (d << (count + 1)))
        {
            count++;
        }

        quotient += (1 << (count));
        n = n - (d << count);
    }

    if(quotient == (1<<31) && sign)
    {
        return INT_MAX;
    }

    if(quotient == (1<<31) && !sign)
    {
        return INT_MIN;
    }

    return sign ? quotient : -quotient;
}

int main()
{
    int divident;
    int divisor;

    cin>>divident;
    cin>>divisor;

    int result = divide(divident, divisor);

    cout<<result;

    return 0;
}

// Time Complexity: O(log n), where n is the absolute value of the dividend
// Space Complexity: O(1)


