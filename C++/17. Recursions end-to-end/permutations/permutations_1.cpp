/*

Print all permutations of a string / array [Approach - I]

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
    void recurPermutation(vector<int>&ds, vector<int>&nums, vector<vector<int>>&ans, vector<int>&freq)
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
                recurPermutation(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permutations(vector<int>&nums)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> freq(nums.size());
        for(int i=0; i<nums.size(); i++) freq[i] = 0;
        recurPermutation(ds, nums, ans, freq);
        return ans;
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

    cout<<endl;

    vector<vector<int>> ans = sol.permutations(nums);

    for(vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}