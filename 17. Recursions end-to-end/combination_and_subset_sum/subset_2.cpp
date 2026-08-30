/*

90. Subsets II
Medium
Topics
premium lock icon
Companies
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

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
    void subsets(int index, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds)
    {
        ans.push_back(ds);

        for(int i=index; i<arr.size(); i++)
        {
            if(i!=index && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            subsets(i+1, arr, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsSet(vector<int>&arr)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        subsets(0, arr, ans, ds);
        return ans;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    vector<vector<int>> result = sol.subsetsSet(arr);

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