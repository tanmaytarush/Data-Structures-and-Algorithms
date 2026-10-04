/*

Palindrome Partitioning for all respective substring combinations for getting a palindrome
substring from a set of string S.

*/

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
    vector<vector<string>> palindromePartitioning(string str)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0, str, ds, ans);
        return ans;
    }

    void solve(int index, string str, vector<string>&ds, vector<vector<string>>&ans)
    {
        if(index == str.length())
        {
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<str.length(); ++i)
        {
            if(isPalindrome(str, index, i))
            {
                ds.push_back(str.substr(index, i-index+1));
                solve(i+1, str, ds, ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string str, int start, int end)
    {
        while(start <= end)
        {
            if(str[start++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;

    string str;
    getline(cin, str);

    vector<vector<string>> result = sol.palindromePartitioning(str);

    for(vector<vector<string>>::iterator it = result.begin(); it != result.end(); ++it)
    {
        for(vector<string>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}