/*

Permutations of an array based on swapping without frequency array

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
    void recurPermutation(int index, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            recurPermutation(index+1, nums, ds, ans);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permutations(vector<int>&nums)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        recurPermutation(0, nums, ds, ans);
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

    vector<vector<int>> result = sol.permutations(nums);

    for(vector<vector<int>>::iterator it = result.begin(); it!=result.end(); ++it)
    {
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}