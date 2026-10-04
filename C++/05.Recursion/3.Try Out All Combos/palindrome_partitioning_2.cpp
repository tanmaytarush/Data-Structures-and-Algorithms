/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase English letters only.
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(int i, int j, string s)
{
    while(i<j)
    {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(int i, int n, string &s)
{
    if(i==n) return 0;

    int minCost = INT_MAX;

    for(int j=i; j<n; ++j)
    {
        if(isPalindrome(i, j, s))
        {
            int cost = 1 + solve(j+1, n, s);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int palindromePartition(string str)
{
    int n = str.size();
    return solve(0, n, str) - 1;
}

int main()
{
    string str;
    getline(cin, str);

    int minCost = palindromePartition(str);

    cout<<minCost;

    return 0;
}