#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;

void combinationSum(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if(target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for(int i=index; i<arr.size(); ++i)
    {
        if(i>index && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;

        ds.push_back(arr[i]);
        combinationSum(i+1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> Result(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    combinationSum(0, target, candidates, ans, ds);
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

    int sum;
    cin>>sum;

    vector<vector<int>> result = Result(arr, sum);

    for(vector<vector<int>>:: iterator it = result.begin(); it != result.end(); ++it)
    {
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}