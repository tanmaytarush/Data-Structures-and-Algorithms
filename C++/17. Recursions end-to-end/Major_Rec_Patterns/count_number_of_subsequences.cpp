/*

Count number of subsequences :-

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
    int countSubsequences(int index, int n, vector<int>&arr, int k, int sum)
    {
        if(index == n)
        {
            if(sum == k) return 1;

            else return 0;
        }

        // pick
        sum += arr[index];
        int l = countSubsequences(index+1, n, arr, k, sum);

        // not-pick
        sum -= arr[index];
        int r = countSubsequences(index+1, n, arr, k, sum);

        return l+r;
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

    int result = sol.countSubsequences(0, n, arr, k, 0);

    cout<<result<<endl;

    return 0;
}