/*
QUESTION:
You are given a string S of size N that represents the prefix form of a valid mathematical expression. Convert it to its infix form.

Example:
Input: 
*-A/BC-/AKL
Output: 
((A-(B/C))*((A/K)-L))
Explanation: 
The above output is its valid infix form.

APPROACH:
- We can use a stack to convert the prefix expression to infix.
- We iterate through each character of the input string in reverse order.
- If the character is an operand (letter or digit), we push it onto the stack.
- If the character is an operator, we pop two operands from the stack, concatenate them with the operator and enclosing parentheses, and push the result back onto the stack.
- After iterating through all characters, the top of the stack will contain the final infix expression.

CODE:
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    string prefixToInfix(string s)
    {
        int n = s.length();
        int i = n-1;
        stack<string> st;

        while(i>=0)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                st.push(string(1, s[i])); // create a string of size 1 and push
            }
            else
            {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();

                string ans = '(' + t1 + s[i] + t2 + ')';
                st.push(ans);
            }
            i--;
        }

        return st.top();
    }
};

int main()
{
    Solution sol;

    string str;
    getline(cin, str);

    string ans = sol.prefixToInfix(str);

    cout<<ans<<endl;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of the preToInfix function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operands.
*/
