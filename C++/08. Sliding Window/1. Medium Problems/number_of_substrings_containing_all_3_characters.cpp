/*
QUESTION:

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int totalSubstrings(string s, int k)
    {
        int len = s.length();
        int l = 0;
        int r = 0;

        vector<int> freq(3,0);
        int total = 0;

        while(r < len)
        {
            char curr = s[r];
            freq[curr - 'a']++;

            while(hasAllChars(freq))
            {
                total += len - r;

                char left = s[l];
                freq[left - 'a']--;
                l++;
            }

            r++;
        }

        return total;
    }

    bool hasAllChars(vector<int>&freq)
    {
        return freq[0]>0 && freq[1]>0 && freq[2]>0;
    }
};

int main()
{
    Solution sol;
    
    string s;
    getline(cin, s);

    int k;
    cin>>k;

    int result = sol.totalSubstrings(s, k);

    cout<<result;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(n), where n is the length of the string s. We iterate over the string once.
- Space complexity: O(1), as the extra space used is constant throughout the algorithm.
*/
