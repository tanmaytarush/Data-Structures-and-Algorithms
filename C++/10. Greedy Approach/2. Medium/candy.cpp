/*
Question:
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second, and third child with 2, 1, 2 candies respectively.

Approach:
- We start by assigning 1 candy to each child as the minimum requirement.
- Then, we iterate from left to right and check if the current child has a higher rating than the previous child.
- If yes, we increment the number of candies for the current child by 1 compared to the previous child.
- Next, we iterate from right to left and check if the current child has a higher rating than the next child.
- If yes, we take the maximum of the current child's candies and the next child's candies plus 1.
- Finally, we sum up all the candies assigned to get the minimum number of candies required.

Complexity Analysis:
- The time complexity of this approach is O(N), where N is the number of children.
- We iterate over the ratings twice to assign the candies.
- The space complexity is O(N) as we use an additional vector to store the number of candies assigned to each child.

Code:
*/

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
    int totalCandies(vector<int>&nums)
    {
        int n = nums.size();
        int candies = n;
        int i=1;

        while(i<n)
        {
            if(nums[i] == nums[i-1])
            {
                i++;
                continue;
            }
            
            int peak = 0;
            while(i<n && nums[i]>nums[i-1])
            {
                peak++;
                candies += peak;
                i++;
            }
            
            int valley = 0;
            while(i<n && nums[i]<nums[i-1])
            {
                valley++;
                candies += valley;
                i++;
            }

            candies -= min(peak, valley);
        }
        return candies;
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

    int candies = sol.totalCandies(nums);

    cout<<candies<<endl;

    return 0;
}
