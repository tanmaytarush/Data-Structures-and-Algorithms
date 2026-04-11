/*

Leetcode 3740. Minimum Distance Between Three Equal Elements I
Medium

Link -> https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/

You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.
 

Example 1:

Input: nums = [1,2,1,1,3]

Output: 6

Explanation:

The minimum distance is achieved by the good tuple (0, 2, 3).

(0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.

Example 2:

Input: nums = [1,1,2,3,2,1,2]

Output: 8

Explanation:

The minimum distance is achieved by the good tuple (2, 4, 6).

(2, 4, 6) is a good tuple because nums[2] == nums[4] == nums[6] == 2. Its distance is abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8.

Example 3:

Input: nums = [1]

Output: -1

Explanation:

There are no good tuples. Therefore, the answer is -1.


Constraints:

1 <= n == nums.length <= 100
1 <= nums[i] <= n



APPROACH:

This problem is a simplified version of 3741. Minimum Distance Between Three Equal Elements II. Since the constraints are smaller, a brute force approach is feasible.

First, consider the formula for the sum of absolute differences. It can be observed that this value is equivalent to the sum of the three sides of a generalized triangle. Regardless of the order of the three selected indices, the total distance always simplifies to twice the length of the segment formed by the two endpoints. In other words, if the leftmost index is i and the rightmost index is k, then the required distance is 2×(k−i).

Therefore, we use three nested loops to enumerate all possible ordered triplets. If the elements at the selected indices in nums are equal, we compute the distance as described above and update the global minimum.

*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int minimumDistance(vector<int> &nums)
    {
        int n = nums.size();
        int ans = n+1;

        for(int i=0; i<n-2; ++i)
        {
            for(int j=i+1; j<n-1; ++j)
            {
                if(nums[i] != nums[j])
                {
                    continue;
                }
                for(int k=j+1; k<n; ++k)
                {
                    if(nums[j] == nums[k])
                    {
                        ans = min(ans, k-i);
                    }
                }
            }
        }
        return ans == n+1 ? -1 : ans*2;
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

    int result = sol.minimumDistance(nums);

    cout<<result<<endl;

    return 0;
}