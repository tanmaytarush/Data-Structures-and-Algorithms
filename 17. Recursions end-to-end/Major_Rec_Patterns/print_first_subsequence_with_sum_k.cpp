/*

Check whether a subsequence with sum k exists or not

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
    vector<int> printFirstSubsequence(int index, int n, vector<int>&arr, vector<int>&ds, int k, int sum)
    {
        if(index == n)
        {
            if(sum == k)
            {
                return ds;
            }
            return {};
        }
        
        // pick process
        ds.push_back(arr[index]);
        sum += arr[index];
        vector<int> left = printFirstSubsequence(index+1, n, arr, ds, k, sum);
        if(!left.empty()) return left;

        // not pick process
        sum -= arr[index];
        ds.pop_back();
        vector<int> right = printFirstSubsequence(index+1, n, arr, ds, k, sum);
        if(!right.empty()) return right;

        return {};
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

    //vector<int> ans;
    vector<int> ds;

    vector<int> result = sol.printFirstSubsequence(0, n, arr, ds, k, 0);

    for(vector<int>::iterator it=result.begin(); it!=result.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}