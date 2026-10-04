#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

bool first_subsequence_with_sum_k(int index, vector<int> &ds, vector<int> &arr, int s, int sum, int n)
{
    if(index == n)
    {
        if(sum == s)
        {
            for(auto it : ds)
            {
                cout<<it<<" ";
                return true;
            }
        }
        else return false;
    }

    ds.push_back(arr[index]);
    s += arr[index];

    if(first_subsequence_with_sum_k(index+1, ds, arr, s, sum, n) == true)
    {
        return true;
    }

    s -= arr[index];
    ds.pop_back();

    if(first_subsequence_with_sum_k(index+1, ds, arr, s, sum, n) == true)
    {
        return true;
    }

    return false;
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

    vector<int> ds;
    first_subsequence_with_sum_k(0, ds, arr, 0, sum, n);

    return 0;
}