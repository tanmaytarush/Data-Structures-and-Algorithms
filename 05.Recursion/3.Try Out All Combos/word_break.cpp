/**
 * QUESTION: Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
 * 
 * Example:
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 *
 * Approach:
 * We can solve this problem using a recursive approach with backtracking.
 * 1. Start from the beginning of the string and try to find a word from the dictionary that matches a substring starting at the current index.
 * 2. If we find a match, recursively call the function on the remaining substring.
 * 3. Repeat this process until we reach the end of the string.
 * 4. If we can successfully break the string into words, we return true. Otherwise, we return false.
 *
 * Time Complexity: O(2^N), where N is the length of the string. In the worst case, we can have 2^N recursive calls.
 * Space Complexity: O(N), where N is the length of the string. The recursion stack can go up to N in the worst case.
 */

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool solve(int index, string str, int n, unordered_set<string>&dict)
{
    if(index == n)
    {
        return true;
    }

    for(int i=index; i<n; ++i)
    {
        string s = str.substr(index, i-index+1);
        if(dict.find(s) != dict.end())
        {
            if(solve(i+1, str, n, dict))
            {
                return true;
            }
        }
    }
    return false;
}

bool wordBreak(string str, vector<string>&wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = str.length();
    bool result = solve(0, str, n, dict);
    return result;
}

int main()
{
    string str;
    getline(cin, str);

    int n;
    cin>>n;

    vector<string> words(n);
    for(int i=0; i<n; ++i)
    {
        cin>>words[i];
    }

    bool res = wordBreak(str, words);

    cout<<res<<endl;

    return 0;
}
