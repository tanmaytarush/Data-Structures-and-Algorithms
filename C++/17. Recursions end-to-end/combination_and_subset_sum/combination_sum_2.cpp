/*

40. Combination Sum II
Medium
Topics
premium lock icon
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

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
    void combination(int index, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<arr.size(); i++)
        {
            if(i>index && arr[i] == arr[i-1]) continue;
            if(arr[i]>target) break;

            ds.push_back(arr[i]);
            combination(index+1, target-arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>&arr, int target)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combination(0, target, arr, ans, ds);
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

    int target;
    cin>>target;

    vector<vector<int>> result = sol.combinationSum(arr, target);

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