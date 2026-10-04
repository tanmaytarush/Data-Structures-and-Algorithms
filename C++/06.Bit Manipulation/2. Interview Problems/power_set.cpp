/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]] 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<vector<int>> powerSubsets(vector<int> &nums)
{
    int n = nums.size();
    int subsets = (1<<n);
    vector<vector<int>> ans;

    for(int num=0; num<subsets; ++num)
    {
        vector<int> subsets;
        for(int i=0; i<n; ++i)
        {
            if(num & (1 << i))
            {
                subsets.push_back(nums[i]);
            }
        }
        ans.push_back(subsets);
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    vector<vector<int>> result = powerSubsets(arr);

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