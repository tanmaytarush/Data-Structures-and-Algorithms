/*

3739. Count Subarrays With Majority Element II
Leetcode -> https://leetcode.com/problems/count-subarrays-with-majority-element-ii/description/ 


You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

 

Example 1:

Input: nums = [1,2,2,3], target = 2

Output: 5

Explanation:

Valid subarrays with target = 2 as the majority element:

nums[1..1] = [2]
nums[2..2] = [2]
nums[1..2] = [2,2]
nums[0..2] = [1,2,2]
nums[1..3] = [2,2,3]
So there are 5 such subarrays.

Example 2:

Input: nums = [1,1,1,1], target = 1

Output: 10

Explanation:

​​​​​​​All 10 subarrays have 1 as the majority element.

Example 3:

Input: nums = [1,2,3], target = 4

Output: 0

Explanation:

target = 4 does not appear in nums at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.

 

Constraints:

1 <= nums.length <= 10​​​​​​​5
1 <= nums[i] <= 10​​​​​​​9
1 <= target <= 109

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
    // Recursive brute force:
    // Try every starting point and recursively extend the subarray.
    // This is only for learning / tiny inputs. It is O(N^2) and not suitable
    // for the actual LeetCode constraints.
    long long countMajorityRecursive(vector<int>& nums, int target)
    {
        int n = nums.size();
        return countFromStart(0, 0, nums, target, n);
    }

    // Optimal solution:
    // Convert target to +1 and all other values to -1.
    // A subarray has target as majority iff its transformed sum is > 0.
    long long countMajorityOptimal(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<int> pre(n * 2 + 1, 0);
        pre[n] = 1;

        int cnt = n;
        long long ans = 0;
        long long presum = 0;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == target)
            {
                presum += pre[cnt];
                ++cnt;
                ++pre[cnt];
            }
            else
            {
                --cnt;
                presum -= pre[cnt];
                ++pre[cnt];
            }

            ans += presum;
        }

        return ans;
    }

    private:
    long long countFromStart(int start, int end, vector<int>& nums, int target, int n)
    {
        if (start == n) return 0;
        if (end == n) return countFromStart(start + 1, start + 1, nums, target, n);

        int balance = 0;
        return countEndingFrom(start, end, balance, nums, target, n) +
               countFromStart(start + 1, start + 1, nums, target, n);
    }

    long long countEndingFrom(int start, int end, int balance, vector<int>& nums, int target, int n)
    {
        if (end == n) return 0;

        balance += (nums[end] == target) ? 1 : -1;

        return (balance > 0 ? 1LL : 0LL) +
               countEndingFrom(start, end + 1, balance, nums, target, n);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    if (n <= 25)
    {
        cout << "Recursive: " << sol.countMajorityRecursive(nums, target) << '\n';
    }
    else
    {
        cout << "Recursive: skipped for large input\n";
    }

    cout << "Optimal: " << sol.countMajorityOptimal(nums, target) << '\n';

    return 0;
}
