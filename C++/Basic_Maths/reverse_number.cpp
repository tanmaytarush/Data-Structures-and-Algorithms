/*

Reverse a number (Easy) :-

You are given an integer n. Return the integer formed by placing the digits of n in reverse order.


Examples:
Input: n = 25

Output: 52

Explanation: Reverse of 25 is 52.

Input: n = 123

Output: 321

Explanation: Reverse of 123 is 321.


Overflow Check :

Part 1: `rev > INT_MAX/10`
	•	`INT_MAX = 2147483647` 
	•	`INT_MAX/10 = 214748364`
	•	If `rev` is already greater than 214748364, then multiplying by 10 will definitely exceed INT_MAX 
Part 2: `(rev == INT_MAX/10 && digit>7)`
	•	When `rev = 214748364` (exactly `INT_MAX/10`)
	•	The last digit of INT_MAX is 7 
	•	So we can safely add digits 0, 1, 2, 3, 4, 5, 6, or 7
	•	If `digit > 7`, the result would be `2147483648` or higher, which exceeds INT_MAX

Similar goes for negative minimum check

*/

#include<iostream>
using namespace std;

int reverse_number(int n)
{
    int rev = 0;
    while(n!=0)
    {
        int digit = n%10;
        n = n/10;
        
        // Overflow Handling, when values outside the range
        if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit > 7))
            return 0;
        if(rev < INT_MIN/10 || (rev == INT_MIN/10 && digit < -8))
            return 0;

        rev = (rev*10) + digit;
    }
    return rev;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; ++i)
    {
        int n;
        cin>>n;
        int ans = reverse_number(n);
        cout<<ans;
    }
    return 0;
}