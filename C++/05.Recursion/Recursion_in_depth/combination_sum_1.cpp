#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

void findCombinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) 
{
    if(index == arr.size())
    {
        if(target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if(arr[index] <= target)
    {
        ds.push_back(arr[index]);
        findCombinations(index, target - arr[index], arr, ans, ds);
        ds.pop_back();
    }

    findCombinations(index + 1, target, arr, ans, ds);
}

vector<vector<int>> combination_sum(vector<int> &candidates, int target)
{
    int n = candidates.size();
    vector<vector<int>> ans;
    vector<int> ds;

    findCombinations(0, target, candidates, ans, ds);
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

    int target;
    cin>>target;

    vector<vector<int>> ans = combination_sum(arr, target);

    for(vector<vector<int>>:: iterator it = ans.begin(); it != ans.end(); ++it)
    {
        for(vector<int> :: iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}