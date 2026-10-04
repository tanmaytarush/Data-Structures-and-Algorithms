/*

Print Subsequences with sum k

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
    vector<vector<int>> subsequenceWithSumK(int index, int n, vector<int>&nums, vector<vector<int>>&ans, vector<int>&ds, int k, int sum)
    {
        if(index == n)
        {
            if(sum == k)
            {
                ans.push_back(ds);
            }
            return ans;
        }

        // add and pick
        ds.push_back(nums[index]);
        sum += nums[index];
        subsequenceWithSumK(index+1, n, nums, ans, ds, k, sum);

        // not-pick
        sum -= nums[index];
        ds.pop_back();
        subsequenceWithSumK(index+1, n, nums, ans, ds, k, sum);

        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    vector<int> ds;
    vector<vector<int>> ans;

    vector<vector<int>> result = sol.subsequenceWithSumK(0, n, nums, ans, ds, k, 0);

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