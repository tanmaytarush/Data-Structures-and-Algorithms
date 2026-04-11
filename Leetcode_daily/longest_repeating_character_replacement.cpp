/*
Leetcode Link -> https://leetcode.com/problems/longest-repeating-character-replacement/description/

424. Longest Repeating Character Replacement
Medium
Topics
premium lock icon
Companies
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

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
    int longestRepeatingBF(string s, int k) // O(N2)
    {
        int maxLen = 0;
        for(int i=0; i<s.length(); ++i)
        {
            vector<int> freq(26, 0);
            
            int maxFreq = 0;

            for(int j=i; j<s.length(); ++j)
            {
                freq[s[j]-'A']++;

                int maxSize = (j - i + 1);

                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                int replacable = maxSize - maxFreq;

                if(replacable <= k)
                {
                    maxLen = max(maxLen, maxSize);
                }
            }
        }
        return maxLen;
    }

    int longestRepeatingBetter(string s, int k) // Somewhat O(N2)
    {
        int l=0;
        int maxLength = 0;
        int r=0;

        int maxFreq = 0;
        vector<int> freq(26, 0);

        while(r < s.length())
        {
            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while((r-l+1) - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }

    int longestRepeatingOptimal(string s, int k)  // O(N)
    {
        int l=0;
        int maxLength = 0;
        int r=0;

        int maxFreq = 0;
        vector<int> freq(26, 0);

        while(r < s.length())
        {
            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            if((r-l+1) - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            if((r-l+1) - maxFreq <= k)
            {
                maxLength = max(maxLength, r-l+1);
            }

            r++;
        }
        return maxLength;
    }
};

int main()
{
    string s;
    getline(cin, s);

    int k;
    cin>>k;

    Solution sol;

    int result1 = sol.longestRepeatingBF(s, k);
    int result2 = sol.longestRepeatingBetter(s, k);
    int result3 = sol.longestRepeatingOptimal(s, k);

    cout<<result1<<endl;
    cout<<result2<<endl;
    cout<<result3<<endl;

    return 0;
}