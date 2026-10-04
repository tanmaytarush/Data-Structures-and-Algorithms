/*

Kth Permutation. 

For all permutations of an input array. Curate all permutations and return the kth one.

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
    vector<int> kthPermutation(vector<int>&nums, int k)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size());
        for(int i=0; i<nums.size(); i++)
        {
            freq[i] = 0;
        }
        solve(0, nums, k, ds, freq, ans);
        return ans[k-1];
    }

    void solve(int index, vector<int>&nums, int k, vector<int>&ds, vector<int>&freq, vector<vector<int>>&ans)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(!freq[i])
            {
                freq[i] = 1;
                ds.push_back(nums[i]);
                solve(i+1, nums, k, ds, freq, ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
};

int main()
{
    Solution sol;
    
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    int k;
    cin>>k;

    vector<int> result = sol.kthPermutation(nums, k);

    for(vector<int>::iterator it=result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}