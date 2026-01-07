/*
Question:
Given a VPS represented as a string s, return the nesting depth of s.

Approach:
1. Initialize `opened` as 0 and `ans` as 0 to keep track of the number of opened parentheses and the maximum nesting depth respectively.
2. Iterate through each character `c` in the string `s`.
    a. If `c` is an opening parenthesis '(', increment `opened` by 1 and update `ans` if it is greater than the current value of `ans`.
    b. If `c` is a closing parenthesis ')', decrement `opened` by 1.
3. Return `ans` as the maximum nesting depth.

CODE:-
*/

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int maxNestingDepth(string s)
{
    int opened = 0;
    int i=0;
    int max_depth = 0;
    while(i < s.length())
    {
        if(s[i] == '(')
        {
            opened ++;
            max_depth = max(max_depth, opened);
        }
        else if(s[i] == ')')
        {
            opened --;
            
        }
        i++;
    }

    if(opened != 0) // check for VPS
    {
        return -1;
    }
    
    return max_depth;
}

int main()
{
    string s;
    getline(cin, s);

    int result = maxNestingDepth(s);

    cout<<result;
    return 0;
}

/*
Time Complexity: O(n), where n is the length of the string `s`.
Space Complexity: O(1)
*/