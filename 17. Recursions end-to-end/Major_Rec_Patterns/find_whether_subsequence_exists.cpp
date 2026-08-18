/*

Find whether a subsequence with sum k exists or not

*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    bool findExistence(int index, int n, vector<int>&arr, vector<int>&ds, int k, int sum)
    {
        if(index == n)
        {
            if(sum == k)
            {
                for(auto it : ds)
                {
                    cout<<it<<" ";
                }
                cout<<endl;
                return true;
            }
            return false;
        }

        // pick
        ds.push_back(arr[index]);
        sum += arr[index];
        if(findExistence(index+1, n, arr, ds, k, sum) == true)
        {
            return true;
        }

        // not-pick
        sum -= arr[index];
        ds.pop_back();
        if(findExistence(index+1, n, arr, ds, k, sum) == true)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    vector<int> ds;

    sol.findExistence(0, n, arr, ds, k, 0);

    return 0;
}