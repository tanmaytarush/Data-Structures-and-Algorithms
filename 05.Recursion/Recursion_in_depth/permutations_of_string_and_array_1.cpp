#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

void permutation_operation(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[])
{
    if(ds.size() == arr.size())
    {
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < arr.size(); ++i)
    {
        if(!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i] = 1;
            permutation_operation(ds, arr, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permutation(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int n = arr.size();
    int* freq = new int[n];
    for(int i=0; i<arr.size(); ++i) freq[i] = 0;
    permutation_operation(ds, arr, ans, freq);
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

    vector<vector<int>> result = permutation(arr);

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