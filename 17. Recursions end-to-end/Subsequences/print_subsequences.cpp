/*

Print all Subsequences :-

A subsequence is a contiguous or a non-contiguous sequence which follows the order,
start to end ion an array whether skipping but in specific order.

Can be done using Power Set.
But here, we will follow take/not-take algorithm.

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
    void subsequences(int index, vector<int>&ds, vector<int>&arr, int n)
    {
        if(index >= n)
        {
            if(ds.size() == 0) cout<<"[]";
            for(auto it : ds)
            {
                cout<<it<<" ";
            }
            cout<<endl;

            return;
        }

        // add and pick an element
        ds.push_back(arr[index]);
        subsequences(index+1, ds, arr, n);
        ds.pop_back();
        subsequences(index+1, ds, arr, n);
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    vector<int> ds;

    sol.subsequences(0, ds, arr, n);

    return 0;
}


// Time Complexity -> O(2**N) * O(N)
// Space Complexity -> O(2**N) or O(1) if not considering the resultant array of answer