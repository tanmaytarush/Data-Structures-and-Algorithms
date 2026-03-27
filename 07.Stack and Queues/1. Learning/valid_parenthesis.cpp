/*
QUESTION:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

Example:
Input: s = "()"
Output: true

APPROACH:
- We can use a stack to keep track of the opening brackets.
- Whenever we encounter an opening bracket, we push it onto the stack.
- If we encounter a closing bracket, we check if it matches the top of the stack.
- If the closing bracket matches the top of the stack, we pop the top element from the stack.
- If at any point the closing bracket does not match the top of the stack or the stack is empty, the string is not valid.
- Finally, if the stack is empty after processing all characters, the string is valid.

CODE:
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    bool validParentheses(string s)
    {
        stack<int> st;
        for(int i=0; i<s.length(); ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }

            else
            {
                if(st.empty()) return false;

                char ch = st.top();
                st.pop();

                if((s[i] == ')' && ch == '(') ||
                    (s[i] == '}' && ch == '{') ||
                    (s[i] == ']' && ch == '['))
                    continue;
                else return false; 
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution obj;

    string s;
    getline(cin, s);
    bool result = obj.validParentheses(s);

    cout<<result;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- The code iterates through the input string once, so the time complexity is O(n), where n is the length of the input string.
- The space complexity is O(n) as we use a stack to store the opening brackets.
*/

