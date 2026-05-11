/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return numSubarrays(nums, k) - numSubarrays(nums, k-1);
    }

    int numSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l=0;
        int r=0;
        unordered_map<int, int> mpp;
        int total = 0;

        while(r < n)
        {
            mpp[nums[r]]++;

            while(mpp.size() > k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }

            if(mpp.size() <= k)
            {
                total += r-l+1;
            }

            r++;
        }

        return total;
    }
};


int main()
{
    Solution sol;
    
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums[i];
    }

    int k;
    cin>>k;

    int result = sol.subarraysWithKDistinct(nums, k);

    cout<<result<<endl;

    return 0;
}
