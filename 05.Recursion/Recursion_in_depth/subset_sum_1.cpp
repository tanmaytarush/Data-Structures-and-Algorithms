#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

void subsetSums(int index, int sum, vector<int> &arr, vector<int> &ds)
{
    if(index == arr.size())
    {
        ds.push_back(sum);
        return;
    }

    // pick the element
    subsetSums(index + 1, sum + arr[index], arr, ds);

    // not pick the element
    subsetSums(index + 1, sum, arr, ds);
}

vector<int> Result(vector<int> &arr, int n)
{
    vector<int> ds;
    subsetSums(0, 0, arr, ds);
    sort(ds.begin(), ds.end());
    return ds;
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

    vector<int> result = Result(arr, n);
    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
} 