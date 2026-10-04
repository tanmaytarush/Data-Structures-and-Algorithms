/*
Expression Add Operators :-

Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
Note that operands in the returned expressions should not contain leading zeros.
Note that a number can contain multiple digits.

Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
Example 3:

Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.

Constraints:

1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    void solve(int index, string num, int target, long value, long prev, string path, vector<string>&ans)
    {
        if(index == num.size())
        {
            if(value == target) ans.push_back(path);
            return;    
        }

        long curr = 0;
        for(int i=index; i<num.size(); ++i)
        {
            if(i>index && num[index]=='0') // if number '00123' we stop exploring further numbers if 0 exists
            {
                break;
            }
            
            curr = curr*10 + (num[i] - '0');
            LOG(curr); // curr value changes based on index and i pointers
            if(index == 0)
            {
                solve(i+1, num, target, curr, curr, to_string(curr), ans);
            }

            else
            {
                // addition operation
                solve(i+1, num, target, value + curr, curr, path+"+"+to_string(curr), ans);

                // substraction operation
                solve(i+1, num, target, value - curr, -curr, path+"-"+to_string(curr), ans);

                // multiplication operation
                solve(i+1, num, target, value-prev + prev*curr, prev*curr, path+"*"+to_string(curr), ans);
            }
        }
    }

    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        solve(0, num, target, 0, 0, "", ans);
        return ans;
    }
};



int main()
{
    Solution sol;

    string num;
    getline(cin, num);

    int target;
    cin>>target;

    vector<string> result = sol.addOperators(num, target);

    for(auto it : result)
    {
        cout<<it<<endl;
    }

    return 0;
}