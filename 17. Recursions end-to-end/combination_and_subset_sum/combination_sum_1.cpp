/*

Combination Sum - 1

Problem Statement: 

Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Examples
 Example 1:
Input: array = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
             7 is a candidate, and 7 = 7.
             These are the only two combinations.


Example 2:
Input: array = [2], target = 1
Output: []
Explaination: No combination is possible.
            
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

class Solution
{
    public:
    void combinations(int index, int target, vector<int>&nums, vector<vector<int>>&ans, vector<int>&ds)
    {
        if(index == nums.size())
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        if(nums[index]<=target)
        {
            ds.push_back(nums[index]);
            // continue with the same element
            combinations(index, target-nums[index], nums, ans, ds);
            ds.pop_back();
        }

        combinations(index+1, target, nums, ans, ds);
    }

    vector<vector<int>> findCombinations(vector<int>&candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0, target, candidates, ans, ds);
        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    int target;
    cin>>target;

    vector<vector<int>> result = sol.findCombinations(nums, target);

    for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it)
    {
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}