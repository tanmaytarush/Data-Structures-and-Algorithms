/*

Problem Statement: "Given a string, check if the string is palindrome or not."  A string is said to be palindrome if the reverse of the string is the same as the string.

Examples:

Example 1:
Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.

Example 2:
Input: Str = “TAKE U FORWARD”
Output: Not Palindrome
Explanation: String when reversed is not the same as string.

*/

#include<iostream>
#include<string>
using namespace std;

class Palindrome{
public:
    bool palindrome_string(int i, string &s)
    {
        if(i>=s.size()/2)
        {
            return true;
        }
        if(s[i] != s[s.size()-i-1])
        {
            return false;
        }
        return palindrome_string(i+1, s);
    }
};

int main()
{
    Palindrome p1;
    string s = "Madam";
    for(char &c : s) c = tolower(c);
    cout<<p1.palindrome_string(0, s);
    return 0;
}