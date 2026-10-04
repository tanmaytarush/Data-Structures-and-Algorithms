#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

void permutation(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i = index; i<nums.size(); ++i)
    {
        swap(nums[i], nums[index]);
        permutation(index + 1, nums, ans);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permutationLists(vector<int> &nums)
{
    vector<vector<int>> ans;
    permutation(0, nums, ans);

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

    vector<vector<int>> result = permutationLists(arr);
    
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