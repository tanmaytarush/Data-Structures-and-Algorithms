/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while(start<=end)
    {
        if(s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

void func(int index, string s, vector<string> &path, vector<vector<string>> &ans)
{
    if(index == s.size())
    {
        ans.push_back(path);
        return;
    }

    for(int i=index; i<s.size(); ++i)
    {
        if(isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            func(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> path;
    func(0, s, path, ans);
    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    auto ans = partition(s);

    for(auto &vec : ans)
    {
        for(auto &str : vec)
        {
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}