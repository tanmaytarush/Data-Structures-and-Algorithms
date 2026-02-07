#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;

void prepare_subsequences(int index, vector<int> &ds, vector<int> &arr, int n)
{
    if(index == n)
    {
        for(auto it : ds)
        {
            cout<<it<<" ";
        }
        if(ds.size() == 0)
        {
            cout<<"{}";
        }
        cout<<endl;
        return;
    }


    ds.push_back(arr[index]);  
    prepare_subsequences(index+1, ds, arr, n); // take operation
    ds.pop_back();
    prepare_subsequences(index+1, ds, arr, n); // not take operation
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
    prepare_subsequences(0, ds, arr, n);
}