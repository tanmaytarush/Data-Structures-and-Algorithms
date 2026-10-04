#include<iostream>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

void print_subsequences_with_sum_k(int index, vector<int> &ds, vector<int> &arr, int s, int sum, int n)
{
    if(index == n)
    {
        if(sum == s)
        {
            for(auto it : ds)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return; // very important to reduce segmentation fault
    }

    ds.push_back(arr[index]);
    s += arr[index];
    // pick operation
    print_subsequences_with_sum_k(index + 1, ds, arr, s, sum, n);

    s -= arr[index];
    ds.pop_back();
    // not-pick operation
    print_subsequences_with_sum_k(index + 1, ds, arr, s, sum, n);
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

    vector<int> ds;
    print_subsequences_with_sum_k(0, ds, arr, 0, 2, n);

    return 0;
}

