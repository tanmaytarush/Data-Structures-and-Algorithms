/*Given an array of integers nums and an integer k, a continuous subarray is called nice if there are k odd numbers in it. Return the number of nice subarrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3 ; Binary array = [1, 1, 0, 1, 1]
Output: 2
Explanation: The only subarrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

APPROACH:
1. Define a helper function called atMostK, which calculates the number of subarrays with at most k odd numbers.
2. Initialize variables start to 0, oddCnt to 0, and ans to 0.
3. Iterate through each element nums[i] in the array:
   - If nums[i] is odd, increment oddCnt by 1.
   - While oddCnt is greater than k, move the start pointer and decrement oddCnt if the element at nums[start] is odd. This ensures that we maintain at most k odd numbers in the subarray.
   - Add the count of subarrays from start to i (i - start + 1) to ans.
4. Return ans, which represents the number of subarrays with at most k odd numbers.
5. In the numberOfSubarrays function, return the difference between atMostK(nums, k) and atMostK(nums, k - 1) to get the number of nice subarrays.

DIRECT TWO POINTERS AND SLIDING WINDOW WORKS FOR KEYWORDS LIKE ATMOST, ETC. TO FIND THE EXACT
SUMMATION SUBARRAYS, THIS APPROACH IS THE STANDARD.

CODE:*/

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
    int niceSubarrays(vector<int>&nums, int k) // return count(=k) - count(<=k)
    {
        return maxSubarrays(nums, k) - maxSubarrays(nums, k-1);
    }

    int maxSubarrays(vector<int>&nums, int k) // sum <= k
    {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int sum = 0;
        int count = 0;

        while(end < n)
        {
            sum += nums[end]%2;

            while(start<=end && sum>k)
            {
                sum -= nums[start]%2;
                start++;
            }

            count += (end - start + 1);
            end++;
        }

        return count;
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

    int result = sol.niceSubarrays(nums, k);

    cout<<result;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(N), where N is the size of the input array nums. We traverse the array once in both the atMostK function and the numberOfSubarrays function.
- Space complexity: O(1), as we use constant extra space throughout the algorithm.
*/
