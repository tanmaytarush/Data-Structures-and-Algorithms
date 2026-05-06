/*
Question:
Given a string s, find the length of the longest substring without repeating characters.

Approach:
- We can use a sliding window approach to solve this problem.
- We maintain a window that contains only unique characters.
- We use a hash map to store the frequency of characters in the current window.
- We iterate through the string and expand the window by adding one character at a time.
- If we encounter a repeating character, we shrink the window from the left until the character is no longer in the window.
- We keep track of the maximum window size encountered so far and return it as the result.

Example:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


INTUITION BRUTE FORCE:-

1.  Consider a scenario in which I need to generate all the substrings and within that substring
    trace out the maximum length of all the possible substrings with unique characters.

2.  I would take two different loops to iterate over i and j, and while generating all substrings,
    I would keep a track of elements as in where the actual window lies.

3.  The outer loop takes into consideration the left side pointer of the windows, and j takes care 
    of the right end of the window. If j is present in the hashSet then break. Calculate the 
    window length and finally calculate the maxLength. 

4.  Finally, the current hashSet[j] is set to 1.

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
    int longestSSWR_BF(string s)
    {
        int n = s.size();
        int maxLength = 0;
        int hashSet[256] = {0};

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(hashSet[s[j]] == 1)  // already used
                {
                    break;
                }

                int length = j-i+1;
                maxLength = max(maxLength, length);

                hashSet[s[j]] = 1;
            }
        }
        return maxLength;
    }  
    
    
    int longestSSWR_Opt(string s)
    {
        int n = s.size();
        int l = 0;
        int r = 0;

        int maxLength = 0;

        int hashSet[256] = {-1};

        while(r<n)
        {
            if(hashSet[s[r]] != -1) // already being passed and used
            {
                if(hashSet[s[r]] >= l) // and the index is greater than current l, then move l
                {
                    l = hashSet[s[r]] + 1;
                }
            }
            int length = r-l+1;
            maxLength = max(length, maxLength);
            hashSet[s[r]] = r;
            r++;
        }
        return maxLength;
    }
};


int main()
{
    Solution sol;

    string s;
    getline(cin, s);

    int result_bf = sol.longestSSWR_BF(s);
    cout<<result_bf<<endl;

    int result_opt = sol.longestSSWR_Opt(s);
    cout<<result_opt<<endl;

    return 0;
}



// Complexity Analysis:
// - The time complexity of this algorithm is O(N), where N is the length of the input string `s`. We iterate through each character of the string once.
// - The space complexity is O(M), where M is the number of unique characters in the string `s`. The unordered map `mp` can store up to M key-value pairs.
