/*
QUESTION:
Given string num representing a non-negative integer num, and an integer k,
return the smallest possible integer after removing k digits from num.

Example:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/

/*
APPROACH:
The idea is to use a stack to build the smallest number by removing larger digits.
We iterate through each digit in num and compare it with the digits in the stack.
If the current digit is smaller than the top of the stack, we pop elements from the stack
until either the stack is empty or the top of the stack is smaller than or equal to the current digit.
After processing all the digits, we remove any remaining digits from the stack to satisfy the required k digits to remove.
Finally, we construct the result by popping elements from the stack and reverse it to get the correct order.
*/


/*

INTUITION BRUTE FORCE :-

1. Consider an example test-case given as [1 4 3 2 2 1 9] and k = 3. In this case, we would have to figure out
   which all elements are to be removed, so that the result is smallest / minimum.

2. So let us take a stack and keep a track of elements inside it. Push the first element of the input string   
   inside the and subsequently check for the next smaller which can be added. If st.top() > curr_element, then 
   simply pop() out the top element, because that will contribute to a smaller element.

3. Finally store all the elements inside the stack, and reverse it to get the final answer.

Edge Cases:-

1. What if there are trailing zeros in the answer -> In this case, the trailing zeros are popped out from the 
   resultant string.

2. What if all the elements are zeros in the given element -> In this case, simply return 0.

3. 'K' is always expected to be within the range such that it is lesser than nums.length(). 

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;

class Solution
{
    public:
    string removeKElements(string nums, int k)
    {
        int n = nums.length();
        stack<int> st;
        vector<int> ans;
        string res = "";

        for(int i=0; i<n; ++i)
        {
            while(!st.empty() && k>0 && (nums[i] - '0') < (st.top() - '0'))
            {
                st.pop();
                k--;
            }

            st.push(nums[i]);   // putting everything in the stack
        }

        while(k>0) st.pop(); k--;

        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        while(res.length() != 0 && res.back() == '0') // not to consider trailing zeros
        {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        if(res.empty()) return "0";

        return res;
    }
};

int main()
{
    Solution sol;

    string arr;
    getline(cin, arr);

    int k;
    cin>>k;

    string result = sol.removeKElements(arr, k);

    cout<<result;

    return 0;
}

/*
Complexity Analysis:
- The code iterates through each digit in the input string, so the time complexity is O(n),
  where n is the length of the input string.
- The space complexity is O(n) as well since the stack can potentially store all the digits in the input string.
*/
