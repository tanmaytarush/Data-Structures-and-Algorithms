/*

Reverse an array using Recursion

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
    vector<int> reverseArray(int l, int r, vector<int>&arr)
    {
        if(l >= r)
        {
            return arr;
        }

        swap(arr[l], arr[r]);

        return reverseArray(l+1, r-1, arr);
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

    vector<int> ans = sol.reverseArray(0, n-1, arr);

    for(vector<int>::iterator it = ans.begin(); it!=ans.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}