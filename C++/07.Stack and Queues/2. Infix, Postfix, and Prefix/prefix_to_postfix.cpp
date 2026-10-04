/*
QUESTION:
You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

Example:
Input: 
*-A/BC-/AKL
Output: 
ABC/-AK/L-*
Explanation: 
The above output is its valid postfix form.

APPROACH:
- We can use a stack to convert the prefix expression to postfix.
- We iterate through each character of the input string in reverse order.
- If the character is an alphanumeric character, we push it onto the stack.
- If the character is an operator, we pop two operands from the stack, concatenate them with the operator, and push the result back onto the stack.
- After iterating through all characters, the top of the stack will contain the final postfix expression.

CODE:
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    string prefixToPostfix(string s)
    {
        int n = s.length();
        int i = n-1;
        stack<string> st;

        while(i>=0)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string res = t1 + t2 + s[i];
                st.push(res);
            }
            i--;
        }
        return st.top();
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);

    string ans = sol.prefixToPostfix(s);

    cout<<ans;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of the preToPost function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operands.
*/
