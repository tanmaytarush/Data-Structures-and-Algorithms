/*

Given an integer x, return true if x is a palindrome, and false otherwise. 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

*/

#include<iostream>
using namespace std;

class Palindrome{
public:
    int rev_number(int x)
    {
        int rev = 0;
        while(x!=0)
        {
            int digit = x%10;
            x = x / 10;

            // Overflow Handling 
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit>7))
                return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && digit<-8))
                return 0;

            rev = (rev*10) + digit;
        }
        return rev;
    }

    bool isPalindrome(int x)
    {
        if(x<0)
            return false;
        if(rev_number(x) == x)
            return true;
        else   
            return false;
    }
};

int main()
{
    Palindrome p1;
    int t;
    cin>>t;
    for(int i=0; i<t; ++i)
    {
        int n;
        cin>>n;
        bool answer = p1.isPalindrome(n);
        cout<<answer;
    }
    return 0;
}