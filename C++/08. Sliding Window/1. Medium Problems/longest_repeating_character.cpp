/*QUESTION:
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

OPTIMAL APPROACH :-
1. Create an unordered_set ltrs to store all unique letters in the given string s.
2. Initialize a variable ans to keep track of the maximum length of the substring.
3. Iterate through each letter ltr in the set ltrs:
   - Initialize variables start and ltrCnt to track the starting index of the current substring and the count of ltr in the substring.
   - Iterate through each character in the string s:
     - If the character is equal to ltr, increment ltrCnt.
     - Enter a while loop to adjust the start index until the number of characters in the substring that are different from ltr is more than k.
     - During the adjustment, if the character at the start index is equal to ltr, decrement ltrCnt.
     - Increment the start index.
     - If the length of the current substring minus ltrCnt is at most k, update ans by taking the maximum of ans and the length of the current substring.
4. Return the maximum length of the substring (ans).

BRUTE FORCE APPROACH :-

1. The minimal approach for this problem is to generate all the subarrays.
2. Now that we have all the subarrays with us, we maintain a hasharray so that we could find out 
   the maximum frequency of a character.
3. Since we have the maximum frequency character with us, so the moment out length of substring
   [l - (maxFreq) > k], we stop. This is because, we simply need to update the spots to create 
   the maximum window only when our window is within the allowed range of K.
4. Once, this part is achieved and our range is within the limit k, we calculate the max-window 
   length. This brings us to our solution.
5. Time complexity -> O(N2) and Space complexity -> O(26).

CODE:*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int longestSubstringBF(string s, int k)
    {
        int n = s.length();
        // int maxFreq = 0;
        int maxWindow = 0;
        // int hash[26] = {0};
        for(int i=0; i<n; ++i)
        {
            int hash[26] = {0};
            int maxFreq = 0;
            for(int j=i; j<n; ++j)
            {
                hash[s[j]-'A']++;
                maxFreq = max(maxFreq, hash[s[j]-'A']);

                int currWindow = (j-i+1) - maxFreq;

                if(currWindow <= k)
                {
                    maxWindow = max(maxWindow, j-i+1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxWindow;
    }

    int longestSubstringOptimal(string s, int k)
    {
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxWindow = 0;

        int hash[26] = {0};

        while(r < n)
        {
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq, hash[s[r]-'A']);  // no need to reupdate and reduce maxFreq, because it will
            // make sense only when the window goes beyond the current max-window.
            int currWindow = (r-l+1) - maxFreq;

            if(currWindow > k)
            {
                hash[s[l]-'A']--;
                l++;
            }

            if(currWindow <= k)
            {
                maxWindow = max(maxWindow, (r-l+1));
            }
            r++;
        }

        return maxWindow;
    }
};

int main()
{
    Solution sol;
    
    string s;
    getline(cin, s);

    int k;
    cin>>k;

    int result_bf = sol.longestSubstringBF(s, k);
    int result_opt = sol.longestSubstringOptimal(s, k);

    cout<<result_bf<<endl;
    cout<<result_opt<<endl;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(N * L), where N is the length of the string s and L is the number of unique letters in the string. We iterate through the string and perform the sliding window operation for each unique letter.
- L can have the max value of 26, so we can say the complexity would be O(N * 26) i.e O(N).
- Space complexity: O(L), as we store the unique letters in the set ltrs.
*/
