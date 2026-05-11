/*
QUESTION:
Given an integer array 'nums' and an integer 'k', find the number of good subarrays of 'nums'.

A good array is an array where the number of different integers in that array is exactly 'k'.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

EXAMPLE:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

APPROACH:
We can solve this problem using a sliding window approach.

1. Create a function, kDistinctIntegers, that takes 'k' and the input vector 's' as parameters.
   - Initialize an unordered_map, mp, to store the frequency of elements.
   - Initialize 'start' to 0 and 'ans' to 0.
   - Iterate over the vector from left to right:
     - Increment the frequency of the current element in the map.
     - If the number of distinct elements in the map exceeds 'k', move the 'start' pointer to the right and remove elements from the map until the number of distinct elements becomes equal to 'k'.
     - Update 'ans' by adding the number of subarrays that can be formed with exactly 'k' distinct integers, which is equal to (i - start + 1).
   - Return 'ans', which represents the total number of good subarrays.

2. Create a function, subarraysWithKDistinct, that takes 'nums' and 'k' as parameters.
   - Return the difference between the number of good subarrays with 'k' distinct integers and the number of good subarrays with 'k-1' distinct integers, which can be calculated using the kDistinctIntegers function.

COMPLEXITY ANALYSIS:
- Time complexity: O(n), where n is the length of the input vector 'nums'. We iterate over the vector once using the sliding window approach.
- Space complexity: O(k), as the space used by the unordered_map is proportional to the number of distinct elements, which can be at most 'k'.
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int maxLenSubstringBF(string s, int k)
    {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> mpp;

        for(int i=0; i<n; ++i)
        {
            mpp.clear();
            for(int j=i; j<n; ++j)
            {
                mpp[s[j]]++;

                if(mpp.size() <= k) // atmost k elements
                {
                    maxLength = max(maxLength, j-i+1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxLength;
    }

    int maxLenOptimal(string s, int k)
    {
        int l=0;
        int r=0;
        int n = s.length();
        unordered_map<char, int> mpp;
        int maxLength = 0;

        while(r < n)
        {
            mpp[s[r]]++;

            if(mpp.size() > k)
            {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(mpp[s[l]]);
                l++;
            }

            if(mpp.size() <= k)
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
    Solution sol;

    string s;
    getline(cin, s);

    int k;
    cin>>k;

    int result_bf = sol.maxLenSubstringBF(s, k);
    int result_opt = sol.maxLenOptimal(s, k);

    cout<<result_bf<<endl;
    cout<<result_opt<<endl;

    return 0;
}
