/*
Question:
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example:
Input: s = "(*))"
Output: true

Approach:
- We maintain two counters `cmin` and `cmax` to keep track of the minimum and maximum possible number of open parentheses.
- We iterate over the characters in the string.
- For each character:
  - If it is '(', we increment both `cmin` and `cmax`.
  - If it is ')', we decrement `cmax` and update `cmin` to the maximum of `cmin - 1` and 0 (to handle cases where '*' is treated as '(').
  - If it is '*', we increment `cmax` (considering '*' as '(') and update `cmin` to the maximum of `cmin - 1` and 0 (to handle cases where '*' is treated as ')').
  - If `cmax` becomes negative at any point, it means even after treating all '*' as '(' we can't maintain balance, so we return false.
- Finally, we check if `cmin` is 0, which means we have balanced parentheses.

Complexity Analysis:
- The time complexity of this approach is O(N), where N is the length of the string s.
- We iterate over each character once.
- The space complexity is O(1) as we are using only a constant amount of extra space.

Code:
*/

// NOTE- this approach is not intuitive but the most optimal however we can use recursion to solve this problem and optimize it using dp.
// We can also solve this using recursion where in the case of '*' we will make 3 recursion calls,
//  1-> where opencnt++,
//  2-> where opencnt
//  3-> where opencnt--
//  The base case would be at end if opencnt == 0 return true else false.


#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    bool isValidRecursive(string str, int index, int count)
    {
        int n = str.length();
        if(count < 0)
        {
            return false;
        }
        if(index == n)
        {
            return (count == 0);
        }

        if(str[index] == '(')
        {
            return isValidRecursive(str, index + 1, count + 1);
        }
        if(str[index] == ')')
        {
            return isValidRecursive(str, index + 1, count - 1);
        }

        return (isValidRecursive(str, index+1, count+1) || isValidRecursive(str, index+1, count-1)
                || isValidRecursive(str, index+1, count));
    }

    bool isValidOptimal(string str)
    {
        int n = str.length();
        int min = 0;
        int max = 0;

        for(int i=0; i<n; ++i)
        {
            if(str[i] == '(')
            {
                min += 1;
                max += 1;
            }
            else if(str[i] == ')')
            {
                min -= 1;
                max -= 1;
            }        
            else
            {
                min -= 1;
                max += 1;
            }

            if(min < 0) min = 0;
            if(max < 0) return false;
        }

        return (min == 0);
    }
};

int main()
{
    Solution sol;

    string str;
    getline(cin, str);

    bool res1 = sol.isValidRecursive(str, 0, 0);
    bool res2 = sol.isValidOptimal(str);

    cout<<res1<<endl;
    cout<<res2<<endl;

    return 0;
}