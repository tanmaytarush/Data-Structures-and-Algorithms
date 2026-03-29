/*
QUESTION:
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

Example:
Input: 
ABC/-AK/L-*
Output: 
*-A/BC-/AKL
Explanation: 
The above output is its valid prefix form.

APPROACH:
- We can use a stack to convert the postfix expression to prefix.
- We iterate through each character of the input string.
- If the character is an alphanumeric character, we push it onto the stack.
- If the character is an operator, we pop two operands from the stack, concatenate them with the operator in the proper order (operator + operand2 + operand1), and push the result back onto the stack.
- After iterating through all characters, the top of the stack will contain the final prefix expression.

CODE:
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    string postfixToPrefix(string s)
    {
        int n = s.length();
        int i = 0;
        stack<string> st;

        while(i<n)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string res = s[i] + t2 + t1;
                st.push(res);
            }
            i++;
        }

        return st.top();
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);

    string ans = sol.postfixToPrefix(s);

    cout<<ans;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of the postToPre function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operands.
*/
