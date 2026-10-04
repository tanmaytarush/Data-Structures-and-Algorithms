/*QUESTION:
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to the goal.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

OPTIMAL INTUITION :
1. Create an unordered_map mp to store the prefix sum and its frequency.
2. Initialize a variable prefSum to keep track of the prefix sum.
3. Initialize a variable cnt to keep track of the count of subarrays with a sum equal to the goal.
4. Iterate through each element nums[i] in the array:
   - Update prefSum by adding nums[i].
   - Check if prefSum is equal to the goal, if so, increment cnt.
   - Check if the difference between prefSum and goal (prefSum - goal) exists in the map.
     - If it exists, increment cnt by the frequency of (prefSum - goal) in the map, as this would mean we have found subarrays with a sum equal to the goal.
   - Increment the frequency of prefSum in the map.
5. Return cnt, which represents the number of non-empty subarrays with a sum equal to the goal.

OPTIMAL INTUITION 2 :- TWO POINTER AND SLIDING WINDOW

1. Consider an array as [1 0 1 0 1] and goal = 2. In this case, we will using the concept
   of prefixSums to find out those subarrays where value is (currentSum - goal).
2. At index 1, the sum is 1, so keep both start and end at index = 0. Then, later use the
   right to move by one step because the currentSum < goal. 
3. Now in this scenario where we need to find all the related subarrays with the given sum,
   we need to consider the complete permutation of window from start to end because we are
   considering all conditions where sum<=goal. That's why in count we are adding 
   (end - start + 1).
4. Finally, we will recursively call the substraction of func(nums, goal) - func(nums, goal-1),
   to find out the subarrays with exact sums.

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
    int numSubarraysWithSum_PS(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int currentSum = 0;
        int count = 0;
        unordered_map<int, int> freq; // currentSum, frequency

        for(int i=0; i<n; ++i)
        {   
            currentSum += nums[i];
            if(currentSum == goal)
            {
                count++;
            }

            if(freq.find(currentSum - goal) != freq.end())
            {
                count += freq[currentSum - goal]; // added 2 for currentSum-goal = 1.
            }

            freq[currentSum]++;
        }

        return count;
    }

    int numSubarraysWithSum_TP(vector<int>&nums, int goal)
    {
        return maxWindowCount(nums, goal) - maxWindowCount(nums, goal-1);
    }

    int maxWindowCount(vector<int>&nums, int goal)
    {
        int n = nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int count=0;

        while(r < n)
        {
            sum += nums[r];

            while(l<=r && sum>goal)
            {
                sum -= nums[l];
                l++;
            }

            count += (r-l+1);
            r++;
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

    int goal;
    cin>>goal;

    int resultPS = sol.numSubarraysWithSum_PS(nums, goal);
    int resultTP = sol.numSubarraysWithSum_TP(nums, goal);

    cout<<resultPS<<endl;
    cout<<resultTP<<endl;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(N), where N is the size of the input array nums. We traverse the array once and perform constant time operations in the loop.
- Space complexity: O(N), as the worst-case scenario would be that all prefix sums are distinct, so the map mp would store N prefix sums.
    - we can reduce the space complexity to O(1) if we use this countOfSubarrays with atmost sum = k - atmost sum = k-1 
    - which will return in countofSubarrays with sum exactly K, but this won't work if array has -ve elements
*/
